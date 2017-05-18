#include "Globals.h"
#include "Character.hpp"

Character::Character(camp::UserObject characterRecord, camp::UserObject accountRecord, WorldClient &client)
	: characterRecord(characterRecord), accountRecord(accountRecord), client(client), stats(this)
{
	this->loadDatas();
	this->direction = 1;
	this->regenTimestamp = 0;
}

bool Character::isFirstContext()
{
	return this->firstContext;
}

void Character::setFirstContext(bool context)
{
	this->firstContext = context;
}

void Character::loadDatas()
{
	this->getSkinsBase();
	this->map = NULL;
}

CharacterBaseInformations Character::getCharacterBaseInformations()
{
	CharacterBaseInformations baseInformations(this->characterRecord.get("Id"), characterRecord.get("Name"),
		characterRecord.get("Level"), this->getEntityLook(), this->characterRecord.get("Breed"), this->characterRecord.get("Sex"));
	return baseInformations;
}

ActorRestrictionsInformations Character::getRestrictions()
{
	ActorRestrictionsInformations restrictions(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
	return restrictions;
}

std::vector<HumanOption> Character::getHumanOptions()
{
	std::vector<HumanOption> options;
	return options;
}

HumanInformations Character::getHumanInformations()
{
	return HumanInformations(this->getRestrictions(), this->characterRecord.get("Sex"), this->getHumanOptions());
}

ActorAlignmentInformations Character::getActorAlignmentInformations()
{
	return ActorAlignmentInformations(0, 0, 0, ((int) this->getCharacterRecord().get("Id") + (int) this->getCharacterRecord().get("Level")));
}

GameRolePlayCharacterInformations *Character::getGameRolePlayCharacterInformations()
{
	EntityDispositionInformations disposition(this->getCharacterRecord().get("CellId"), this->direction);

	GameRolePlayCharacterInformations *characterInformations = new GameRolePlayCharacterInformations(this->characterRecord.get("Id"), this->getEntityLook(), disposition, this->characterRecord.get("Name"),
		this->getHumanInformations(), this->accountRecord.get("id"), this->getActorAlignmentInformations());
	return characterInformations;
}

void Character::getSkinsBase()
{
	camp::UserObject breedRecord = client.getWorld()->getDatabase()->getBreedsRecord(this->characterRecord.get("Breed"));
	if (breedRecord.pointer() != NULL)
	{
		this->defaultLook = CharactersManager::getDefaultLook(breedRecord, characterRecord);
		this->headLook = CharactersManager::getCosmeticHead(client, characterRecord);
		this->scaleLook = CharactersManager::getScaleLook(breedRecord, characterRecord);
	}
	else
	{
		Logger::Error("Can't find breedRecord from character breed id !");
		client.disconnect();
	}
}

void Character::onDisconnect()
{
	if (this->map != NULL)
		this->map->leaveMap(this->client);
	this->stopRegenLife(false);
}

Character::~Character()
{
	this->onDisconnect();
}

camp::UserObject		Character::getAccountRecord()
{
	return this->accountRecord;
}

camp::UserObject		Character::getCharacterRecord()
{
	return this->characterRecord;
}

void					Character::updateLevel(int level)
{
	this->characterRecord.set("Level", level);
}

void Character::refreshEntityLook()
{
	this->skins.clear();

	this->skins.push_back(this->defaultLook); // base skin
	this->skins.push_back(this->headLook); // head skin
	// stuff
}

int	Character::getBonesId()
{
	// mount == 2
	return 1;
}

std::vector<SubEntity> Character::getSubEntities()
{
	std::vector<SubEntity> empty;
	/*std::vector<SubEntity> subEntities;

	EntityLook *look = new EntityLook(2, this->skins, this->getColors(), this->getScales(), empty);

	subEntities.push_back(SubEntity(2, 0, look));
	*/
	// famillier ect
	return empty;
}

std::vector<uint>  Character::getSkins()
{
	return this->skins;
}

std::vector<int> Character::getColors()
{
	std::vector<int> colors;
	colors.push_back(this->characterRecord.get("Colors_0"));
	colors.push_back(this->characterRecord.get("Colors_1"));
	colors.push_back(this->characterRecord.get("Colors_2"));
	colors.push_back(this->characterRecord.get("Colors_3"));
	colors.push_back(this->characterRecord.get("Colors_4"));

	std::vector<int> nextColors;
	for (int i = 0; i < colors.size(); i++)
		nextColors.push_back(i + 1 << 24 | colors[i] & 16777215);

	return nextColors;
}

std::vector<int> Character::getScales()
{
	std::vector<int> scales;
	scales.push_back(this->scaleLook);
	return scales;
}

EntityLook Character::getEntityLook()
{
	this->refreshEntityLook();
	return EntityLook(this->getBonesId(), this->getSkins(), this->getColors(), this->getScales(), this->getSubEntities());
}

void Character::startRegenLife(bool sendMessage)
{
	if (this->regenTimestamp > 0)
		this->stopRegenLife(false);
	if (this->stats.getCurrentLife() < this->stats.getMaxLife())
	{
		this->regenTimestamp = Utils::getUnixTimestamp();
		if (sendMessage)
			client.sendMessage(LifePointsRegenBeginMessage(10));
	}
}

void Character::stopRegenLife(bool sendMessage)
{
	if (this->regenTimestamp > 0)
	{
		long int lifePointsWon = (Utils::getUnixTimestamp() - this->regenTimestamp);
		this->stats.updateCurrentLife(this->stats.getCurrentLife() + lifePointsWon);
		this->regenTimestamp = 0;
		if (sendMessage)
			client.sendMessage(LifePointsRegenEndMessage(this->stats.getCurrentLife(), this->stats.getMaxLife(), lifePointsWon));
	}
}

void Character::onConnected()
{
	this->startRegenLife();
	GameHandler::sendWelcomeMessage(this->client);
	// Friends ..
}

Map	*Character::getMap()
{
	return this->map;
}

void Character::setMap(Map *map)
{
	this->map = map;
}

void Character::updatePosition(int mapId, int cellId)
{
	this->characterRecord.set("MapId", mapId);
	this->characterRecord.set("CellId", cellId);
}

void Character::updateDirection(int direction)
{
	this->direction = direction;
}

int Character::getDirection()
{
	return this->direction;
}

WorldClient				&Character::getClient()
{
	return this->client;
}

ActorExtendedAlignmentInformations Character::getActorExtendedAlignmentInformations()
{
	return ActorExtendedAlignmentInformations(0, 0, 0, 0, 0, 0, 0, 0);
}

std::vector<CharacterSpellModification>					Character::getCharacterSpellModification()
{
	std::vector<CharacterSpellModification> modifications;
	return modifications;
}

void Character::sendStats()
{
	this->client.sendMessage(CharacterStatsListMessage(this->getCharacterCharacteristicsInformations()));
}

CharacterCharacteristicsInformations Character::getCharacterCharacteristicsInformations()
{
	return CharacterCharacteristicsInformations(
		CharactersManager::getCharacterExperience(client),
		CharactersManager::getExperienceLevel(this->client).get("Xp"),
		CharactersManager::getExperienceLevelNext(this->client).get("Xp"),
		0,
		this->characterRecord.get("Kamas"),
		this->stats.getStatsRecord().get("StatsPoints"),
		0, // Parchemin stats
		this->stats.getStatsRecord().get("SpellsPoints"),
		this->getActorExtendedAlignmentInformations(),
		this->stats.getCurrentLife(),
		this->stats.getMaxLife(),
		this->stats.getEnergy(),
		this->stats.getEnergy(),
		this->stats.getCurrentAP(),
		this->stats.getCurrentMP(),
		this->stats.getCharacteristicInitiative(),
		this->stats.getCharacteristicPP(),
		this->stats.getCharacteristicAP(),
		this->stats.getCharacteristicMP(),
		this->stats.getCharacteristicStrength(),
		this->stats.getCharacteristicVitality(),
		this->stats.getCharacteristicWisdom(),
		this->stats.getCharacteristicChance(),
		this->stats.getCharacteristicAgility(),
		this->stats.getCharacteristicIntelligence(),
		CharacterBaseCharacteristic(1, 0, 0, 0, 0),
		CharacterBaseCharacteristic(1, 0, 0, 0, 0),
		CharacterBaseCharacteristic(0, 0, 0, 0, 0),
		CharacterBaseCharacteristic(0, 0, 0, 0, 0),
		0,
		CharacterBaseCharacteristic(0, 0, 0, 0, 0),
		CharacterBaseCharacteristic(0, 0, 0, 0, 0),
		CharacterBaseCharacteristic(0, 0, 0, 0, 0),
		CharacterBaseCharacteristic(0, 0, 0, 0, 0),
		CharacterBaseCharacteristic(0, 0, 0, 0, 0),
		CharacterBaseCharacteristic(0, 0, 0, 0, 0),
		CharacterBaseCharacteristic(0, 0, 0, 0, 0),
		CharacterBaseCharacteristic(0, 0, 0, 0, 0),
		CharacterBaseCharacteristic(0, 0, 0, 0, 0),
		CharacterBaseCharacteristic(0, 0, 0, 0, 0),
		CharacterBaseCharacteristic(0, 0, 0, 0, 0),
		CharacterBaseCharacteristic(0, 0, 0, 0, 0),
		CharacterBaseCharacteristic(0, 0, 0, 0, 0),
		CharacterBaseCharacteristic(0, 0, 0, 0, 0),
		CharacterBaseCharacteristic(0, 0, 0, 0, 0),
		CharacterBaseCharacteristic(0, 0, 0, 0, 0),
		CharacterBaseCharacteristic(0, 0, 0, 0, 0),
		CharacterBaseCharacteristic(0, 0, 0, 0, 0),
		CharacterBaseCharacteristic(0, 0, 0, 0, 0),
		CharacterBaseCharacteristic(0, 0, 0, 0, 0),
		CharacterBaseCharacteristic(0, 0, 0, 0, 0),
		CharacterBaseCharacteristic(0, 0, 0, 0, 0),
		CharacterBaseCharacteristic(0, 0, 0, 0, 0),
		CharacterBaseCharacteristic(0, 0, 0, 0, 0),
		CharacterBaseCharacteristic(0, 0, 0, 0, 0),
		CharacterBaseCharacteristic(0, 0, 0, 0, 0),
		CharacterBaseCharacteristic(0, 0, 0, 0, 0),
		CharacterBaseCharacteristic(0, 0, 0, 0, 0),
		CharacterBaseCharacteristic(0, 0, 0, 0, 0),
		CharacterBaseCharacteristic(0, 0, 0, 0, 0),
		CharacterBaseCharacteristic(0, 0, 0, 0, 0),
		CharacterBaseCharacteristic(0, 0, 0, 0, 0),
		CharacterBaseCharacteristic(0, 0, 0, 0, 0),
		CharacterBaseCharacteristic(0, 0, 0, 0, 0),
		CharacterBaseCharacteristic(0, 0, 0, 0, 0),
		CharacterBaseCharacteristic(0, 0, 0, 0, 0),
		CharacterBaseCharacteristic(0, 0, 0, 0, 0),
		CharacterBaseCharacteristic(0, 0, 0, 0, 0),
		CharacterBaseCharacteristic(0, 0, 0, 0, 0),
		CharacterBaseCharacteristic(0, 0, 0, 0, 0),
		CharacterBaseCharacteristic(0, 0, 0, 0, 0),
		CharacterBaseCharacteristic(0, 0, 0, 0, 0),
		CharacterBaseCharacteristic(0, 0, 0, 0, 0),
		CharacterBaseCharacteristic(0, 0, 0, 0, 0),
		CharacterBaseCharacteristic(0, 0, 0, 0, 0),
		this->getCharacterSpellModification(),
		0);
}

Stats &Character::getStats()
{
	return this->stats;
}

void Character::replyLangsMessage(int typeId, int id, std::vector<std::string> params)
{
	this->client.sendMessage(TextInformationMessage(typeId, id, params));
}

void Character::replyText(std::string message)
{
	std::vector<std::string> params;
	params.push_back(message);

	this->replyLangsMessage(0, 0, params);
}

void Character::replyError(std::string message)
{
	std::vector<std::string> params;
	std::string content = "<font color=\"#ff0000\">" + message + "</font>";
	params.push_back(content);

	this->replyLangsMessage(0, 0, params);
}