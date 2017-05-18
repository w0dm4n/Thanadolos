#include "Database.hpp"
#include "Logger.hpp"
#include "Account.hpp"
#include "WorldsServers.hpp"
#include "WorldsCharacters.hpp"

Database::Database(std::string host, std::string database, std::string user, std::string password)
{
	this->host = host;
	this->database = database;
	this->user = user;
	this->password = password;

	/* Declaring reflections data class */
	AccountRecord::declareRecord();
	WorldsServersRecord::declareRecord();
	WorldsCharactersRecord::declareRecord();
}

void Database::loadServers()
{
	try
	{
		Logger::Infos("Loading servers from database..");
		const camp::Class &meta = camp::classByType<WorldsServersRecord>();
		SACommand cmd(&this->db_con);
		cmd.setCommandText("select * from worlds_servers");
		cmd.Execute();
		int loaded = 0;
		if (cmd.isResultSet() > 0)
		{
			while (cmd.FetchNext())
			{
				camp::UserObject server = meta.construct();
				server.set("id", (sa_uint64_t)cmd.Field("Id").asNumeric());
				server.set("name", (const char *)cmd.Field("Name").asString());
				server.set("address", (const char *)cmd.Field("Address").asString());
				server.set("port", (sa_uint64_t)cmd.Field("Port").asNumeric());
				server.set("capacity", (sa_uint64_t)cmd.Field("MaxCapacity").asNumeric());
				server.set("status", (sa_uint64_t)cmd.Field("ServerStatus").asNumeric());
				server.set("role", (sa_uint64_t)cmd.Field("RequiredRole").asNumeric());
				this->WorldsServers.push_back(server);
				loaded++;
			}
		}
		std::string msg = "";
		char buffer[20];

		itoa(loaded, buffer, 10);
		msg += buffer;
		msg += " server(s) loaded from database.";
		Logger::Infos(msg);
	}
	catch (std::exception &e)
	{
		Logger::Error("An error occured while trying to load servers from database", 12, e.what());
	}
	catch (SAException& x)
	{
		Logger::Error("An error occured while trying to load servers from database", 12, x.ErrText().GetMultiByteChars());
	}
}

void Database::updateWorldStatus(int serverId, int status)
{
	std::list<camp::UserObject> servers = this->getWorldsServers();
	std::list<camp::UserObject>::iterator iter = servers.begin();
	std::list<camp::UserObject>::iterator end = servers.end();

	while (iter != servers.end())
	{
		camp::UserObject server = *iter;
		if ((int)server.get("id") == serverId)
		{
			server.set("status", status);
			break;
		}
		++iter;
	}
}

std::list<camp::UserObject> Database::getWorldsServers()
{
	return this->WorldsServers;
}

Database::~Database()
{
}

SAConnection &Database::getConnection()
{
	return this->db_con;
}

bool Database::initializeDatabase()
{
	try
	{
		this->db_con.Connect(this->database.c_str(), this->user.c_str(), this->password.c_str(), SA_MySQL_Client);

		SACommand command(&this->db_con);
		command.setCommandText("SET NAMES 'utf8'");
		command.Execute();
		Logger::Infos("Successfully connected to the database !", 2);
		
		this->loadServers();
	}
	catch (SAException& x)
	{
		Logger::Error("An error occured while trying to load the database", 12, x.ErrText().GetMultiByteChars());
		return false;
	}
	return true;
}

camp::UserObject Database::getAccount(std::string Account, std::string Password)
{
	try
	{
		std::lock_guard<std::mutex> locker(this->m);
		SACommand cmd(&this->db_con);
		cmd.setCommandText("select * from accounts where Account = :1 and Password = :2");
		cmd.Param(1).setAsString() = Account.c_str();
		cmd.Param(2).setAsString() = Password.c_str();
		cmd.Execute();
		if (cmd.isResultSet() > 0)
		{
			if (cmd.FetchFirst())
			{
				SAString nickname = cmd.Field("Nickname").asString();

				const camp::Class &meta = camp::classByType<AccountRecord>();

				camp::UserObject acc = meta.construct();
				acc.set("id", (sa_uint64_t) cmd.Field("Id").asNumeric());
				acc.set("account", (const char *) cmd.Field("Account").asString());
				acc.set("password", (const char *) cmd.Field("Password").asString());
				acc.set("question", (const char *)cmd.Field("SecretQuestion").asString());
				acc.set("answer", (const char *)cmd.Field("SecretAnswer").asString());
				acc.set("level", (sa_uint64_t) cmd.Field("Level").asNumeric());
				acc.set("nickname", (const char *) cmd.Field("Nickname").asString());
				acc.set("banned", cmd.Field("Banned").asBool());
				return acc;
			}
		}
		camp::UserObject empty;
		return empty;
	}
	catch (std::exception &e)
	{
		Logger::Error("An error occured while trying to fetch an account", 12, e.what());
		camp::UserObject empty;
		return empty;
	}
	catch (SAException& x)
	{
		Logger::Error("An error occured while trying to fetch an account", 12, x.ErrText().GetMultiByteChars());
		camp::UserObject empty;
		return empty;
	}
}

