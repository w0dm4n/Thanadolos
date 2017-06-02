#include "Globals.h"
#include "CharactersManager.hpp"
#include "ApproachHandler.hpp"

std::string CharactersManager::generateName()
{
	const char prefix[][5] = {
		"",
		"bel",
		"nar",
		"xan",
		"bell",
		"natr",
		"ev",
	};

	const char suffix[][5] = {
		"", "us", "ix", "ox", "ith",
		"ath", "um", "ator", "or", "axia",
		"imus", "ais", "itur", "orex", "o",
		"y"
	};

	const char stems[][10] = {
		"adur", "aes", "anim", "apoll", "imac",
		"educ", "equis", "extr", "guius", "hann",
		"equi", "amora", "hum", "iace", "ille",
		"inept", "iuv", "obe", "ocul", "orbis"
	};

	std::string name = "";

	name += prefix[Utils::getRand(0, 7)];
	name += stems[Utils::getRand(0, 20)];
	name += suffix[Utils::getRand(0, 16)];
	name[0] = toupper(name[0]);
	// check if the name is not already used
	return name;
}

bool CharactersManager::isMyCharacter(int characterId, WorldClient &client)
{
	int i = 0;
	std::vector<camp::UserObject> characters = client.getCharacters();
	while (i < characters.size())
	{
		camp::UserObject characterRecord = characters[i];
		if (characterRecord.pointer() != NULL)
		{
			if ((int)characterRecord.get("Id") == characterId)
				return true;
		}
		i++;
	}
	return false;
}

int CharactersManager::getCharacterVectorPos(int id, std::vector<camp::UserObject> charactersRecord)
{
	int i = 0;
	while (i < charactersRecord.size())
	{
		camp::UserObject characterRecord = charactersRecord[i];
		if (characterRecord.pointer() != NULL)
		{
			if ((int)characterRecord.get("Id") == id)
				return i;
		}
		i++;
	}
	return (-1);
}

camp::UserObject CharactersManager::getCharacterRecordFromIndex(int index, std::vector<camp::UserObject> charactersRecord)
{
	int i = 0;
	while (i < charactersRecord.size())
	{
		if (i == index)
			return charactersRecord[i];
		i++;
	}
	camp::UserObject empty;
	return empty;
}

bool CharactersManager::removeCharacter(int characterId, WorldClient &client)
{
	bool result = false;
	std::vector<camp::UserObject> characters = client.getCharacters();
	int index = CharactersManager::getCharacterVectorPos(characterId, characters);
	if (index != -1)
	{
		result = client.getWorld()->getDatabase()->deleteCharacter(CharactersManager::getCharacterRecordFromIndex(index, characters), index, client);
		if (result)
		{
			ApproachHandler::sendCharactersList(client);
		}
	}
	return result;
}

uint CharactersManager::getDefaultLook(camp::UserObject breedRecord, camp::UserObject characterRecord)
{
	bool sex = characterRecord.get("Sex");
	std::string look = (sex) ? breedRecord.get("femaleLook") : breedRecord.get("maleLook");
	Split data = Utils::split(look, '|');
	return (data.size() >= 2) ? std::stoi(data[1]) : 0;
}

uint CharactersManager::getCosmeticHead(WorldClient &client, camp::UserObject characterRecord)
{
	camp::UserObject headRecord = client.getWorld()->getDatabase()->getRecordObject(characterRecord.get("CosmeticId"), "HeadsRecord");
	return (headRecord.pointer() != NULL) ? headRecord.get("skins") : 0;
}

uint CharactersManager::getScaleLook(camp::UserObject breedRecord, camp::UserObject characterRecord)
{
	bool sex = characterRecord.get("Sex");
	std::string look = (sex) ? breedRecord.get("femaleLook") : breedRecord.get("maleLook");
	Split data = Utils::split(look, '|');
	return (data.size() >= 4) ? std::stoi(data[3]) : 0;
}

long long int CharactersManager::getCharacterExperience(WorldClient &client)
{
	std::string experience = client.character->getCharacterRecord().get("Experience");
	return std::stoll(experience);
}

