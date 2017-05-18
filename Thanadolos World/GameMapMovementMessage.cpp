#include "Globals.h"
#include "GameMapMovementMessage.hpp"

GameMapMovementMessage::GameMapMovementMessage(std::vector<uint> keyMovements, int forcedDirection, int actorId)
{
	this->keyMovements = keyMovements;
	this->actorId = actorId;

}

GameMapMovementMessage::GameMapMovementMessage()
{

}

ushort GameMapMovementMessage::getId()
{
	return id;
}

std::string GameMapMovementMessage::getName()
{
	return "GameMapMovementMessage";
}

void GameMapMovementMessage::serialize(BinaryWriter& writer)
{
	writer.writeShort(this->keyMovements.size());	int _loc2_ = 0;
	while (_loc2_ < this->keyMovements.size())	{		writer.writeShort(this->keyMovements[_loc2_]);		_loc2_++;	}	writer.writeShort(this->forcedDirection);	writer.writeDouble(this->actorId.toNumber());
}

void GameMapMovementMessage::deserialize(BinaryReader& reader)
{
	{		int _loc4_ = 0;
		int _loc2_ = reader.readUnsignedShort();		int _loc3_ = 0;
		while (_loc3_ < _loc2_)		{			_loc4_ = reader.readShort();			this->keyMovements.push_back(_loc4_);			_loc3_++;		}		this->actorId = reader.readInt64();	}
}