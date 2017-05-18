#pragma once
#pragma comment(lib, "mysqlcppconn.lib")
#pragma comment(lib, "sqlapi.lib")
#pragma comment(lib, "campd.lib")
#include "IpcTicketAccountMessage.hpp"
#include "CharacterCreationRequestMessage.hpp"
#include "WorldClient.hpp"
#include "CustomVisitor.hpp"

class Database
{
public:
	Database(std::string host, std::string database, std::string user, std::string password);
	~Database();
	bool Database::initializeDatabase();
	camp::UserObject getAccount(std::string Account, std::string Password);
	SAConnection &getConnection();
	camp::UserObject buildAccount(IpcTicketAccountMessage ticketAccount);

	CustomVisitor getVisitor(std::string name);
	bool loadTables();
	bool characterNameAvailable(const char *name);

	bool createCharacter(CharacterCreationRequestMessage &data, WorldClient &client);
	bool createCharacterStats(camp::UserObject characterRecord, WorldClient &client);

	bool loadCharacters(WorldClient &client);
	int saveObject(camp::UserObject record);
	bool deleteCharacterRecordById(int id);
	bool deleteCharacterStatsRecordById(int id);

	bool deleteCharacter(camp::UserObject characterRecord, int vectorIndex, WorldClient &client);
	bool deleteCharacterStats(int characterId);

	camp::UserObject getBreedsRecord(int breedId);
	camp::UserObject getHeadsRecord(int id);
	camp::UserObject getMapsRecord(int id);
	camp::UserObject getMapsPosition(int id);
	camp::UserObject getMapsSubareas(int id);
	camp::UserObject getCharacterStats(int id);

	std::vector<camp::UserObject> _characters;
	std::vector<camp::UserObject> _characters_stats;
	std::vector<camp::UserObject> _heads;
	std::vector<camp::UserObject> _breeds;
	std::vector<camp::UserObject> _maps;
	std::vector<camp::UserObject> _maps_positions;
	std::vector<camp::UserObject> _maps_subareas;
	std::vector<camp::UserObject> _experiences;
	SAConnection db_con;

private:
	std::string host;
	std::string database;
	std::string user;
	std::string password;
	std::mutex m;
};