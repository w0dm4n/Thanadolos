#pragma once
#include "SpellLevel.hpp"
#include "Database.hpp"
#include "SpellLevel.hpp"
class Spell
{
public:
	Spell(camp::UserObject spellCharacterRecord, Database *database);
	bool				updateSpellLevel(int spellLevel);
	camp::UserObject	spellCharacterRecord;
	camp::UserObject	spellRecord;
	SpellLevel			spellLevel;
	Database			*database;
	std::string			hello;
};