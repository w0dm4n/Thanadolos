#include "Globals.h"
#include "Processor.hpp"
#include "imessage.h"
#include "BinaryReader.hpp"
#include "ApproachHandler.hpp"
#include "GameHandler.hpp"
#include "ChatHandler.hpp"
#include "AdminHandler.hpp"

#include "AuthenticationTicketMessage.hpp"
#include "CharactersListRequestMessage.hpp"
#include "ReloginTokenRequestMessage.hpp"
#include "CharacterNameSuggestionRequestMessage.hpp"
#include "CharacterCreationRequestMessage.hpp"
#include "CharacterDeletionRequestMessage.hpp"
#include "CharacterSelectionMessage.hpp"
#include "GameContextCreateRequestMessage.hpp"
#include "MapInformationsRequestMessage.hpp"
#include "GameMapMovementRequestMessage.hpp"
#include "ChangeMapMessage.hpp"
#include "StatsUpgradeRequestMessage.hpp"
#include "ChatClientMultiMessage.hpp"
#include "ChatClientPrivateMessage.hpp"
#include "SpellModifyRequestMessage.hpp"
#include "ShortcutBarAddRequestMessage.hpp"
#include "ShortcutBarRemoveRequestMessage.hpp"
#include "ShortcutBarSwapRequestMessage.hpp"
#include "AdminCommandMessage.hpp"

bool Processor::processPacket(Packet &packet, WorldClient &client)
{
	BinaryReader reader(packet.data());
	std::list<Handler*> handlers;

	/*
	**	Approach Handler
	*/

	handlers.push_back(new Handler(AuthenticationTicketMessage::id, &ApproachHandler::AuthenticationTicketMessageHandler, "AuthenticationTicketMessage"));
	handlers.push_back(new Handler(CharactersListRequestMessage::id, &ApproachHandler::CharactersListRequestMessageHandler, "CharactersListRequestMessage"));
	handlers.push_back(new Handler(ReloginTokenRequestMessage::id, &ApproachHandler::ReloginTokenRequestMessageHandler, "ReloginTokenRequestMessage"));
	handlers.push_back(new Handler(CharacterNameSuggestionRequestMessage::id, &ApproachHandler::CharacterNameSuggestionRequestMessageHandler, "CharacterNameSuggestionRequestMessage"));
	handlers.push_back(new Handler(CharacterCreationRequestMessage::id, &ApproachHandler::CharacterCreationRequestMessageHandler, "CharacterCreationRequestMessage"));
	handlers.push_back(new Handler(CharacterDeletionRequestMessage::id, &ApproachHandler::CharacterDeletionRequestMessageHandler, "CharacterDeletionRequestMessage"));
	handlers.push_back(new Handler(CharacterSelectionMessage::id, &ApproachHandler::CharacterSelectionMessageHandler, "CharacterSelectionMessage"));

	/*
	**	Game Handler
	*/

	handlers.push_back(new Handler(GameContextCreateRequestMessage::id, &GameHandler::GameContextCreateRequestMessageHandler, "GameContextCreateRequestMessage"));
	handlers.push_back(new Handler(MapInformationsRequestMessage::id, &GameHandler::MapComplementaryInformationsDataMessageHandler, "MapComplementaryInformationsDataMessage"));
	handlers.push_back(new Handler(GameMapMovementRequestMessage::id, &GameHandler::GameMapMovementRequestMessageHandler, "GameMapMovementRequestMessage"));
	handlers.push_back(new Handler(ChangeMapMessage::id, &GameHandler::ChangeMapMessageHandler, "ChangeMapMessageHandler"));
	handlers.push_back(new Handler(StatsUpgradeRequestMessage::id, &GameHandler::StatsUpgradeRequestMessageHandler, "StatsUpgradeRequestMessage"));
	handlers.push_back(new Handler(SpellModifyRequestMessage::id, &GameHandler::SpellModifyRequestMessageHandler, "SpellModifyRequestMessage"));
	handlers.push_back(new Handler(ShortcutBarAddRequestMessage::id, &GameHandler::ShortcutBarAddRequestMessageHandler, "ShortcutBarAddRequestMessage"));
	handlers.push_back(new Handler(ShortcutBarRemoveRequestMessage::id, &GameHandler::ShortcutBarRemoveRequestMessageHandler, "ShortcutBarRemoveRequestMessage"));
	handlers.push_back(new Handler(ShortcutBarSwapRequestMessage::id, &GameHandler::ShortcutBarSwapRequestMessageHandler, "ShortcutBarSwapRequestMessage"));

	/*
	**	Admin Handler
	*/

	handlers.push_back(new Handler(5662, &AdminHandler::AdminQuietCommandMessageHandler, "AdminQuietCommandMessage"));

	/*
	**	Chat Handler
	*/

	handlers.push_back(new Handler(ChatClientMultiMessage::id, &ChatHandler::ChatClientMultiMessageHandler, "ChatClientMultiMessage"));
	handlers.push_back(new Handler(ChatClientPrivateMessage::id, &ChatHandler::ChatClientPrivateMessageHandler, "ChatClientPrivateMessage"));

	std::list<Handler*>::iterator iter = handlers.begin();
	std::list<Handler*>::iterator end = handlers.end();

	bool packetHandled = false;
	while (iter != handlers.end())
	{
		Handler *handle = *iter;
		if (handle->packetId == packet.id())
		{
			try
			{
				packetHandled = true;
				Logger::NetworkRcv(packet, client, handle->name);
				handle->func(reader, client);
				break;
			}
			catch (std::exception &e)
			{
				Logger::Error("An error ocurred while trying to process a packet", 12, e.what());
				break;
			}
		}
		++iter;
	}
	if (packetHandled == false)
		Logger::NetworkRcv(packet, client);
	Processor::removeHandlers(handlers);
	return false;
}

void Processor::removeHandlers(std::list<Handler*> handlers)
{
	std::list<Handler*>::iterator iter = handlers.begin();
	std::list<Handler*>::iterator end = handlers.end();

	while (iter != handlers.end())
	{
		Handler *handle = *iter;
		delete handle;
		++iter;
	}
}