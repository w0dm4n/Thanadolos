#include "Globals.h"
#include "ChatClientMultiMessage.hpp"

ChatClientMultiMessage::ChatClientMultiMessage(std::string content, int channel) : ChatAbstractClientMessage(content)
{
	this->channel = channel;

}

ChatClientMultiMessage::ChatClientMultiMessage()
{

}

ushort ChatClientMultiMessage::getId()
{
	return id;
}

std::string ChatClientMultiMessage::getName()
{
	return "ChatClientMultiMessage";
}

void ChatClientMultiMessage::serialize(BinaryWriter& writer)
{
	ChatAbstractClientMessage::serialize(writer);
	writer.writeByte(this->channel);
}

void ChatClientMultiMessage::deserialize(BinaryReader& reader)
{
	{		ChatAbstractClientMessage::deserialize(reader);		this->channel = reader.readByte();	}
}