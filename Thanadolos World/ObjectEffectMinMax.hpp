#pragma once
#ifndef OBJECTEFFECTMINMAX_THANADOLOS_HPP
#define OBJECTEFFECTMINMAX_THANADOLOS_HPP

#include "IType.hpp"
#include "ObjectItem.hpp"

class ObjectEffectMinMax : public ObjectItem
{
public:
	ObjectEffectMinMax(int position, int objectGID, std::vector<ObjectEffect*> effects, int objectUID, int quantity, int value, int min, int max);
	ObjectEffectMinMax();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int __id = 82;

	/*VARS*/
	int min;
	int max;
};


#endif