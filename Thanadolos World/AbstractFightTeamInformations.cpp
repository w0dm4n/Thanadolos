#include "Globals.h"
#include "AbstractFightTeamInformations.hpp"

AbstractFightTeamInformations::AbstractFightTeamInformations(int teamId, int leaderId, int teamSide, int teamTypeId, int nbWaves)
{
	this->teamId = teamId;
	this->leaderId = leaderId;
	this->teamSide = teamSide;
	this->teamTypeId = teamTypeId;
	this->nbWaves = nbWaves;

}

AbstractFightTeamInformations::AbstractFightTeamInformations()
{

}

ushort AbstractFightTeamInformations::getId()
{
	return __id;
}

std::string AbstractFightTeamInformations::getName()
{
	return "AbstractFightTeamInformations";
}

void AbstractFightTeamInformations::serialize(BinaryWriter& writer)
{
	writer.writeByte(this->teamId);
}

void AbstractFightTeamInformations::deserialize(BinaryReader& reader)
{
	{
}