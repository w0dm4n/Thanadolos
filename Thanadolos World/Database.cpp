#include "Globals.h"
#include "Database.hpp"
#include "Logger.hpp"
#include "AccountRecord.hpp"
#include "CharacterRecord.hpp"
#include "HeadsRecord.hpp"
#include "BreedsRecord.hpp"
#include "MapsRecord.hpp"
#include "MapsPositionsRecord.hpp"
#include "MapsSubareasRecord.hpp"
#include "CharacterStatsRecord.hpp"
#include "ExperiencesRecord.hpp"
#include "Utils.hpp"
#include "Config.hpp"
#include "World.hpp"

Database::Database(std::string host, std::string database, std::string user, std::string password)
{
	this->host = host;
	this->database = database;
	this->user = user;
	this->password = password;

	/* Declaring reflections data class */
	AccountRecord::declareRecord();
	CharacterRecord::declareRecord();
	HeadsRecord::declareRecord();
	BreedsRecord::declareRecord();
	MapsRecord::declareRecord();
	MapsPositionsRecord::declareRecord();
	MapsSubareasRecord::declareRecord();
	CharacterStatsRecord::declareRecord();
	ExperiencesRecord::declareRecord();
}

Database::~Database()
{
}

SAConnection &Database::getConnection()
{
	return this->db_con;
}

CustomVisitor Database::getVisitor(std::string name)
{
	CustomVisitor visitor;
	visitor.className = name;
	const camp::Class& record = camp::classByName(visitor.className);
	record.visit(visitor);
	return visitor;
}

bool Database::loadTables()
{
	std::vector<CustomVisitor> visitors;
	visitors.push_back(this->getVisitor("CharacterRecord"));
	visitors.push_back(this->getVisitor("CharacterStatsRecord"));
	visitors.push_back(this->getVisitor("ExperiencesRecord"));
	visitors.push_back(this->getVisitor("BreedsRecord"));
	visitors.push_back(this->getVisitor("HeadsRecord"));
	visitors.push_back(this->getVisitor("MapsRecord"));
	visitors.push_back(this->getVisitor("MapsPositionsRecord"));
	visitors.push_back(this->getVisitor("MapsSubareasRecord"));

	int i = 0;
	while (i < visitors.size())
	{
		if (!visitors[i++].loadTable(this))
			return false;
	}
	return true;
}

bool Database::initializeDatabase()
{
	try
	{
		bool result = true;
		this->db_con.Connect(this->database.c_str(), this->user.c_str(), this->password.c_str(), SA_MySQL_Client);

		SACommand command(&this->db_con);
		command.setCommandText("SET NAMES 'utf8'");
		command.Execute();
		Logger::Infos("Successfully connected to the database !", 2);
		Logger::Infos("Loading tables...");
		return this->loadTables();
	}
	catch (SAException& x)
	{
		Logger::Error("An error occured while trying to load the database", 12, x.ErrText().GetMultiByteChars());
		return false;
	}
	return false;
}

camp::UserObject Database::buildAccount(IpcTicketAccountMessage ticketAccount)
{
	const camp::Class &meta = camp::classByType<AccountRecord>();

	camp::UserObject acc = meta.construct();
	acc.set("id", ticketAccount.accountId);
	acc.set("account", ticketAccount.account);
	acc.set("password", ticketAccount.password);
	acc.set("question", ticketAccount.secret_question);
	acc.set("answer", ticketAccount.secret_answer);
	acc.set("level", ticketAccount.level);
	acc.set("nickname", ticketAccount.nickname);
	acc.set("banned", ticketAccount.banned);
	return acc;
}

bool Database::characterNameAvailable(const char *name)
{
	try
	{
		std::lock_guard<std::mutex> locker(this->m);
		int i = 0;
		int len = strlen(name);
		while (i < this->_characters.size())
		{
			camp::UserObject character = this->_characters[i];
			if (character.pointer() != NULL)
			{
				std::string characterName = character.get("Name");
				if (len == characterName.length() && strncmp(characterName.c_str(), name, (strlen(name) - 1)) == 0)
					return false;
			}
			
			i++;
		}
		return true;
	}
	catch (std::exception &e)
	{
		Logger::Error("An error occured while trying to check a character name", 12, e.what());
		return false;
	}
	catch (SAException& x)
	{
		Logger::Error("An error occured while trying to check a character name", 12, x.ErrText().GetMultiByteChars());
		return false;
	}
}

