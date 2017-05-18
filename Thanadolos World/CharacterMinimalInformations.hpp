#pragma once
#ifndef CHARACTERMINIMALINFORMATIONS_HPP
#define CHARACTERMINIMALINFORMATIONS_HPP

#include "IType.hpp"
#include "CharacterBasicMinimalInformations.hpp"

class CharacterMinimalInformations : public CharacterBasicMinimalInformations
{
public:
	CharacterMinimalInformations(int id, std::string name, int level);
	CharacterMinimalInformations();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int __id = 110;

	/* VARIABLES */
	int level;
};


#endif