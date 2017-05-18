#pragma once
#ifndef CHARACTERBASECHARACTERISTIC_THANADOLOS_HPP
#define CHARACTERBASECHARACTERISTIC_THANADOLOS_HPP

#include "IType.hpp"


class CharacterBaseCharacteristic : public IType
{
public:
	CharacterBaseCharacteristic(int base, int additionnal, int objectsAndMountBonus, int alignGiftBonus, int contextModif);
	CharacterBaseCharacteristic();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int __id = 4;

	/*VARS*/
	int base;
	int additionnal;
	int objectsAndMountBonus;
	int alignGiftBonus;
	int contextModif;
};


#endif