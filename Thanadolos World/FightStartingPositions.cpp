#include "Globals.h"
#include "FightStartingPositions.hpp"

FightStartingPositions::FightStartingPositions(std::vector<uint> positionsForChallengers, std::vector<uint> positionsForDefenders)
{
	this->positionsForChallengers = positionsForChallengers;
	this->positionsForDefenders = positionsForDefenders;

}

FightStartingPositions::FightStartingPositions()
{

}

ushort FightStartingPositions::getId()
{
	return __id;
}

std::string FightStartingPositions::getName()
{
	return "FightStartingPositions";
}

void FightStartingPositions::serialize(BinaryWriter& writer)
{
	writer.writeShort(this->positionsForChallengers.size());	int _loc2_ = 0;
	while (_loc2_ < this->positionsForChallengers.size())	{		writer.writeVarShort(this->positionsForChallengers[_loc2_]);		_loc2_++;	}	writer.writeShort(this->positionsForDefenders.size());	int _loc3_ = 0;
	while (_loc3_ < this->positionsForDefenders.size())	{		writer.writeVarShort(this->positionsForDefenders[_loc3_]);		_loc3_++;	}
}

void FightStartingPositions::deserialize(BinaryReader& reader)
{
	{		int _loc6_ = 0;
		int _loc7_ = 0;
		int _loc2_ = reader.readUnsignedShort();		int _loc3_ = 0;
		while (_loc3_ < _loc2_)		{			_loc6_ = reader.readVarUhShort();			this->positionsForChallengers.push_back(_loc6_);			_loc3_++;		}		int _loc4_ = reader.readUnsignedShort();		int _loc5_ = 0;
		while (_loc5_ < _loc4_)		{			_loc7_ = reader.readVarUhShort();			this->positionsForDefenders.push_back(_loc7_);			_loc5_++;		}	}
}