#include "Globals.h"
#include "FightTeamMemberInformations.hpp"

FightTeamMemberInformations::FightTeamMemberInformations(int id)
{
	this->id = id;

}

FightTeamMemberInformations::FightTeamMemberInformations()
{

}

ushort FightTeamMemberInformations::getId()
{
	return __id;
}

std::string FightTeamMemberInformations::getName()
{
	return "FightTeamMemberInformations";
}

void FightTeamMemberInformations::serialize(BinaryWriter& writer)
{
	writer.writeDouble(this->id.toNumber());
}

void FightTeamMemberInformations::deserialize(BinaryReader& reader)
{
	{		this->id = reader.readInt64();	}
}