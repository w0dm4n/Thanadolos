#include "Globals.h"
#include "ChatClientPrivateMessage.hpp"

ChatClientPrivateMessage::ChatClientPrivateMessage(std::string content, std::string receiver) : ChatAbstractClientMessage(content)
{
	this->receiver = receiver;

}

ChatClientPrivateMessage::ChatClientPrivateMessage()
{

}

ushort ChatClientPrivateMessage::getId()
{
	return id;
}

std::string ChatClientPrivateMessage::getName()
{
	return "ChatClientPrivateMessage";
}

void ChatClientPrivateMessage::serialize(BinaryWriter& writer)
{
	ChatAbstractClientMessage::serialize(writer);
	writer.writeUTF(this->receiver);
}

void ChatClientPrivateMessage::deserialize(BinaryReader& reader)
{
	{		ChatAbstractClientMessage::deserialize(reader);		this->receiver = reader.readUTF();	}
}