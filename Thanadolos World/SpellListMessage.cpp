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
	writer.writeBool(this->spellPrevisualization);	writer.writeShort(this->spells.size());	int _loc2_ = 0;
	while (_loc2_ < this->spells.size())	{		(this->spells[_loc2_]).serialize(writer);
		_loc2_++;	}
}

void SpellListMessage::deserialize(BinaryReader& reader)
{
	{		SpellItem _loc4_;
		this->spellPrevisualization = reader.readBool();		int _loc2_ = reader.readUnsignedShort();		int _loc3_ = 0;
		while (_loc3_ < _loc2_)		{			_loc4_.deserialize(reader);			this->spells.push_back(_loc4_);			_loc3_++;		}	}
}