#pragma once
#ifndef OBJECTEFFECTDICE_THANADOLOS_HPP
#define OBJECTEFFECTDICE_THANADOLOS_HPP

#include "IType.hpp"
#include "ObjectItem.hpp"

class ObjectEffectDice : public ObjectItem
{
public:
	ObjectEffectDice(int position, int objectGID, std::vector<ObjectEffect*> effects, int objectUID, int quantity, int diceNum, int diceSide, int diceConst);
	ObjectEffectDice();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int __id = 73;

	/*VARS*/
	int diceNum;
	int diceSide;
	int diceConst;
};


#endif