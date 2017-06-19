#pragma once
#ifndef OBJECTEFFECT_THANADOLOS_HPP
#define OBJECTEFFECT_THANADOLOS_HPP

#include "IType.hpp"


class ObjectEffect : public IType
{
public:
	ObjectEffect(int actionId);
	ObjectEffect();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int __id = 76;

	/*VARS*/
	int actionId;
};


#endif