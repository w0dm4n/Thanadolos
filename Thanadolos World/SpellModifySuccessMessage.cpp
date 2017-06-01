#include "Globals.h"
#include "SpellModifySuccessMessage.hpp"

SpellModifySuccessMessage::SpellModifySuccessMessage(int spellId, int spellLevel)
{
	this->spellId = spellId;
	this->spellLevel = spellLevel;

}

SpellModifySuccessMessage::SpellModifySuccessMessage()
{

}

ushort SpellModifySuccessMessage::getId()
{
	return id;
}

std::string SpellModifySuccessMessage::getName()
{
	return "SpellModifySuccessMessage";
}

void SpellModifySuccessMessage::serialize(BinaryWriter& writer)
{
	writer.writeInt(this->spellId);
}

void SpellModifySuccessMessage::deserialize(BinaryReader& reader)
{
	{
}