std::list<camp::UserObject> Database::getWorldsCharactersByAccountId(int accountId)
{
	std::list<camp::UserObject> lists;
	try
	{
		std::lock_guard<std::mutex> locker(this->m);
		const camp::Class &meta = camp::classByType<WorldsCharactersRecord>();
		SACommand cmd(&this->db_con);
		cmd.setCommandText("select * from worlds_characters where AccountId = :1");
		cmd.Param(1).setAsNumeric() = (sa_int64_t)accountId;
		cmd.Execute();
		if (cmd.isResultSet() > 0)
		{
			while (cmd.FetchNext())
			{
				camp::UserObject characters = meta.construct();
				characters.set("id", (sa_uint64_t)cmd.Field("Id").asNumeric());
				characters.set("account", (sa_uint64_t)cmd.Field("AccountId").asNumeric());
				characters.set("server", (sa_uint64_t)cmd.Field("ServerId").asNumeric());
				characters.set("count", (sa_uint64_t)cmd.Field("CharactersCount").asNumeric());
				lists.push_back(characters);
			}
		}
		return (lists);
	}
	catch (std::exception &e)
	{
		Logger::Error("An error occured while trying to fetch worlds characters list", 12, e.what());
		return lists;	
	}
	catch (SAException& x)
	{
		Logger::Error("An error occured while trying to fetch worlds characters list", 12, x.ErrText().GetMultiByteChars());
		return lists;
	}
}

camp::UserObject Database::getWorldServer(int serverId)
{
	std::list<camp::UserObject> servers = this->getWorldsServers();
	std::list<camp::UserObject>::iterator iter = servers.begin();
	std::list<camp::UserObject>::iterator end = servers.end();

	while (iter != servers.end())
	{
		camp::UserObject server = *iter;
		if ((int)server.get("id") == serverId)
		{
			return server;
		}
		++iter;
	}
	camp::UserObject empty;
	return empty;
}

void Database::increaseCharactersCount(int serverId, int accountId)
{
	camp::UserObject world = this->getWorldServer(serverId);
	if (world.pointer() != NULL)
	{
		try
		{
			std::lock_guard<std::mutex> locker(this->m);
			SACommand cmd(&this->db_con);
			cmd.setCommandText("select * from worlds_characters where AccountId = :1 and ServerId = :2");
			cmd.Param(1).setAsNumeric() = (sa_int64_t)accountId;
			cmd.Param(2).setAsNumeric() = (sa_int64_t)serverId;
			cmd.Execute();
			
			if (cmd.isResultSet() > 0 && cmd.FetchFirst())
			{
				int currentCount = (sa_uint64_t) cmd.Field("CharactersCount").asNumeric();
				currentCount++;
				cmd.Reset();
				cmd.setCommandText("update worlds_characters set CharactersCount = :1 where AccountId = :2 and ServerId = :3");
				cmd.Param(1).setAsNumeric() = (sa_uint64_t)currentCount;
				cmd.Param(2).setAsNumeric() = (sa_uint64_t)accountId;
				cmd.Param(3).setAsNumeric() = (sa_uint64_t)serverId;
				cmd.Execute();
			}
			else
			{
				cmd.Reset();
				cmd.setCommandText("insert into worlds_characters(AccountId,ServerId,CharactersCount) values(:1, :2, :3)");
				cmd.Param(1).setAsNumeric() = (sa_uint64_t)accountId;
				cmd.Param(2).setAsNumeric() = (sa_uint64_t)serverId;
				cmd.Param(3).setAsNumeric() = (sa_uint64_t) 1;
				cmd.Execute();
			}
		}
		catch (std::exception &e)
		{
			Logger::Error("An error occured while trying to update characters count", 12, e.what());
		}
		catch (SAException& x)
		{
			Logger::Error("An error occured while trying to update characters count", 12, x.ErrText().GetMultiByteChars());
		}
	}
	else
		Logger::Error("Received a new character from an unknown world server.. be careful !");
}

void Database::decreaseCharactersCount(int serverId, int accountId)
{
	camp::UserObject world = this->getWorldServer(serverId);
	if (world.pointer() != NULL)
	{
		try
		{
			std::lock_guard<std::mutex> locker(this->m);
			SACommand cmd(&this->db_con);
			cmd.setCommandText("select * from worlds_characters where AccountId = :1 and ServerId = :2");
			cmd.Param(1).setAsNumeric() = (sa_int64_t)accountId;
			cmd.Param(2).setAsNumeric() = (sa_int64_t)serverId;
			cmd.Execute();

			if (cmd.isResultSet() > 0 && cmd.FetchFirst())
			{
				int currentCount = (sa_uint64_t)cmd.Field("CharactersCount").asNumeric();
				currentCount--;
				cmd.Reset();
				cmd.setCommandText("update worlds_characters set CharactersCount = :1 where AccountId = :2 and ServerId = :3");
				cmd.Param(1).setAsNumeric() = (sa_uint64_t)currentCount;
				cmd.Param(2).setAsNumeric() = (sa_uint64_t)accountId;
				cmd.Param(3).setAsNumeric() = (sa_uint64_t)serverId;
				cmd.Execute();
			}
			else
				Logger::Error("Trying to decrease world characters count from a server when it doesnt exist");
		}
		catch (std::exception &e)
		{
			Logger::Error("An error occured while trying to update characters count", 12, e.what());
		}
		catch (SAException& x)
		{
			Logger::Error("An error occured while trying to update characters count", 12, x.ErrText().GetMultiByteChars());
		}
	}
	else
		Logger::Error("Received a new character from an unknown world server.. be careful !");
}