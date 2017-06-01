#include "Globals.h"
#include "SpellListMessage.hpp"

SpellListMessage::SpellListMessage(bool spellPrevisualization, std::vector<SpellItem> spells)
{
	this->spellPrevisualization = spellPrevisualization;
	this->spells = spells;
}

SpellListMessage::SpellListMessage()
{

}

ushort SpellListMessage::getId()
{
	return id;
}

std::string SpellListMessage::getName()
{
	return "SpellListMessage";
}

void SpellListMessage::serialize(BinaryWriter& writer)
{
	writer.writeBool(this->spellPrevisualization);
	while (_loc2_ < this->spells.size())
		_loc2_++;
}

void SpellListMessage::deserialize(BinaryReader& reader)
{
	{
		this->spellPrevisualization = reader.readBool();
		while (_loc3_ < _loc2_)
}