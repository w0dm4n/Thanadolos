#pragma once
#ifndef CHARACTERMINIMALPLUSLOOKINFORMATIONS_HPP
#define CHARACTERMINIMALPLUSLOOKINFORMATIONS_HPP

#include "IType.hpp"
#include "CharacterMinimalInformations.hpp"
#include "EntityLook.hpp"

class CharacterMinimalPlusLookInformations : public CharacterMinimalInformations
{
public:
	CharacterMinimalPlusLookInformations(int id, std::string name, int level, EntityLook &entityLook);
	CharacterMinimalPlusLookInformations();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int __id = 163;

	/* VARIABLES */
	EntityLook entityLook;
};


#endif