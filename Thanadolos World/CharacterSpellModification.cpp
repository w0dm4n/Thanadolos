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
	writer.writeByte(this->modificationType);	writer.writeVarShort(this->spellId);	this->value.serialize(writer);

}

void CharacterSpellModification::deserialize(BinaryReader& reader)
{
	{		this->modificationType = reader.readByte();		this->spellId = reader.readVarUhShort();		this->value.deserialize(reader);	}
}