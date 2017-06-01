#include "Globals.h"
#include "ShortcutSpell.hpp"

ShortcutSpell::ShortcutSpell(int slotId, int spellId) : Shortcut(slotId)
{
	this->spellId = spellId;

}

ShortcutSpell::ShortcutSpell()
{

}

ushort ShortcutSpell::getId()
{
	return __id;
}

std::string ShortcutSpell::getName()
{
	return "ShortcutSpell";
}

void ShortcutSpell::serialize(BinaryWriter& writer)
{
	Shortcut::serialize(writer);
	writer.writeVarShort(this->spellId);
}

void ShortcutSpell::deserialize(BinaryReader& reader)
{
	{		Shortcut::deserialize(reader);		this->spellId = reader.readVarUhShort();	}
}