long long int CharactersManager::castToLongLong(std::string value)
{
	return std::stoll(value);
}

camp::UserObject CharactersManager::getExperienceLevel(WorldClient &client)
{
	std::vector<camp::UserObject> levels = client.getWorld()->getDatabase()->_experiences;
	long long int characterExperience = CharactersManager::getCharacterExperience(client);
	int i = 0;
	long long int palierXp = 0;
	long long int nextPalier = 0;
	while (i < levels.size())
	{
		palierXp = CharactersManager::castToLongLong(levels[i].get("Xp"));
		if ((i + 1) < levels.size())
		{
			nextPalier = CharactersManager::castToLongLong(levels[(i + 1)].get("Xp"));
			if (characterExperience >= palierXp && characterExperience < nextPalier)
				return levels[i];
		}
		else
			return levels[i];
		i++;
	}
	camp::UserObject empty;
	return empty;
}

camp::UserObject CharactersManager::getExperienceLevelNext(WorldClient &client)
{
	std::vector<camp::UserObject> levels = client.getWorld()->getDatabase()->_experiences;
	long long int characterExperience = CharactersManager::getCharacterExperience(client);
	int i = 0;
	long long int palierXp = 0;
	long long int nextPalier = 0;
	while (i < levels.size())
	{
		palierXp = CharactersManager::castToLongLong(levels[i].get("Xp"));
		if ((i + 1) < levels.size())
		{
			nextPalier = CharactersManager::castToLongLong(levels[(i + 1)].get("Xp"));
			if (characterExperience >= palierXp && characterExperience < nextPalier)
				return levels[i + 1];
		}
		else
			return levels[i];
		i++;
	}
	camp::UserObject empty;
	return empty;
}


int CharactersManager::getStatsCostFromValue(int statValue, std::string value)
{
	Split data = Utils::split(value, ',');
	bool isValue = false;
	int i = data.size() - 1;
	while (i > 0)
	{
		if (!isValue)
			isValue = true;
		else
		{
			if (statValue >= std::stoi(data[i]))
				return std::stoi(data[(i + 1)]);
			isValue = false;
		}
		i--;
	}
	return 1;
}


int CharactersManager::getStatsCost(int statId, WorldClient &client)
{
	camp::UserObject breedRecord = client.getWorld()->getDatabase()->getRecordObject(client.character->getCharacterRecord().get("Breed"), "BreedsRecord");
	switch (statId)
	{
		case StatsBoostTypeEnum::Vitality:
			return 1;
		break;

		case StatsBoostTypeEnum::Strength:
			return getStatsCostFromValue(client.character->getStats().getBaseStrength(), breedRecord.get("statsPointsForStrength"));
		break;

		case StatsBoostTypeEnum::Agility:
			return getStatsCostFromValue(client.character->getStats().getBaseAgility(), breedRecord.get("statsPointsForAgility"));
		break;

		case StatsBoostTypeEnum::Intelligence:
			return getStatsCostFromValue(client.character->getStats().getBaseIntelligence(), breedRecord.get("statsPointsForIntelligence"));
		break;

		case StatsBoostTypeEnum::Wisdom:
			return getStatsCostFromValue(client.character->getStats().getBaseWisdom(), breedRecord.get("statsPointsForWisdom"));
		break;

		case StatsBoostTypeEnum::Chance:
			return getStatsCostFromValue(client.character->getStats().getBaseChance(), breedRecord.get("statsPointsForChance"));
		break;

		default:
			return -1;
		break;
	}
}

std::vector<int> CharactersManager::getBreedSpells(int breedId, Database *database)
{
	std::vector<int> spells;

	camp::UserObject breed = database->getRecordObject(breedId, "BreedsRecord");
	std::string breedSpells = breed.get("breedSpellsId");
	Split spells_database = Utils::split(breedSpells, ',');
	for (int i = 0; i < spells_database.size(); i++)
		spells.push_back(std::stoi(spells_database[i]));
	return spells;
}