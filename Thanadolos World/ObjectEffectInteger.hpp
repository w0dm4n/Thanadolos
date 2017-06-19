#pragma once
#ifndef OBJECTEFFECTINTEGER_THANADOLOS_HPP
#define OBJECTEFFECTINTEGER_THANADOLOS_HPP

#include "IType.hpp"
#include "ObjectItem.hpp"

class ObjectEffectInteger : public ObjectItem
{
public:
	ObjectEffectInteger(int position, int objectGID, std::vector<ObjectEffect*> effects, int objectUID, int quantity, int value);
	ObjectEffectInteger();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int __id = 70;

	/*VARS*/
	int value;
};


#endif