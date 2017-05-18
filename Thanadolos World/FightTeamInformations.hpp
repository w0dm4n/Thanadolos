#pragma once
#ifndef FIGHTTEAMINFORMATIONS_THANADOLOS_HPP
#define FIGHTTEAMINFORMATIONS_THANADOLOS_HPP

#include "IType.hpp"
#include "FightTeamMemberInformations.hpp"
#include "AbstractFightTeamInformations.hpp"

class FightTeamInformations : public AbstractFightTeamInformations
{
public:
	FightTeamInformations(int teamId, int leaderId, int teamSide, int teamTypeId, int nbWaves, std::vector<FightTeamMemberInformations> teamMembers);
	FightTeamInformations();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int __id = 33;

	/*VARS*/
	std::vector<FightTeamMemberInformations> teamMembers;
};


#endif