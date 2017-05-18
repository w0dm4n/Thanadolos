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
	writer.writeShort(this->teamMembers.size());
	while (_loc2_ < this->teamMembers.size())
}

void FightTeamInformations::deserialize(BinaryReader& reader)
{
	{
		FightTeamMemberInformations _loc5_;
		AbstractFightTeamInformations::deserialize(reader);
		while (_loc3_ < _loc2_)
}