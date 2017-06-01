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
	writer.writeInt(this->spellId);	writer.writeShort(this->spellLevel);
}

void SpellModifySuccessMessage::deserialize(BinaryReader& reader)
{
	{		this->spellId = reader.readInt();		this->spellLevel = reader.readShort();	}
}