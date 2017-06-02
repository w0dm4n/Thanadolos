#pragma once
#pragma comment(lib, "mysqlcppconn.lib")
#pragma comment(lib, "sqlapi.lib")
#pragma comment(lib, "campd.lib")
#include <iostream>
#include <camp/camptype.hpp>
#include <camp/class.hpp>
#include <SQLAPI.h>
#include <mutex>
#include "ServerStatus.hpp"

class Database
{
public:
	Database(std::string host, std::string database, std::string user, std::string password);
	~Database();
	bool Database::initializeDatabase();
	camp::UserObject getAccount(std::string Account, std::string Password);
	SAConnection &getConnection();
	void loadServers();
	void updateWorldStatus(int serverId, int status);
	std::list<camp::UserObject> getWorldsServers();
	std::list<camp::UserObject> getWorldsCharactersByAccountId(int accountId);
	camp::UserObject getWorldServer(int serverId);
	void increaseCharactersCount(int serverId, int accountId);
	void decreaseCharactersCount(int serverId, int accountId);

private:
	SAConnection db_con;
	std::string host;
	std::string database;
	std::string user;
	std::string password;
	std::mutex m;


	std::list<camp::UserObject> WorldsServers;
};