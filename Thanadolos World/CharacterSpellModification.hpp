#pragma once
#ifndef CHARACTERSPELLMODIFICATION_THANADOLOS_HPP
#define CHARACTERSPELLMODIFICATION_THANADOLOS_HPP

#include "IType.hpp"
#include "CharacterBaseCharacteristic.hpp" 


class CharacterSpellModification : public IType
{
public:
	CharacterSpellModification(int modificationType, int spellId, CharacterBaseCharacteristic& value);
	CharacterSpellModification();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int __id = 215;

	/*VARS*/
	int modificationType;
	int spellId;
	CharacterBaseCharacteristic value;
};


#endif