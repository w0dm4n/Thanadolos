#pragma once
#ifndef MAP_HPP
# define MAP_HPP

#include "Database.hpp"
#include "Logger.hpp"

#define _WINSOCK2API_
#include "Database.hpp"

#define _WS2IPDEF_
#define _WS2TCPIP_H_
#include "WorldClient.hpp"
#include "MapComplementaryInformationsDataMessage.hpp"
#include "CurrentMapMessage.hpp"
#include "GameContextRemoveElementMessage.hpp"
#include "GameRolePlayShowActorMessage.hpp"

class Map
{
public:
	static const std::string DECRYPT_KEY;
	Map(int mapId, Database *db);
	void loadRecord(int mapId);
	MapComplementaryInformationsDataMessage getMapComplementaryInformationsDataMessage();
	std::vector<GameRolePlayActorInformations*> getActors();
	void enterMap(WorldClient &client);
	void leaveMap(WorldClient &client);
	bool removeClient(WorldClient &client);
	void sendMap(IMessage &message);
	camp::UserObject getMapRecord();
private:
	camp::UserObject mapRecord;
	camp::UserObject mapSubareaRecord;
	camp::UserObject mapPositionRecord;
	Database *db;
	std::vector<WorldClient*> clients;
	std::mutex m;
};

#endif