#pragma once
#ifndef FIGHTSTARTINGPOSITIONS_THANADOLOS_HPP
#define FIGHTSTARTINGPOSITIONS_THANADOLOS_HPP

#include "IType.hpp"


class FightStartingPositions : public IType
{
public:
	FightStartingPositions(std::vector<uint> positionsForChallengers, std::vector<uint> positionsForDefenders);
	FightStartingPositions();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int __id = 513;

	/*VARS*/
	std::vector<uint> positionsForChallengers;
	std::vector<uint> positionsForDefenders;
};


#endif