#include "Globals.h"
#include "AdminCommandMessage.hpp"

AdminCommandMessage::AdminCommandMessage(std::string content)
{
	this->content = content;
}

AdminCommandMessage::AdminCommandMessage()
{

}

ushort AdminCommandMessage::getId()
{
	return id;
}

std::string AdminCommandMessage::getName()
{
	return "AdminCommandMessage";
}

void AdminCommandMessage::serialize(BinaryWriter& writer)
{
	writer.writeUTF(this->content);
}

void AdminCommandMessage::deserialize(BinaryReader& reader)
{
	{		this->content = reader.readUTF();	}
}