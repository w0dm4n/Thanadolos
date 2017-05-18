#pragma once
#ifndef ENTITYLOOK_HPP
#define ENTITYLOOK_HPP

#include "IType.hpp"
#include "SubEntity.hpp"

class EntityLook : public IType
{
public:
	EntityLook(uint bonesId,
	std::vector<uint> skins,
	std::vector<int> indexedColors,
	std::vector<int> scales,
	std::vector<SubEntity> subentities);
	EntityLook();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int __id = 55;
	/* VARIABLES */
	uint bonesId;
	std::vector<uint> skins;
	std::vector<int> indexedColors;
	std::vector<int> scales;
	std::vector<SubEntity> subentities;
};


#endif