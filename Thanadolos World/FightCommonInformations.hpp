#pragma once
#ifndef FIGHTCOMMONINFORMATIONS_THANADOLOS_HPP
#define FIGHTCOMMONINFORMATIONS_THANADOLOS_HPP

#include "IType.hpp"
#include "FightTeamInformations.hpp"
#include "FightOptionsInformations.hpp"

class FightCommonInformations : public IType
{
public:
	FightCommonInformations(int fightId, int fightType, std::vector<FightTeamInformations> fightTeams, std::vector<uint> fightTeamsPositions, std::vector<FightOptionsInformations> fightTeamsOptions);
	FightCommonInformations();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int __id = 43;

	/*VARS*/
	int fightId;
	int fightType;
	std::vector<FightTeamInformations> fightTeams;
	std::vector<uint> fightTeamsPositions;
	std::vector<FightOptionsInformations> fightTeamsOptions;
};


#endif