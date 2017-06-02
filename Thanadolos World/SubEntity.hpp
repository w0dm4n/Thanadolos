#pragma once
#ifndef SUBENTITY_HPP
#define SUBENTITY_HPP

#include "IType.hpp"
class EntityLook;

class SubEntity : public IType
{
public:
	SubEntity(uint bindingPointCategory,
	uint bindingPointIndex,
	EntityLook *subEntityLook);
	SubEntity();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int __id = 54;

	/* VARIABLES */
	uint bindingPointCategory;
	uint bindingPointIndex;
	EntityLook *subEntityLook;
};


#endif