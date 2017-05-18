#include "Globals.h"
#include "ChangeMapMessage.hpp"

ChangeMapMessage::ChangeMapMessage(int mapId)
{
	this->mapId = mapId;

}

ChangeMapMessage::ChangeMapMessage()
{

}

ushort ChangeMapMessage::getId()
{
	return id;
}

std::string ChangeMapMessage::getName()
{
	return "ChangeMapMessage";
}

void ChangeMapMessage::serialize(BinaryWriter& writer)
{
	writer.writeInt(this->mapId);
}

void ChangeMapMessage::deserialize(BinaryReader& reader)
{
	{		this->mapId = reader.readInt();	}
}