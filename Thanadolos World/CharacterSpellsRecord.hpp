#pragma once

#ifndef CHARACTERSPELLSRECORD_HPP
# define CHARACTERSPELLSRECORD_HPP

#include <iostream>
class CharacterSpellsRecord
{
public:
	static void declareRecord()
	{
		camp::Class::declare<CharacterSpellsRecord>("CharacterSpellsRecord")
			.constructor0().property("Id", &CharacterSpellsRecord::getId, &CharacterSpellsRecord::setId)
			.property("CharacterId", &CharacterSpellsRecord::getCharacterId, &CharacterSpellsRecord::setCharacterId)
			.property("SpellId", &CharacterSpellsRecord::getSpellId, &CharacterSpellsRecord::setSpellId)
			.property("SpellLevel", &CharacterSpellsRecord::getSpellLevel, &CharacterSpellsRecord::setSpellLevel);

	}
	CharacterSpellsRecord() { }

	int getId() { return this->Id; }
	void setId(int var) { this->Id = var; }

	int getCharacterId() { return this->CharacterId; }
	void setCharacterId(int var) { this->CharacterId = var; }

	int getSpellId() { return this->SpellId; }
	void setSpellId(int var) { this->SpellId = var; }

	int getSpellLevel() { return this->SpellLevel; }
	void setSpellLevel(int var) { this->SpellLevel = var; }



private:
	int Id;
	int CharacterId;
	int SpellId;
	int SpellLevel;
};

CAMP_TYPE(CharacterSpellsRecord)

#endif
