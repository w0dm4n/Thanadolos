#pragma once
#ifndef ABSTRACTFIGHTTEAMINFORMATIONS_THANADOLOS_HPP
#define ABSTRACTFIGHTTEAMINFORMATIONS_THANADOLOS_HPP

#include "IType.hpp"


class AbstractFightTeamInformations : public IType
{
public:
	AbstractFightTeamInformations(int teamId, int leaderId, int teamSide, int teamTypeId, int nbWaves);
	AbstractFightTeamInformations();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int __id = 116;

	/*VARS*/
	int teamId;
	Int64 leaderId;
	int teamSide;
	int teamTypeId;
	int nbWaves;
};


#endif