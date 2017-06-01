#include "Globals.h"
#include "SpellItem.hpp"

SpellItem::SpellItem(int spellId, int spellLevel) : Item()
{
	this->spellId = spellId;
	this->spellLevel = spellLevel;
}

SpellItem::SpellItem()
{

}

ushort SpellItem::getId()
{
	return __id;
}

std::string SpellItem::getName()
{
	return "SpellItem";
}

void SpellItem::serialize(BinaryWriter& writer)
{
	Item::serialize(writer);
	writer.writeInt(this->spellId);	writer.writeShort(this->spellLevel);
}

void SpellItem::deserialize(BinaryReader& reader)
{
	{		Item::deserialize(reader);		this->spellId = reader.readInt();		this->spellLevel = reader.readShort();	}
}