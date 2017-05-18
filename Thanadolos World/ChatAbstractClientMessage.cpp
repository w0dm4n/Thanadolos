#include "Globals.h"
#include "ChatAbstractClientMessage.hpp"

ChatAbstractClientMessage::ChatAbstractClientMessage(std::string content)
{
	this->content = content;

}

ChatAbstractClientMessage::ChatAbstractClientMessage()
{

}

ushort ChatAbstractClientMessage::getId()
{
	return id;
}

std::string ChatAbstractClientMessage::getName()
{
	return "ChatAbstractClientMessage";
}

void ChatAbstractClientMessage::serialize(BinaryWriter& writer)
{
	writer.writeUTF(this->content);
}

void ChatAbstractClientMessage::deserialize(BinaryReader& reader)
{
	{		this->content = reader.readUTF();	}
}