int Database::saveObject(camp::UserObject object)
{
	try
	{
		CustomVisitor visitor;
		const camp::Class& currentClass = object.getClass();
		visitor.className = currentClass.name();

		const camp::Class& metaclass = camp::classByName(currentClass.name());
		metaclass.visit(visitor);
		std::string query = visitor.buildUpdateQuery(object, currentClass.name());

		std::lock_guard<std::mutex> locker(this->m);

		SACommand cmd(&this->db_con);
		cmd.setCommandText(query.c_str());
		cmd.Execute();
		return true;
	}
	catch (std::exception &e)
	{
		Logger::Error("An error occured while trying to save an object", 12, e.what());
		return false;
	}
	catch (SAException& x)
	{
		Logger::Error("An error occured while trying to save an object", 12, x.ErrText().GetMultiByteChars());
		return false;
	}
}

bool Database::createCharacterStats(camp::UserObject characterRecord, WorldClient &client)
{
	try
	{
		const camp::Class &meta = camp::classByType<CharacterStatsRecord>();
		camp::UserObject characterStats = meta.construct();
		Config *config = client.getWorld()->getConfig();
		int startLevel = std::stoi(config->getData("START_LEVEL"));

		characterStats.set("CharacterId", (sa_uint64_t)characterRecord.get("Id"));
		characterStats.set("StatsPoints", (startLevel * 5) - 5);
		characterStats.set("SpellsPoints", (sa_uint64_t)(startLevel - 1));
		characterStats.set("BaseVitality", (sa_uint64_t)0);
		characterStats.set("BaseWisdom", (sa_uint64_t)0);
		characterStats.set("BaseStrength", (sa_uint64_t)0);
		characterStats.set("BaseIntelligence", (sa_uint64_t)0);
		characterStats.set("BaseChance", (sa_uint64_t)0);
		characterStats.set("BaseAgility", (sa_uint64_t)0);
		characterStats.set("CurrentLife", (sa_uint64_t) (42 + (5 * (int) characterRecord.get("Level") - 5)));

		CustomVisitor visitor;
		visitor.className = meta.name();
		meta.visit(visitor);

		SACommand cmd(&this->db_con);
		cmd.setCommandText(visitor.buildInsertQuery(characterStats, meta.name()).c_str());
		cmd.Execute();
		this->_characters_stats.push_back(characterStats);
		return true;
	}
	catch (std::exception &e)
	{
		Logger::Error("An error occured while trying to create a character stats", 12, e.what());
		return false;
	}
	catch (SAException& x)
	{
		Logger::Error("An error occured while trying to create a character stats", 12, x.ErrText().GetMultiByteChars());
		return false;
	}
}

bool Database::createCharacter(CharacterCreationRequestMessage &data, WorldClient &client)
{
	try
	{
		std::lock_guard<std::mutex> locker(this->m);
		const camp::Class &meta = camp::classByType<CharacterRecord>();
		camp::UserObject character = meta.construct();
		Config *config = client.getWorld()->getConfig();

		character.set("AccountId", (sa_uint64_t) client.getAccount().get("id"));
		character.set("Name", (const char *) data.name.c_str());
		character.set("Level", (sa_uint64_t)std::stoi(config->getData("START_LEVEL")));
		character.set("MapId", (sa_uint64_t) std::stoi(config->getData("START_MAP")));
		character.set("CellId", (sa_uint64_t) std::stoi(config->getData("START_CELL")));
		character.set("Kamas", (sa_uint64_t)std::stoi(config->getData("START_KAMAS")));
		character.set("Experience", (sa_uint64_t) 0);
		character.set("Breed", (sa_uint64_t) data.breed);
		character.set("Sex", (bool) data.sex);
		character.set("CosmeticId", (sa_uint64_t) data.cosmeticId);
		character.set("Colors_0", (sa_uint64_t) data.colors[0]);
		character.set("Colors_1", (sa_uint64_t) data.colors[1]);
		character.set("Colors_2", (sa_uint64_t) data.colors[2]);
		character.set("Colors_3", (sa_uint64_t) data.colors[3]);
		character.set("Colors_4", (sa_uint64_t) data.colors[4]);

		CustomVisitor visitor;
		visitor.className = meta.name();
		meta.visit(visitor);

		SACommand cmd(&this->db_con);
		std::string name = character.get("Name");
		std::string xp = character.get("Experience");
		cmd.setCommandText(visitor.buildInsertQuery(character, meta.name()).c_str());
		cmd.Execute();

		cmd.Reset();
		SAString query = "select * from characters where Name = :1";
		cmd.setCommandText(query);
		cmd.Param(1).setAsString() = (const char *) name.c_str();
		cmd.Execute();

		if (cmd.isResultSet() > 0)
		{
			cmd.FetchFirst();
			character.set("Id", (sa_uint64_t)cmd.Field("Id").asNumeric());
			this->_characters.push_back(character);
			client.addCharacter(character);
			client.sendNewCharacterToAuth();
			std::string msg = "One new character [";
			msg += name;
			msg += "] created !";
			Logger::Infos(msg);
			cmd.Close();
			return this->createCharacterStats(character, client);
		}
		return false;
	}
	catch (std::exception &e)
	{
		Logger::Error("An error occured while trying to create a character", 12, e.what());
		return false;
	}
	catch (SAException& x)
	{
		Logger::Error("An error occured while trying to create a character", 12, x.ErrText().GetMultiByteChars());
		return false;
	}
}

