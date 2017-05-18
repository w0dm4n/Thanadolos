#include "Globals.h"
#include "GameMapMovementRequestMessage.hpp"

GameMapMovementRequestMessage::GameMapMovementRequestMessage(std::vector<uint> keyMovements, int mapId)
{
	this->keyMovements = keyMovements;
	this->mapId = mapId;

}

GameMapMovementRequestMessage::GameMapMovementRequestMessage()
{

}

ushort GameMapMovementRequestMessage::getId()
{
	return id;
}

std::string GameMapMovementRequestMessage::getName()
{
	return "GameMapMovementRequestMessage";
}

void GameMapMovementRequestMessage::serialize(BinaryWriter& writer)
{
	writer.writeShort(this->keyMovements.size());	int _loc2_ = 0;
	while (_loc2_ < this->keyMovements.size())	{		writer.writeShort(this->keyMovements[_loc2_]);		_loc2_++;	}	writer.writeInt(this->mapId);
}

void GameMapMovementRequestMessage::deserialize(BinaryReader& reader)
{
	{		int _loc4_ = 0;
		int _loc2_ = reader.readUnsignedShort();		int _loc3_ = 0;
		while (_loc3_ < _loc2_)		{			_loc4_ = reader.readShort();			this->keyMovements.push_back(_loc4_);			_loc3_++;		}		this->mapId = reader.readInt();	}
}