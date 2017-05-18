#include "Globals.h"
#include "ChatHandler.hpp"

std::string ChatHandler::escapeMessageHtml(std::string content)
{
	boost::replace_all(content, "&", "&amp;");
	boost::replace_all(content, "<", "&lt;");
	boost::replace_all(content, ">", "&gt;");
	boost::replace_all(content, "\"", "&quot;");
	boost::replace_all(content, "'", "&#039;");
	return content;
}

void ChatHandler::ChatClientPrivateMessageHandler(BinaryReader &reader, WorldClient &client)
{
	ChatClientPrivateMessage message;
	message.deserialize(reader);

	message.receiver = message.receiver.substr(0, message.receiver.size() - 1);
	if (message.content.length() > 256)
		return;
	if ((int)client.character->getAccountRecord().get("level") < AccountRole::ANIMATOR)
		message.content = ChatHandler::escapeMessageHtml(message.content);
	std::string characterName = client.character->getCharacterRecord().get("Name");
	if (message.receiver == characterName)
	{
		client.character->replyText("Le message n'a pas été envoyé : vous vous parlez à vous-même...");
		return;
	}
	WorldClient *target = client.getWorld()->getClient(message.receiver);
	if (target != NULL)
	{
		client.sendMessage(ChatServerCopyMessage(ChatActivableChannelsEnum::PSEUDO_CHANNEL_PRIVATE, message.content, Utils::getUnixTimestamp(), target->character->getCharacterRecord().get("Name"), 
			target->character->getCharacterRecord().get("Id"), target->character->getCharacterRecord().get("Name")));
		target->sendMessage(ChatServerMessage(ChatActivableChannelsEnum::PSEUDO_CHANNEL_PRIVATE, message.content, Utils::getUnixTimestamp(), target->character->getCharacterRecord().get("Name"),
			client.character->getCharacterRecord().get("Id"), client.character->getCharacterRecord().get("Name"), client.character->getAccountRecord().get("id")));
	}
	else
		client.character->replyText("Le message n'a pas pu être envoyé : le destinataire est introuvable.");
}

void ChatHandler::ChatClientMultiMessageHandler(BinaryReader &reader, WorldClient &client)
{
	ChatClientMultiMessage message;
	message.deserialize(reader);

	if (message.content.length() > 256)
		return;
	if ((int) client.character->getAccountRecord().get("level") < AccountRole::ANIMATOR)
		message.content = ChatHandler::escapeMessageHtml(message.content);
	switch (message.channel)
	{
		case ChatActivableChannelsEnum::CHANNEL_GLOBAL:
			client.character->getMap()->sendMap(ChatServerMessage(message.channel, message.content, Utils::getUnixTimestamp(), client.character->getCharacterRecord().get("Name"),
				client.character->getCharacterRecord().get("Id"), client.character->getCharacterRecord().get("Name"), client.character->getAccountRecord().get("id")));
		break;

		case ChatActivableChannelsEnum::CHANNEL_SEEK:
			client.getWorld()->sendToAllOnlineClients(ChatServerMessage(message.channel, message.content, Utils::getUnixTimestamp(), client.character->getCharacterRecord().get("Name"),
				client.character->getCharacterRecord().get("Id"), client.character->getCharacterRecord().get("Name"), client.character->getAccountRecord().get("id")));
		break;

		case ChatActivableChannelsEnum::CHANNEL_SALES:
			client.getWorld()->sendToAllOnlineClients(ChatServerMessage(message.channel, message.content, Utils::getUnixTimestamp(), client.character->getCharacterRecord().get("Name"),
				client.character->getCharacterRecord().get("Id"), client.character->getCharacterRecord().get("Name"), client.character->getAccountRecord().get("id")));
		break;
	}
}