bool Database::loadCharacters(WorldClient &client)
{
	camp::UserObject account = client.getAccount();
	if (account.pointer() != NULL)
	{
		try
		{
			std::lock_guard<std::mutex> locker(this->m);
			int i = 0;
			while (i < this->_characters.size())
			{
				camp::UserObject character = this->_characters[i];
				if (character.pointer() != NULL)
				{
					if ((int)character.get("AccountId") == (int)account.get("id"))
						client.addCharacter(character);
				}
				i++;
			}
			return true;
		}
		catch (std::exception &e)
		{
			Logger::Error("An error occured while trying to load characters for a client", 12, e.what());
			return false;
		}
	}
	else
		return false;
}

bool Database::deleteCharacterRecordById(int id)
{
	int i = 0;
	while (i < this->_characters.size())
	{
		if (this->_characters[i].pointer() != NULL)
		{
			if ((int)this->_characters[i].get("Id") == id)
			{
				this->_characters.erase(this->_characters.begin() + i);
				return true;
			}
		}
		i++;
	}
	return false;
}

bool Database::deleteCharacterStatsRecordById(int id)
{
	int i = 0;
	while (i < this->_characters_stats.size())
	{
		if (this->_characters_stats[i].pointer() != NULL)
		{
			if ((int)this->_characters_stats[i].get("CharacterId") == id)
			{
				this->_characters_stats.erase(this->_characters_stats.begin() + i);
				return true;
			}
		}
		i++;
	}
	return false;
}

bool Database::deleteCharacterStats(int characterId)
{
	try
	{
		SACommand cmd(&this->db_con);
		cmd.setCommandText("delete from characters_stats where CharacterId = :1");
		cmd.Param(1).setAsNumeric() = (sa_uint64_t) characterId;
		cmd.Execute();
		if (cmd.isExecuted())
			return this->deleteCharacterStatsRecordById(characterId);
		return false;
	}
	catch (std::exception &e)
	{
		Logger::Error("An error occured while trying to delete a character stats", 12, e.what());
		return false;
	}
	catch (SAException& x)
	{
		Logger::Error("An error occured while trying to delete a character stats", 12, x.ErrText().GetMultiByteChars());
		return false;
	}
}

bool Database::deleteCharacter(camp::UserObject characterRecord, int vectorIndex, WorldClient &client)
{
	try
	{
		std::lock_guard<std::mutex> locker(this->m);
		if (characterRecord.pointer() != NULL)
		{
			SACommand cmd(&this->db_con);
			cmd.setCommandText("delete from characters where Id = :1");
			cmd.Param(1).setAsNumeric() = (sa_uint64_t) characterRecord.get("Id");
			cmd.Execute();
			if (cmd.isExecuted())
			{
				if (this->deleteCharacterRecordById(characterRecord.get("Id")))
				{
					std::vector<camp::UserObject> characters = client.getCharacters();
					characters.erase(characters.begin() + vectorIndex);
					client.updateCharactersRecord(characters);
					client.sendDeletedCharacterToAuth();
					
					std::string name = characterRecord.get("Name");
					std::string msg = "One character deleted [";
					msg += name;
					msg += "] !";
					Logger::Infos(msg);
					return this->deleteCharacterStats(characterRecord.get("Id"));
				}
			}
		}
		return false;
	}
	catch (std::exception &e)
	{
		Logger::Error("An error occured while trying to delete a character", 12, e.what());
		return false;
	}
	catch (SAException& x)
	{
		Logger::Error("An error occured while trying to delete a character", 12, x.ErrText().GetMultiByteChars());
		return false;
	}
}

