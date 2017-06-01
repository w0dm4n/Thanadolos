#include "Globals.h"
#include "Spell.hpp"

Spell::Spell(camp::UserObject spellCharacterRecord, Database *database) : spellCharacterRecord(spellCharacterRecord), database(database)
{
	this->spellRecord = database->getRecordObject(this->spellCharacterRecord.get("SpellId"), "SpellsRecord");
	int currentSpellLevel = spellCharacterRecord.get("SpellLevel");
	std::string spellLevels = this->spellRecord.get("spellLevels");
	int spellLevelId = 0;

	Split levels = Utils::split(spellLevels, ',');
	if (levels.size() >= (currentSpellLevel - 1))
		spellLevelId = std::stoi(levels[(currentSpellLevel - 1)]);
	else
		spellLevelId = std::stoi(levels[levels.size() - 1]);
	this->spellLevel = SpellLevel(spellLevelId, database);
}

bool Spell::updateSpellLevel(int spellLevel)
{
	std::string spellLevels = this->spellRecord.get("spellLevels");
	Split levels = Utils::split(spellLevels, ',');
	if (levels.size() >= (spellLevel - 1))
	{
		this->spellLevel = SpellLevel(std::stoi(levels[(spellLevel - 1)]), database);
		if (this->spellLevel.levelRecord.pointer() != NULL)
		{
			this->spellCharacterRecord.set("SpellLevel", spellLevel);
			return true;
		}
	}
	return false;
}