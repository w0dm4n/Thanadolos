#include "Globals.h"
#include "MapInformationsRequestMessage.hpp"

MapInformationsRequestMessage::MapInformationsRequestMessage(int mapId)
{
	this->mapId = mapId;

}

MapInformationsRequestMessage::MapInformationsRequestMessage()
{

}

ushort MapInformationsRequestMessage::getId()
{
	return id;
}

std::string MapInformationsRequestMessage::getName()
{
	return "MapInformationsRequestMessage";
}

void MapInformationsRequestMessage::serialize(BinaryWriter& writer)
{
	writer.writeInt(this->mapId);
}

void MapInformationsRequestMessage::deserialize(BinaryReader& reader)
{
	{		this->mapId = reader.readInt();	}
}