#pragma once
#pragma comment(lib, "mysqlcppconn.lib")
#pragma comment(lib, "sqlapi.lib")
#pragma comment(lib, "campd.lib")
#include "IpcTicketAccountMessage.hpp"
#include "CharacterCreationRequestMessage.hpp"
#include "WorldClient.hpp"
#include "CustomVisitor.hpp"
#include "CharactersManager.hpp"

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
	bool createCharacterSpells(std::vector<int> breedSpells, camp::UserObject character);
	camp::UserObject createShortcut(camp::UserObject character, int objectId, int objectUID, int slotId, int typeId);
	bool removeShortcut(int shortcutId);
	bool loadCharacters(WorldClient &client);
	int	 saveObject(camp::UserObject record);
	bool deleteShortcutRecordById(int id);
	bool deleteCharacterRecordById(int id);
	bool deleteCharacterStatsRecordById(int id);

	bool deleteCharacter(camp::UserObject characterRecord, int vectorIndex, WorldClient &client);
	bool deleteCharacterStats(int characterId);
	bool deleteCharacterSpells(int characterId);
	bool deleteCharacterShortcuts(int characterId);

	int getExperience(int level);
	int getIndexModulo(std::vector<camp::UserObject> _objects, int askedId, int propertyId = 0);

	std::vector<camp::UserObject> getVectorByRecord(std::string recordName);
	

	/* Getter without lock */
	camp::UserObject getRecordObject(int index, std::string recordName, int propertyIndex = 0);
	
	/* Getter with lock on */
	std::vector<camp::UserObject> getCharacterSpells(int id);
	camp::UserObject getCharacterStats(int id);
	std::vector<camp::UserObject> getCharacterShortcuts(int id);

	std::vector<camp::UserObject> _characters;
	std::vector<camp::UserObject> _characters_stats;
	std::vector<camp::UserObject> _characters_spells;
	std::vector<camp::UserObject> _characters_shortcuts;

	std::vector<camp::UserObject> _heads;
	std::vector<camp::UserObject> _breeds;
	std::vector<camp::UserObject> _maps;
	std::vector<camp::UserObject> _maps_positions;
	std::vector<camp::UserObject> _maps_subareas;
	std::vector<camp::UserObject> _experiences;
	std::vector<camp::UserObject> _spells;
	std::vector<camp::UserObject> _spells_levels;
	SAConnection db_con;
	std::string host;
	std::string database;
	std::string user;
	std::string password;

private:
	std::mutex m;
};