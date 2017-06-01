#pragma once

#ifndef CHARACTERSHORTCUTSRECORD_HPP
# define CHARACTERSHORTCUTSRECORD_HPP

#include <iostream>
class CharacterShortcutsRecord
{
public:
	static void declareRecord()
	{
		camp::Class::declare<CharacterShortcutsRecord>("CharacterShortcutsRecord")
			.constructor0().property("Id", &CharacterShortcutsRecord::getId, &CharacterShortcutsRecord::setId)
			.property("CharacterId", &CharacterShortcutsRecord::getCharacterId, &CharacterShortcutsRecord::setCharacterId)
			.property("ObjectId", &CharacterShortcutsRecord::getObjectId, &CharacterShortcutsRecord::setObjectId)
			.property("ObjectUID", &CharacterShortcutsRecord::getObjectUID, &CharacterShortcutsRecord::setObjectUID)
			.property("SlotId", &CharacterShortcutsRecord::getSlotId, &CharacterShortcutsRecord::setSlotId)
			.property("TypeId", &CharacterShortcutsRecord::getTypeId, &CharacterShortcutsRecord::setTypeId);

	}
	CharacterShortcutsRecord() { }

	int getId() { return this->Id; }
	void setId(int var) { this->Id = var; }

	int getCharacterId() { return this->CharacterId; }
	void setCharacterId(int var) { this->CharacterId = var; }

	int getObjectId() { return this->ObjectId; }
	void setObjectId(int var) { this->ObjectId = var; }

	int getObjectUID() { return this->ObjectUID; }
	void setObjectUID(int var) { this->ObjectUID = var; }

	int getSlotId() { return this->SlotId; }
	void setSlotId(int var) { this->SlotId = var; }

	int getTypeId() { return this->TypeId; }
	void setTypeId(int var) { this->TypeId = var; }


private:
	int Id;
	int CharacterId;
	int ObjectId;
	int ObjectUID;
	int SlotId;
	int TypeId;
};

CAMP_TYPE(CharacterShortcutsRecord)

#endif
