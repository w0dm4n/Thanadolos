#ifndef CHARACTERS_MANAGER_HPP
# define CHARACTERS_MANAGER_HPP

#include <iostream>
#include "Logger.hpp"
#include "Utils.hpp"
#include "Database.hpp"
#include <algorithm>
#include "Utils.hpp"
#include "StatsBoostTypeEnum.hpp"
#include "StatsUpgradeResultEnum.hpp"

class CharactersManager
{
public:
	static std::string generateName();
	static bool isMyCharacter(int characterId, WorldClient &client);
	static int getCharacterVectorPos(int id, std::vector<camp::UserObject> charactersRecord);
	static camp::UserObject getCharacterRecordFromIndex(int index, std::vector<camp::UserObject> charactersRecord);
	static bool removeCharacter(int characterId, WorldClient &client);
	static uint getCosmeticHead(WorldClient &client, camp::UserObject characterRecord);
	static uint getDefaultLook(camp::UserObject breedRecord, camp::UserObject characterRecord);
	static uint getScaleLook(camp::UserObject breedRecord, camp::UserObject characterRecord);
	static long long int castToLongLong(std::string value);
	static long long int getCharacterExperience(WorldClient &client);
	static camp::UserObject getExperienceLevel(WorldClient &client);
	static camp::UserObject getExperienceLevelNext(WorldClient &client);
	static int getStatsCostFromValue(int statValue, std::string data);
	static int getStatsCost(int statId, WorldClient &client);
	static std::vector<int> getBreedSpells(int breedId, Database *database);
};

#endif
