#ifndef GAME_HANDLER_HPP
# define GAME_HANDLER_HPP
#include "WorldClient.hpp"
#include "World.hpp"
#include "IPC.hpp"

#include "GameContextCreateMessage.hpp"
#include "GameContextCreateRequestMessage.hpp"
#include "GameContextCreateErrorMessage.hpp"
#include "GameContextDestroyMessage.hpp"
#include "CurrentMapMessage.hpp"
#include "MapComplementaryInformationsDataMessage.hpp"
#include "FightStartingPositions.hpp"
#include "GameMapMovementRequestMessage.hpp"
#include "GameMapMovementMessage.hpp"
#include "ChangeMapMessage.hpp"
#include "DirectionsEnum.hpp"
#include "CharacterStatsListMessage.hpp"
#include "UpdateLifePointsMessage.hpp"
#include "StatsUpgradeRequestMessage.hpp"
#include "StatsUpgradeResultMessage.hpp"
#include "StatsBoostTypeEnum.hpp"
#include "StatsUpgradeResultEnum.hpp"

#include "Character.hpp"
#include "CharactersManager.hpp"
#include "Map.hpp"
#include "GameRolePlayShowActorMessage.hpp"

class GameHandler
{
public:
	static void GameContextCreateRequestMessageHandler(BinaryReader &reader, WorldClient &client);
	static void MapComplementaryInformationsDataMessageHandler(BinaryReader &reader, WorldClient &client);
	static void GameMapMovementRequestMessageHandler(BinaryReader &reader, WorldClient &client);
	static void ChangeMapMessageHandler(BinaryReader &reader, WorldClient &client);
	static void StatsUpgradeRequestMessageHandler(BinaryReader &reader, WorldClient &client);
	static void sendWelcomeMessage(WorldClient &client);
};


#endif