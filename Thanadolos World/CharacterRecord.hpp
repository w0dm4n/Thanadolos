#pragma once

#ifndef CHARACTERRECORD_HPP
# define CHARACTERRECORD_HPP

#include <iostream>
class CharacterRecord
{
public:
	static void declareRecord()
	{
		camp::Class::declare<CharacterRecord>("CharacterRecord")
			.constructor0().property("Id", &CharacterRecord::getId, &CharacterRecord::setId)
			.property("AccountId", &CharacterRecord::getAccountId, &CharacterRecord::setAccountId)
			.property("Name", &CharacterRecord::getName, &CharacterRecord::setName)
			.property("Level", &CharacterRecord::getLevel, &CharacterRecord::setLevel)
			.property("Experience", &CharacterRecord::getExperience, &CharacterRecord::setExperience)
			.property("Kamas", &CharacterRecord::getKamas, &CharacterRecord::setKamas)
			.property("Breed", &CharacterRecord::getBreed, &CharacterRecord::setBreed)
			.property("Sex", &CharacterRecord::getSex, &CharacterRecord::setSex)
			.property("MapId", &CharacterRecord::getMapId, &CharacterRecord::setMapId)
			.property("CellId", &CharacterRecord::getCellId, &CharacterRecord::setCellId)
			.property("CosmeticId", &CharacterRecord::getCosmeticId, &CharacterRecord::setCosmeticId)
			.property("Colors_0", &CharacterRecord::getColors_0, &CharacterRecord::setColors_0)
			.property("Colors_1", &CharacterRecord::getColors_1, &CharacterRecord::setColors_1)
			.property("Colors_2", &CharacterRecord::getColors_2, &CharacterRecord::setColors_2)
			.property("Colors_3", &CharacterRecord::getColors_3, &CharacterRecord::setColors_3)
			.property("Colors_4", &CharacterRecord::getColors_4, &CharacterRecord::setColors_4);

	}
	CharacterRecord() { }

	int getId() { return this->Id; }
	void setId(int var) { this->Id = var; }

	int getAccountId() { return this->AccountId; }
	void setAccountId(int var) { this->AccountId = var; }

	std::string getName() { return this->Name; }
	void setName(std::string var) { this->Name = var; }

	int getLevel() { return this->Level; }
	void setLevel(int var) { this->Level = var; }

	std::string getExperience() { return this->Experience; }
	void setExperience(std::string var) { this->Experience = var; }

	int getKamas() { return this->Kamas; }
	void setKamas(int var) { this->Kamas = var; }

	int getBreed() { return this->Breed; }
	void setBreed(int var) { this->Breed = var; }

	int getSex() { return this->Sex; }
	void setSex(int var) { this->Sex = var; }

	int getMapId() { return this->MapId; }
	void setMapId(int var) { this->MapId = var; }

	int getCellId() { return this->CellId; }
	void setCellId(int var) { this->CellId = var; }

	int getCosmeticId() { return this->CosmeticId; }
	void setCosmeticId(int var) { this->CosmeticId = var; }

	int getColors_0() { return this->Colors_0; }
	void setColors_0(int var) { this->Colors_0 = var; }

	int getColors_1() { return this->Colors_1; }
	void setColors_1(int var) { this->Colors_1 = var; }

	int getColors_2() { return this->Colors_2; }
	void setColors_2(int var) { this->Colors_2 = var; }

	int getColors_3() { return this->Colors_3; }
	void setColors_3(int var) { this->Colors_3 = var; }

	int getColors_4() { return this->Colors_4; }
	void setColors_4(int var) { this->Colors_4 = var; }



private:
	int Id;
	int AccountId;
	std::string Name;
	int Level;
	std::string Experience;
	int Kamas;
	int Breed;
	int Sex;
	int MapId;
	int CellId;
	int CosmeticId;
	int Colors_0;
	int Colors_1;
	int Colors_2;
	int Colors_3;
	int Colors_4;
};

CAMP_TYPE(CharacterRecord)

#endif
