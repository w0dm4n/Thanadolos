#include "Globals.h"
#include "FightCommonInformations.hpp"

FightCommonInformations::FightCommonInformations(int fightId, int fightType, std::vector<FightTeamInformations> fightTeams, std::vector<uint> fightTeamsPositions, std::vector<FightOptionsInformations> fightTeamsOptions)
{
	this->fightId = fightId;
	this->fightType = fightType;
	this->fightTeams = fightTeams;
	this->fightTeamsPositions = fightTeamsPositions;
	this->fightTeamsOptions = fightTeamsOptions;

}

FightCommonInformations::FightCommonInformations()
{

}

ushort FightCommonInformations::getId()
{
	return __id;
}

std::string FightCommonInformations::getName()
{
	return "FightCommonInformations";
}

void FightCommonInformations::serialize(BinaryWriter& writer)
{
	writer.writeInt(this->fightId);	writer.writeByte(this->fightType);	writer.writeShort(this->fightTeams.size());	int _loc2_ = 0;
	while (_loc2_ < this->fightTeams.size())	{		writer.writeShort((this->fightTeams[_loc2_]).getId());		(this->fightTeams[_loc2_]).serialize(writer);		_loc2_++;	}	writer.writeShort(this->fightTeamsPositions.size());	int _loc3_ = 0;
	while (_loc3_ < this->fightTeamsPositions.size())	{		writer.writeVarShort(this->fightTeamsPositions[_loc3_]);		_loc3_++;	}	writer.writeShort(this->fightTeamsOptions.size());	int _loc4_ = 0;
	while (_loc4_ < this->fightTeamsOptions.size())	{		(this->fightTeamsOptions[_loc4_]);
		_loc4_++;	}
}

void FightCommonInformations::deserialize(BinaryReader& reader)
{
	{		int _loc8_ = 0;
		FightTeamInformations _loc9_;
		int _loc10_ = 0;
		FightOptionsInformations _loc11_;
		this->fightId = reader.readInt();		this->fightType = reader.readByte();		int _loc2_ = reader.readUnsignedShort();		int _loc3_ = 0;
		while (_loc3_ < _loc2_)		{			_loc8_ = reader.readUnsignedShort();			_loc9_.deserialize(reader);			this->fightTeams.push_back(_loc9_);			_loc3_++;		}		int _loc4_ = reader.readUnsignedShort();		int _loc5_ = 0;
		while (_loc5_ < _loc4_)		{			_loc10_ = reader.readVarUhShort();			this->fightTeamsPositions.push_back(_loc10_);			_loc5_++;		}		int _loc6_ = reader.readUnsignedShort();		int _loc7_ = 0;
		while (_loc7_ < _loc6_)		{			_loc11_.deserialize(reader);			this->fightTeamsOptions.push_back(_loc11_);			_loc7_++;		}	}
}