#include "Globals.h"
#include "CharacterSpellModification.hpp"

CharacterSpellModification::CharacterSpellModification(int modificationType, int spellId, CharacterBaseCharacteristic& value)
{
	this->modificationType = modificationType;
	this->spellId = spellId;
	this->value = value;

}

CharacterSpellModification::CharacterSpellModification()
{

}

ushort CharacterSpellModification::getId()
{
	return __id;
}

std::string CharacterSpellModification::getName()
{
	return "CharacterSpellModification";
}

void CharacterSpellModification::serialize(BinaryWriter& writer)
{
	writer.writeByte(this->modificationType);

}

void CharacterSpellModification::deserialize(BinaryReader& reader)
{
	{
}