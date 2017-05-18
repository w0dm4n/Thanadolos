#pragma once
#ifndef CHARACTERBASEINFORMATIONS_HPP
#define CHARACTERBASEINFORMATIONS_HPP

#include "IType.hpp"
#include "CharacterMinimalPlusLookInformations.hpp"

class CharacterBaseInformations : public CharacterMinimalPlusLookInformations
{
public:
	CharacterBaseInformations(int id, std::string name, int level, EntityLook &entityLook, int breed, bool sex);
	CharacterBaseInformations();
	ushort getId();
	~CharacterBaseInformations();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int __id = 45;

	/* VARIABLES */
	int breed;
	bool sex;
};


#endif