camp::UserObject Database::getHeadsRecord(int id)
{
	camp::UserObject empty;
	try
	{
		std::lock_guard<std::mutex> locker(this->m);
		int i = 0;
		while (i < this->_heads.size())
		{
			camp::UserObject head = this->_heads[i];
			if (head.pointer() != NULL)
			{
				if ((int)head.get("id") == id)
					return head;
			}
			i++;
		}
		camp::UserObject empty;
		return empty;
	}
	catch (std::exception &e)
	{
		Logger::Error("An error occured while trying to fetch a head record", 12, e.what());
		return empty;
	}
	return empty;
}

camp::UserObject Database::getBreedsRecord(int breedId)
{
	camp::UserObject empty;
	try
	{
		std::lock_guard<std::mutex> locker(this->m);
		int i = 0;
		while (i < this->_breeds.size())
		{
			camp::UserObject breed = this->_breeds[i];
			if (breed.pointer() != NULL)
			{
				if ((int)breed.get("id") == breedId)
					return breed;
			}
			i++;
		}
		camp::UserObject empty;
		return empty;
	}
	catch (std::exception &e)
	{
		Logger::Error("An error occured while trying to fetch a breeds record", 12, e.what());
		return empty;
	}
	return empty;
}

camp::UserObject Database::getMapsRecord(int id)
{
	camp::UserObject empty;
	try
	{
		std::lock_guard<std::mutex> locker(this->m);
		int i = 0;
		while (i < this->_maps.size())
		{
			camp::UserObject map = this->_maps[i];
			if (map.pointer() != NULL)
			{
				if ((int)map.get("id") == id)
					return map;
			}
			i++;
		}
		camp::UserObject empty;
		return empty;
	}
	catch (std::exception &e)
	{
		Logger::Error("An error occured while trying to fetch a map record", 12, e.what());
		return empty;
	}
	return empty;
}

camp::UserObject Database::getMapsPosition(int id)
{
	camp::UserObject empty;
	try
	{
		std::lock_guard<std::mutex> locker(this->m);
		int i = 0;
		while (i < this->_maps_positions.size())
		{
			camp::UserObject position = this->_maps_positions[i];
			if (position.pointer() != NULL)
			{
				if ((int)position.get("id") == id)
					return position;
			}
			i++;
		}
		camp::UserObject empty;
		return empty;
	}
	catch (std::exception &e)
	{
		Logger::Error("An error occured while trying to fetch a map position record", 12, e.what());
		return empty;
	}
	return empty;
}

camp::UserObject Database::getMapsSubareas(int id)
{
	camp::UserObject empty;
	try
	{
		std::lock_guard<std::mutex> locker(this->m);
		int i = 0;
		while (i < this->_maps_subareas.size())
		{
			camp::UserObject subarea = this->_maps_subareas[i];
			if (subarea.pointer() != NULL)
			{
				if ((int)subarea.get("id") == id)
					return subarea;
			}
			i++;
		}
		camp::UserObject empty;
		return empty;
	}
	catch (std::exception &e)
	{
		Logger::Error("An error occured while trying to fetch a map subarea record", 12, e.what());
		return empty;
	}
	return empty;
}

camp::UserObject Database::getCharacterStats(int id)
{
	camp::UserObject empty;
	try
	{
		std::lock_guard<std::mutex> locker(this->m);
		int i = 0;
		while (i < this->_characters_stats.size())
		{
			camp::UserObject stats = this->_characters_stats[i];
			if (stats.pointer() != NULL)
			{
				if ((int)stats.get("CharacterId") == id)
					return stats;
			}
			i++;
		}
		camp::UserObject empty;
		return empty;
	}
	catch (std::exception &e)
	{
		Logger::Error("An error occured while trying to fetch a character stats record", 12, e.what());
		return empty;
	}
	return empty;
}