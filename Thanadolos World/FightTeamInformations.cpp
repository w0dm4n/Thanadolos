#include "Globals.h"
#include "FightTeamInformations.hpp"

FightTeamInformations::FightTeamInformations(int teamId, int leaderId, int teamSide, int teamTypeId, int nbWaves, std::vector<FightTeamMemberInformations> teamMemberss) : AbstractFightTeamInformations(teamId, leaderId, teamSide, teamTypeId, nbWaves)
{
	this->teamMembers = teamMembers;

}

FightTeamInformations::FightTeamInformations()
{

}

ushort FightTeamInformations::getId()
{
	return __id;
}

std::string FightTeamInformations::getName()
{
	return "FightTeamInformations";
}

void FightTeamInformations::serialize(BinaryWriter& writer)
{
	AbstractFightTeamInformations::serialize(writer);
	writer.writeShort(this->teamMembers.size());	int _loc2_ = 0;
	while (_loc2_ < this->teamMembers.size())	{		writer.writeShort((this->teamMembers[_loc2_]).getId());		(this->teamMembers[_loc2_]).serialize(writer);		_loc2_++;	}
}

void FightTeamInformations::deserialize(BinaryReader& reader)
{
	{		int _loc4_ = 0;
		FightTeamMemberInformations _loc5_;
		AbstractFightTeamInformations::deserialize(reader);		int _loc2_ = reader.readUnsignedShort();		int _loc3_ = 0;
		while (_loc3_ < _loc2_)		{			_loc4_ = reader.readUnsignedShort();			_loc5_.deserialize(reader);			this->teamMembers.push_back(_loc5_);			_loc3_++;		}	}
}