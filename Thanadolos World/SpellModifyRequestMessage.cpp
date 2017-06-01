#include "Globals.h"
#include "SpellModifyRequestMessage.hpp"

SpellModifyRequestMessage::SpellModifyRequestMessage(int spellId, int spellLevel)
{
	this->spellId = spellId;
	this->spellLevel = spellLevel;

}

SpellModifyRequestMessage::SpellModifyRequestMessage()
{

}

ushort SpellModifyRequestMessage::getId()
{
	return id;
}

std::string SpellModifyRequestMessage::getName()
{
	return "SpellModifyRequestMessage";
}

void SpellModifyRequestMessage::serialize(BinaryWriter& writer)
{
	writer.writeVarShort(this->spellId);	writer.writeShort(this->spellLevel);
}

void SpellModifyRequestMessage::deserialize(BinaryReader& reader)
{
	{		this->spellId = reader.readVarUhShort();		this->spellLevel = reader.readShort();	}
}