#include "Globals.h"
#include "Stats.hpp"
#include "Character.hpp"

Stats::Stats(Character *character) : character(character)
{
	this->loadRecord();
}

void Stats::loadRecord()
{
	this->statsRecord = this->character->getClient().getWorld()->getDatabase()->getCharacterStats(this->character->getCharacterRecord().get("Id"));
	if (this->statsRecord.pointer() == NULL)
	{
		Logger::Error("An error occured while trying to fetch stats for a character");
		this->character->getClient().disconnect();
	}
}

int Stats::getBaseLife()
{
	return (42 + (5 * (int) this->character->getCharacterRecord().get("Level") - 5));
}

int Stats::getCurrentLife()
{
	return (int) this->statsRecord.get("CurrentLife") > this->getMaxLife() ? this->getMaxLife() : this->statsRecord.get("CurrentLife");
}

int Stats::getMaxLife()
{
	return this->getBaseLife() + this->getBaseVitality(); // + item effect id vitality
}

int Stats::getItemsAP()
{
	return 0; // + item effect id AP
}

int Stats::getBaseAP()
{
	return ((int)this->character->getCharacterRecord().get("Level") >= 100 ? 7 : 6);
}

int Stats::getBaseMP()
{
	return 3;
}

int Stats::getItemsMP()
{
	return 0; // + item effect id MP
}

int Stats::getCurrentAP()
{
	int AP = this->getBaseAP() + this->getItemsAP();
	int MAX_AP = std::stoi(this->character->getClient().getWorld()->getConfig()->getData("MAX_AP"));
	return (AP > MAX_AP) ? MAX_AP : AP;
}

int Stats::getCurrentMP()
{
	int MP = this->getBaseMP() + this->getItemsMP(); 
	int MAX_MP = std::stoi(this->character->getClient().getWorld()->getConfig()->getData("MAX_MP"));
	return (MP > MAX_MP) ? MAX_MP : MP;
}

int Stats::getBaseInitiative()
{
	int baseInitiative = (int) this->statsRecord.get("BaseStrength")
		+ (int) this->statsRecord.get("BaseIntelligence") + (int) this->statsRecord.get("BaseChance")
		+ (int) this->statsRecord.get("BaseAgility");
	return baseInitiative;
}

int Stats::getItemsInitiative()
{
	return 0; // item effect id initiative
}

int Stats::getTotalInitiative()
{
	return this->getBaseInitiative() + this->getItemsInitiative();
}

CharacterBaseCharacteristic Stats::getCharacteristicInitiative()
{
	int baseInitiative = this->getBaseInitiative();
	int itemsInitiative = this->getItemsInitiative(); 

	int total = (baseInitiative + itemsInitiative) * (this->getCurrentLife() / this->getMaxLife());
	return CharacterBaseCharacteristic(baseInitiative, itemsInitiative, 0, 0, 0);
}

int Stats::getBasePP()
{
	int base = 100;
	int chance = this->statsRecord.get("BaseChance");
	chance = (chance > 0) ? (chance / 10) : chance;
	return (chance > 0) ? (base + chance) : base;
}

int Stats::getItemsPP()
{
	int chance = 0; // item effect id chance
	chance = (chance > 0) ? (chance / 10) : chance;
	return (chance > 0) ? (chance) : 0;
}

int Stats::getTotalPP()
{
	return this->getBasePP() + this->getItemsPP();
}

int Stats::getBaseStrength()
{
	return this->statsRecord.get("BaseStrength");
}

int Stats::getItemsStrength()
{
	return 0; // item effect id strength
}

int	Stats::getTotalStrength()
{
	return this->getBaseStrength() + this->getItemsStrength();
}

int Stats::getBaseVitality()
{
	return this->statsRecord.get("BaseVitality");
}

int Stats::getItemsVitality()
{
	return 0; // item effect id vitality
}

int	Stats::getTotalVitality()
{
	return this->getBaseVitality() + this->getItemsVitality();
}

int Stats::getBaseWisdom()
{
	return this->statsRecord.get("BaseWisdom");
}

int Stats::getItemsWisdom()
{
	return 0; // item effect id wisdom
}

int	Stats::getTotalWisdom()
{
	return this->getBaseWisdom() + this->getItemsWisdom();
}

int Stats::getBaseChance()
{
	return this->statsRecord.get("BaseChance");
}

int Stats::getItemsChance()
{
	return 0; // item effect id chance
}

int	Stats::getTotalChance()
{
	return this->getBaseChance() + this->getItemsChance();
}

