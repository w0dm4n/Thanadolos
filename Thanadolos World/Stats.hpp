#pragma once

#ifndef STATS_HPP
# define STATS_HPP

#include "Database.hpp"
#include "Logger.hpp"
#include "Database.hpp"
#include "CharacterBaseInformations.hpp"
#include "EntityLook.hpp"
#include "SubEntity.hpp"
#include "GameRolePlayCharacterInformations.hpp"
#include "CharacterCharacteristicsInformations.hpp"
#include "ActorExtendedAlignmentInformations.hpp"
#include "CharacterSpellModification.hpp"
#include "World.hpp"
#include "Map.hpp"
#include "CharactersManager.hpp"
#include "StatsBoostTypeEnum.hpp"

class Character;

class Stats
{
public:
	Stats(Character *character);
	int							getBaseLife();
	int							getBaseAP();
	int							getItemsAP();
	int							getBaseMP();
	int							getItemsMP();
	int							getBaseInitiative();
	int							getItemsInitiative();
	int							getTotalInitiative();
	int							getBasePP();
	int							getItemsPP();
	int							getTotalPP();
	int							getEnergy();
	int							getBaseStrength();
	int							getItemsStrength();
	int							getTotalStrength();
	int							getBaseVitality();
	int							getItemsVitality();
	int							getTotalVitality();
	int							getBaseWisdom();
	int							getItemsWisdom();
	int							getTotalWisdom();
	int							getBaseChance();
	int							getItemsChance();
	int							getTotalChance();
	int							getBaseAgility();
	int							getItemsAgility();
	int							getTotalAgility();
	int							getBaseIntelligence();
	int							getItemsIntelligence();
	int							getTotalIntelligence();
	int							getSpellsPoints();
	void						increaseBaseStats(int statId);
	void						decreaseStatsPoints(int value);
	void						increaseSpellsPoints(int value);
	void						decreaseSpellsPoints(int value);
	void						updateCurrentLife(int lifePoints);

	int getCurrentLife();
	int getMaxLife();

	int getCurrentAP();
	int getCurrentMP();
	void loadRecord();
	CharacterBaseCharacteristic getCharacteristicInitiative();
	CharacterBaseCharacteristic getCharacteristicPP();
	CharacterBaseCharacteristic getCharacteristicAP();
	CharacterBaseCharacteristic getCharacteristicMP();
	CharacterBaseCharacteristic getCharacteristicStrength();
	CharacterBaseCharacteristic getCharacteristicVitality();
	CharacterBaseCharacteristic getCharacteristicWisdom();
	CharacterBaseCharacteristic getCharacteristicChance();
	CharacterBaseCharacteristic getCharacteristicAgility();
	CharacterBaseCharacteristic getCharacteristicIntelligence();
	camp::UserObject			getStatsRecord();
private:
	Character *character;
	camp::UserObject statsRecord;
};

#endif