#include "Globals.h"
#include "Map.hpp"
#include "MapsManager.hpp"
#include "World.hpp"
#include "Config.hpp"
#include "Character.hpp"

const std::string Map::DECRYPT_KEY = "649ae451ca33ec53bbcbcc33becf15f4";

Map::Map(int mapId, Database *db) : db(db)
{
	this->loadRecord(mapId);
}

void Map::loadRecord(int mapId)
{
	this->mapRecord = db->getMapsRecord(mapId);
	this->mapPositionRecord = db->getMapsPosition(mapId);
	this->mapSubareaRecord = db->getMapsSubareas(this->mapRecord.get("subareaId"));
}

void	Map::enterMap(WorldClient &client)
{
	if (this->mapRecord.pointer() != NULL)
	{
		this->sendMap(GameRolePlayShowActorMessage(client.character->getGameRolePlayCharacterInformations()));
		this->clients.push_back(&client);
		client.character->setMap(this);
		client.sendMessage(CurrentMapMessage(this->mapRecord.get("id"), Map::DECRYPT_KEY));
	}
	else
	{
		Logger::Error("A character is trying to enter on an invalid map, teleported to start map !");
		client.getWorld()->teleportClient(std::stoi(client.getWorld()->getConfig()->getData("START_MAP")),
			std::stoi(client.getWorld()->getConfig()->getData("START_CELL")), client);
	}
}

bool Map::removeClient(WorldClient &client)
{
	int i = 0;
	std::lock_guard<std::mutex> locker(this->m);

	while (i < this->clients.size())
	{
		if (this->clients[i] == &client)
		{
			this->clients.erase(this->clients.begin() + i);
			return true;
		}
		i++;
	}
	return false;
}

void	Map::leaveMap(WorldClient &client)
{
	if (this->removeClient(client))
		this->sendMap(GameContextRemoveElementMessage((int)client.character->getCharacterRecord().get("Id")));
}

std::vector<GameRolePlayActorInformations*> Map::getActors()
{
	std::vector<GameRolePlayActorInformations*> actors;

	int i = 0;
	while (i < this->clients.size())
		actors.push_back(this->clients[i++]->character->getGameRolePlayCharacterInformations());
	return actors;
}

void Map::sendMap(IMessage &message)
{
	int i = 0;
	while (i < this->clients.size())
		this->clients[i++]->sendMessage(message);
}


MapComplementaryInformationsDataMessage Map::getMapComplementaryInformationsDataMessage()
{
	std::vector<HouseInformations> houses;
	std::vector<InteractiveElement> interactiveElements;
	std::vector<StatedElement> statedElements;
	std::vector<MapObstacle> obstacles;
	std::vector<FightCommonInformations> fights;
	FightStartingPositions positions;

	return MapComplementaryInformationsDataMessage(this->mapSubareaRecord.get("id"), this->mapRecord.get("id"), houses, this->getActors(), interactiveElements, statedElements, obstacles, fights, false, positions);
}

camp::UserObject Map::getMapRecord()
{
	return this->mapRecord;
}