int Stats::getBaseAgility()
{
	return this->statsRecord.get("BaseAgility");
}

int Stats::getItemsAgility()
{
	return 0; // item effect id agility
}

int	Stats::getTotalAgility()
{
	return this->getBaseAgility() + this->getItemsAgility();
}

int Stats::getBaseIntelligence()
{
	return this->statsRecord.get("BaseIntelligence");
}

int Stats::getItemsIntelligence()
{
	return 0; // item effect id intelligence
}

int	Stats::getTotalIntelligence()
{
	return this->getBaseIntelligence() + this->getItemsIntelligence();
}

int Stats::getSpellsPoints()
{
	return this->statsRecord.get("SpellsPoints");
}

CharacterBaseCharacteristic Stats::getCharacteristicPP()
{
	return CharacterBaseCharacteristic(this->getBasePP(), this->getItemsPP(), 0, 0, 0);
}

CharacterBaseCharacteristic Stats::getCharacteristicAP()
{
	return CharacterBaseCharacteristic(this->getBaseAP(), this->getItemsAP(), 0, 0, 0);
}

CharacterBaseCharacteristic Stats::getCharacteristicMP()
{
	return CharacterBaseCharacteristic(this->getBaseMP(), this->getItemsMP(), 0, 0, 0);
}

CharacterBaseCharacteristic Stats::getCharacteristicStrength()
{
	return CharacterBaseCharacteristic(this->getBaseStrength(), this->getItemsStrength(), 0, 0, 0);
}

CharacterBaseCharacteristic Stats::getCharacteristicVitality()
{
	return CharacterBaseCharacteristic(this->getBaseVitality(), this->getItemsVitality(), 0, 0, 0);
}

CharacterBaseCharacteristic Stats::getCharacteristicWisdom()
{
	return CharacterBaseCharacteristic(this->getBaseWisdom(), this->getItemsWisdom(), 0, 0, 0);
}

CharacterBaseCharacteristic Stats::getCharacteristicChance()
{
	return CharacterBaseCharacteristic(this->getBaseChance(), this->getItemsChance(), 0, 0, 0);
}

CharacterBaseCharacteristic Stats::getCharacteristicAgility()
{
	return CharacterBaseCharacteristic(this->getBaseAgility(), this->getItemsAgility(), 0, 0, 0);
}

CharacterBaseCharacteristic Stats::getCharacteristicIntelligence()
{
	return CharacterBaseCharacteristic(this->getBaseIntelligence(), this->getItemsIntelligence(), 0, 0, 0);
}

camp::UserObject Stats::getStatsRecord()
{
	return this->statsRecord;
}

int Stats::getEnergy()
{
	return 10000; // TODO
}

void Stats::increaseBaseStats(int statId)
{
	switch (statId)
	{
		case StatsBoostTypeEnum::Vitality:
			this->statsRecord.set("BaseVitality", (int) this->statsRecord.get("BaseVitality") + 1);
			break;

		case StatsBoostTypeEnum::Strength:
			this->statsRecord.set("BaseStrength", (int) this->statsRecord.get("BaseStrength") + 1);
			break;

		case StatsBoostTypeEnum::Agility:
			this->statsRecord.set("BaseAgility", (int) this->statsRecord.get("BaseAgility") + 1);
			break;

		case StatsBoostTypeEnum::Intelligence:
			this->statsRecord.set("BaseIntelligence", (int) this->statsRecord.get("BaseIntelligence") + 1);
			break;

		case StatsBoostTypeEnum::Wisdom:
			this->statsRecord.set("BaseWisdom", (int) this->statsRecord.get("BaseWisdom") + 1);
			break;

		case StatsBoostTypeEnum::Chance:
			this->statsRecord.set("BaseChance", (int) this->statsRecord.get("BaseChance") + 1);
			break;
	}
}

void Stats::decreaseStatsPoints(int value)
{
	this->statsRecord.set("StatsPoints", ((int) this->statsRecord.get("StatsPoints") - value));
}

void Stats::increaseSpellsPoints(int value)
{
	this->statsRecord.set("SpellsPoints", ((int) this->statsRecord.get("SpellsPoints") + value));
}

void Stats::decreaseSpellsPoints(int value)
{
	this->statsRecord.set("SpellsPoints", ((int) this->statsRecord.get("SpellsPoints") - value));
}

void Stats::updateCurrentLife(int lifePoints)
{
	if (lifePoints >= this->getMaxLife())
	{
		this->statsRecord.set("CurrentLife", this->getMaxLife());
	}
	else
	{
		this->statsRecord.set("CurrentLife", lifePoints);
	}
}