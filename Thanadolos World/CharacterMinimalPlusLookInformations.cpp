#include "Globals.h"
#include "CharacterMinimalPlusLookInformations.hpp"

CharacterMinimalPlusLookInformations::CharacterMinimalPlusLookInformations(int id, std::string name, int level, EntityLook &entityLook) : CharacterMinimalInformations(id, name, level)
{
	this->entityLook = entityLook;
}

CharacterMinimalPlusLookInformations::CharacterMinimalPlusLookInformations()
{

}

ushort CharacterMinimalPlusLookInformations::getId()
{
	return __id;
}

std::string CharacterMinimalPlusLookInformations::getName()
{
	return "CharacterMinimalPlusLookInformations";
}

void CharacterMinimalPlusLookInformations::serialize(BinaryWriter& writer)
{
	CharacterMinimalInformations::serialize(writer);
	this->entityLook.serialize(writer);
}

void CharacterMinimalPlusLookInformations::deserialize(BinaryReader& reader)
{
	CharacterMinimalInformations::deserialize(reader);
	this->entityLook.deserialize(reader);
}