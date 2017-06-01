#pragma once
#ifndef SPELLITEM_THANADOLOS_HPP
#define SPELLITEM_THANADOLOS_HPP

#include "IType.hpp"
#include "Item.hpp"

class SpellItem : public Item
{
public:
	SpellItem(int spellId, int spellLevel);
	SpellItem();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int __id = 49;

	/*VARS*/
	int spellId;
	int spellLevel;
};


#endif