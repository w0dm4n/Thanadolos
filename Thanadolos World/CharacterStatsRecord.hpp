#pragma once

#ifndef CHARACTERSTATSRECORD_HPP
# define CHARACTERSTATSRECORD_HPP

#include <iostream>
class CharacterStatsRecord
{
public:
	static void declareRecord()
	{
		camp::Class::declare<CharacterStatsRecord>("CharacterStatsRecord")
			.constructor0().property("CharacterId", &CharacterStatsRecord::getCharacterId, &CharacterStatsRecord::setCharacterId)
			.property("StatsPoints", &CharacterStatsRecord::getStatsPoints, &CharacterStatsRecord::setStatsPoints)
			.property("SpellsPoints", &CharacterStatsRecord::getSpellsPoints, &CharacterStatsRecord::setSpellsPoints)
			.property("BaseVitality", &CharacterStatsRecord::getBaseVitality, &CharacterStatsRecord::setBaseVitality)
			.property("BaseWisdom", &CharacterStatsRecord::getBaseWisdom, &CharacterStatsRecord::setBaseWisdom)
			.property("BaseStrength", &CharacterStatsRecord::getBaseStrength, &CharacterStatsRecord::setBaseStrength)
			.property("BaseIntelligence", &CharacterStatsRecord::getBaseIntelligence, &CharacterStatsRecord::setBaseIntelligence)
			.property("BaseChance", &CharacterStatsRecord::getBaseChance, &CharacterStatsRecord::setBaseChance)
			.property("BaseAgility", &CharacterStatsRecord::getBaseAgility, &CharacterStatsRecord::setBaseAgility)
			.property("CurrentLife", &CharacterStatsRecord::getCurrentLife, &CharacterStatsRecord::setCurrentLife);

	}
	CharacterStatsRecord() { }

	int getCharacterId() { return this->CharacterId; }
	void setCharacterId(int var) { this->CharacterId = var; }

	int getStatsPoints() { return this->StatsPoints; }
	void setStatsPoints(int var) { this->StatsPoints = var; }

	int getSpellsPoints() { return this->SpellsPoints; }
	void setSpellsPoints(int var) { this->SpellsPoints = var; }

	int getBaseVitality() { return this->BaseVitality; }
	void setBaseVitality(int var) { this->BaseVitality = var; }

	int getBaseWisdom() { return this->BaseWisdom; }
	void setBaseWisdom(int var) { this->BaseWisdom = var; }

	int getBaseStrength() { return this->BaseStrength; }
	void setBaseStrength(int var) { this->BaseStrength = var; }

	int getBaseIntelligence() { return this->BaseIntelligence; }
	void setBaseIntelligence(int var) { this->BaseIntelligence = var; }

	int getBaseChance() { return this->BaseChance; }
	void setBaseChance(int var) { this->BaseChance = var; }

	int getBaseAgility() { return this->BaseAgility; }
	void setBaseAgility(int var) { this->BaseAgility = var; }

	int getCurrentLife() { return this->CurrentLife; }
	void setCurrentLife(int var) { this->CurrentLife = var; }



private:
	int CharacterId;
	int StatsPoints;
	int SpellsPoints;
	int BaseVitality;
	int BaseWisdom;
	int BaseStrength;
	int BaseIntelligence;
	int BaseChance;
	int BaseAgility;
	int CurrentLife;
};

CAMP_TYPE(CharacterStatsRecord)

#endif
