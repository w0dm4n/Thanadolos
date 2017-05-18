#pragma once
#ifndef MAPCOMPLEMENTARYINFORMATIONSDATAMESSAGE_THANADOLOS_HPP
#define MAPCOMPLEMENTARYINFORMATIONSDATAMESSAGE_THANADOLOS_HPP

#include "imessage.h"
#include "HouseInformations.hpp"
#include "GameRolePlayActorInformations.hpp"
#include "InteractiveElement.hpp"
#include "StatedElement.hpp"
#include "MapObstacle.hpp"
#include "FightCommonInformations.hpp"
#include "FightStartingPositions.hpp"

class MapComplementaryInformationsDataMessage : public IMessage
{
public:
	MapComplementaryInformationsDataMessage(int subAreaId, int mapId, std::vector<HouseInformations> houses, std::vector<GameRolePlayActorInformations*> actors, std::vector<InteractiveElement> interactiveElements, std::vector<StatedElement> statedElements, std::vector<MapObstacle> obstacles, std::vector<FightCommonInformations> fights, bool hasAggressiveMonsters, FightStartingPositions& fightStartPositions);
	MapComplementaryInformationsDataMessage();
	~MapComplementaryInformationsDataMessage();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 226;

	/*VARS*/
	int subAreaId;
	int mapId;
	std::vector<HouseInformations> houses;
	std::vector<GameRolePlayActorInformations*> actors;
	std::vector<InteractiveElement> interactiveElements;
	std::vector<StatedElement> statedElements;
	std::vector<MapObstacle> obstacles;
	std::vector<FightCommonInformations> fights;
	bool hasAggressiveMonsters;
	FightStartingPositions fightStartPositions;
};


#endif