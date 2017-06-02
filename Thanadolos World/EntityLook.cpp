#include "Globals.h"
#include "EntityLook.hpp"

EntityLook::EntityLook(uint bonesId,
	std::vector<uint> skins,
	std::vector<int> indexedColors,
	std::vector<int> scales,
	std::vector<SubEntity> subentities)
{
	this->bonesId = bonesId;
	this->skins = skins;
	this->indexedColors = indexedColors;
	this->scales = scales;
	this->subentities = subentities;
}

EntityLook::EntityLook()
{

}

ushort EntityLook::getId()
{
	return __id;
}

std::string EntityLook::getName()
{
	return "EntityLook";
}

void EntityLook::serialize(BinaryWriter& writer)
{
	writer.writeVarShort(this->bonesId);
	writer.writeShort(this->skins.size());
	int i = 0;
	while (i < this->skins.size())
		writer.writeVarShort(this->skins[i++]);

	writer.writeShort(this->indexedColors.size());
	i = 0;
	while (i < this->indexedColors.size())
		writer.writeInt(this->indexedColors[i++]);

	writer.writeShort(this->scales.size());
	i = 0;
	while (i < this->scales.size())
		writer.writeVarShort(this->scales[i++]);

	writer.writeShort(this->subentities.size());
	i = 0;
	while (i < this->subentities.size())
		this->subentities[i++].serialize(writer);
}

void EntityLook::deserialize(BinaryReader& reader)
{
	// ahahahahah
}