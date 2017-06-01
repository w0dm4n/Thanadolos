#pragma once
#ifndef SPELLLISTMESSAGE_THANADOLOS_HPP
#define SPELLLISTMESSAGE_THANADOLOS_HPP

#include "imessage.h"
#include "SpellItem.hpp"

class SpellListMessage : public IMessage
{
public:
	SpellListMessage(bool spellPrevisualization, std::vector<SpellItem> spells);
	SpellListMessage();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 1200;

	/*VARS*/
	bool spellPrevisualization;
	std::vector<SpellItem> spells;
};


#endif