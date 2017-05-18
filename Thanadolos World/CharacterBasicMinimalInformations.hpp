#pragma once
#ifndef CHARACTERBASICMINIMALINFORMATIONS_HPP
#define CHARACTERBASICMINIMALINFORMATIONS_HPP

#include "IType.hpp"
#include "AbstractCharacterInformation.hpp"

class CharacterBasicMinimalInformations : public AbstractCharacterInformation
{
public:
	CharacterBasicMinimalInformations(int id, std::string name);
	CharacterBasicMinimalInformations();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int __id = 503;

	/* VARIABLES */
	std::string name;
};


#endif