#include "Globals.h"
#include "CharacterBaseInformations.hpp"

CharacterBaseInformations::CharacterBaseInformations(int id, std::string name, int level, EntityLook &entityLook, int breed, bool sex) : CharacterMinimalPlusLookInformations(id, name, level, entityLook)
{
	this->breed = breed;
	this->sex = sex;
}

CharacterBaseInformations::CharacterBaseInformations()
{

}

ushort CharacterBaseInformations::getId()
{
	return __id;
}

std::string CharacterBaseInformations::getName()
{
	return "CharacterBaseInformations";
}

CharacterBaseInformations::~CharacterBaseInformations()
{
}

void CharacterBaseInformations::serialize(BinaryWriter& writer)
{
	CharacterMinimalPlusLookInformations::serialize(writer);
	writer.writeByte(this->breed);
	writer.writeBool(this->sex);
}

void CharacterBaseInformations::deserialize(BinaryReader& reader)
{
	CharacterMinimalPlusLookInformations::deserialize(reader);
	this->breed = reader.readByte();
	this->sex = reader.readBool();
}