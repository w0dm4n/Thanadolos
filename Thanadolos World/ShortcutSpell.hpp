#pragma once
#ifndef SHORTCUTSPELL_THANADOLOS_HPP
#define SHORTCUTSPELL_THANADOLOS_HPP

#include "IType.hpp"
#include "Shortcut.hpp"

class ShortcutSpell : public Shortcut
{
public:
	ShortcutSpell(int slotId, int spellId);
	ShortcutSpell();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int __id = 368;

	/*VARS*/
	int spellId;
};


#endif