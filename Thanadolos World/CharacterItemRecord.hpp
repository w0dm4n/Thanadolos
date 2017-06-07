#pragma once

#ifndef CHARACTERITEMRECORD_HPP
# define CHARACTERITEMRECORD_HPP

#include <iostream>
class CharacterItemRecord
{
public:
	static void declareRecord()
	{
		camp::Class::declare<CharacterItemRecord>("CharacterItemRecord")
			.constructor0().property("Id", &CharacterItemRecord::getId, &CharacterItemRecord::setId)
			.property("CharacterId", &CharacterItemRecord::getCharacterId, &CharacterItemRecord::setCharacterId)
			.property("TemplateId", &CharacterItemRecord::getTemplateId, &CharacterItemRecord::setTemplateId)
			.property("Quantity", &CharacterItemRecord::getQuantity, &CharacterItemRecord::setQuantity)
			.property("Position", &CharacterItemRecord::getPosition, &CharacterItemRecord::setPosition)
			.property("Effects", &CharacterItemRecord::getEffects, &CharacterItemRecord::setEffects);
	}
	CharacterItemRecord() { }

	int getId() { return this->Id; }
	void setId(int var) { this->Id = var; }

	int getCharacterId() { return this->CharacterId; }
	void setCharacterId(int var) { this->CharacterId = var; }

	int getTemplateId() { return this->TemplateId; }
	void setTemplateId(int var) { this->TemplateId = var; }

	int getQuantity() { return this->Quantity; }
	void setQuantity(int var) { this->Quantity = var; }

	int getPosition() { return this->Position; }
	void setPosition(int var) { this->Position = var; }

	std::string getEffects() { return this->Effects; }
	void setEffects(std::string var) { this->Effects = var; }



private:
	int Id;
	int CharacterId;
	int TemplateId;
	int Quantity;
	int Position;
	std::string Effects;
};

CAMP_TYPE(CharacterItemRecord)

#endif
