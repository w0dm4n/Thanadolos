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
#include "SpellsRecord.hpp"
#include "CharacterSpellsRecord.hpp"
#include "SpellsLevelsRecord.hpp"
#include "CharacterShortcutsRecord.hpp"
#include "ItemsRecord.hpp"
#include "Utils.hpp"
#include "Config.hpp"
#include "World.hpp"
#include "Loader.hpp"

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
	SpellsRecord::declareRecord();
	CharacterSpellsRecord::declareRecord();
	SpellsLevelsRecord::declareRecord();
	CharacterShortcutsRecord::declareRecord();
	ItemsRecord::declareRecord();
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
	std::vector<CustomVisitor>	visitors;
	std::vector<Loader*>		loaders;
	std::vector<bool>			over;
	int							i = 0;

	visitors.push_back(this->getVisitor("CharacterRecord"));
	visitors.push_back(this->getVisitor("CharacterStatsRecord"));
	visitors.push_back(this->getVisitor("CharacterSpellsRecord"));
	visitors.push_back(this->getVisitor("CharacterShortcutsRecord"));
	visitors.push_back(this->getVisitor("ExperiencesRecord"));
	visitors.push_back(this->getVisitor("BreedsRecord"));
	visitors.push_back(this->getVisitor("HeadsRecord"));
	visitors.push_back(this->getVisitor("MapsRecord"));
	visitors.push_back(this->getVisitor("MapsPositionsRecord"));
	visitors.push_back(this->getVisitor("MapsSubareasRecord"));
	visitors.push_back(this->getVisitor("SpellsRecord"));
	visitors.push_back(this->getVisitor("SpellsLevelsRecord"));
	visitors.push_back(this->getVisitor("ItemsRecord"));
	
	while (i < visitors.size())
		loaders.push_back(new Loader(this, visitors[i++]));
	while (true)
	{
		for (int i = 0; i < loaders.size(); i++)
		{
			if (loaders[i]->over)
				over.push_back(true);
		}
		if (over.size() == loaders.size())
			break;
		else
			over.clear();
		Sleep(1000);
	}
	i = 0;
	while (i < loaders.size())
		delete loaders[i++];
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
		std::lock_guard<std::mutex> locker(this->m);
		CustomVisitor visitor;
		const camp::Class& currentClass = object.getClass();
		visitor.className = currentClass.name();

		const camp::Class& metaclass = camp::classByName(currentClass.name());
		metaclass.visit(visitor);
		std::string query = visitor.buildUpdateQuery(object, currentClass.name());

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

bool Database::createCharacterSpells(std::vector<int> breedSpells, camp::UserObject character)
{
	try
	{
		const camp::Class &meta = camp::classByType<CharacterSpellsRecord>();
		CustomVisitor visitor;
		visitor.className = meta.name();
		meta.visit(visitor);

		for (int i = 0; i < breedSpells.size(); i++)
		{
			camp::UserObject characterSpell = meta.construct();
			characterSpell.set("CharacterId", (int)character.get("Id"));
			characterSpell.set("SpellId", breedSpells[i]);
			characterSpell.set("SpellLevel", 1);

			SACommand cmd(&this->db_con);
			cmd.setCommandText(visitor.buildInsertQuery(characterSpell, meta.name()).c_str());
			cmd.Execute();

			this->_characters_spells.push_back(characterSpell);
		}
		return true;
	}
	catch (std::exception &e)
	{
		Logger::Error("An error occured while trying to create a character spells", 12, e.what());
		return false;
	}
	catch (SAException& x)
	{
		Logger::Error("An error occured while trying to create a character spells", 12, x.ErrText().GetMultiByteChars());
		return false;
	}
	return true;
}

int Database::getExperience(int level)
{
	for (int i = 0; i < this->_experiences.size(); i++)
	{
		if ((int) this->_experiences[i].get("Level") == level)
			return this->_experiences[i].get("Xp");
	}
	return 0;
}

bool Database::createCharacter(CharacterCreationRequestMessage &data, WorldClient &client)
{
	try
	{
		std::vector<int> breedSpells = CharactersManager::getBreedSpells(data.breed, this);
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
		character.set("Experience", (sa_uint64_t) this->getExperience(std::stoi(config->getData("START_LEVEL"))));
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
			if (this->createCharacterStats(character, client))
				return this->createCharacterSpells(breedSpells, character);
			else
				return false;
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

bool Database::deleteShortcutRecordById(int id)
{
	int i = 0;
	while (i < this->_characters_shortcuts.size())
	{
		if (this->_characters_shortcuts[i].pointer() != NULL)
		{
			if ((int)this->_characters_shortcuts[i].get("Id") == id)
			{
				this->_characters_shortcuts.erase(this->_characters_shortcuts.begin() + i);
				return true;
			}
		}
		i++;
	}
	return false;
}

bool Database::removeShortcut(int shortcutId)
{
	try
	{
		std::lock_guard<std::mutex> locker(this->m);
		SACommand cmd(&this->db_con);
		cmd.setCommandText("delete from characters_shortcuts where Id = :1");
		cmd.Param(1).setAsNumeric() = (sa_uint64_t)shortcutId;
		cmd.Execute();
		return this->deleteShortcutRecordById(shortcutId);
	}
	catch (std::exception &e)
	{
		Logger::Error("An error occured while trying to remove a shortcut", 12, e.what());
		return false;
	}
	catch (SAException& x)
	{
		Logger::Error("An error occured while trying to remove a shortcut", 12, x.ErrText().GetMultiByteChars());
		return false;
	}
}

camp::UserObject Database::createShortcut(camp::UserObject character, int objectId, int objectUID, int slotId, int typeId)
{
	camp::UserObject empty;
	try
	{
		std::lock_guard<std::mutex> locker(this->m);
		const camp::Class			&meta = camp::classByType<CharacterShortcutsRecord>();
		camp::UserObject			shortcut = meta.construct();
		CustomVisitor				visitor;

		visitor.className = meta.name();
		meta.visit(visitor);

		shortcut.set("CharacterId", character.get("Id"));
		shortcut.set("ObjectId", objectId);
		shortcut.set("ObjectUID", objectUID);
		shortcut.set("SlotId", slotId);
		shortcut.set("TypeId", typeId);
		SACommand cmd(&this->db_con);
		cmd.setCommandText(visitor.buildInsertQuery(shortcut, meta.name()).c_str());
		cmd.Execute();

		cmd.Reset();
		SAString query = "select * from characters_shortcuts where CharacterId = :1 and SlotId = :2 and TypeId = :3";
		cmd.setCommandText(query);
		cmd.Param(1).setAsNumeric() = (sa_uint64_t)character.get("Id");
		cmd.Param(2).setAsNumeric() = (sa_uint64_t)slotId;
		cmd.Param(3).setAsNumeric() = (sa_uint64_t)typeId;
		cmd.Execute();

		cmd.FetchFirst();
		shortcut.set("Id", (sa_uint64_t)cmd.Field("Id").asNumeric());
		this->_characters_shortcuts.push_back(shortcut);
		return shortcut;
	}
	catch (std::exception &e)
	{
		Logger::Error("An error occured while trying to create a shortcut", 12, e.what());
		return empty;
	}
	catch (SAException& x)
	{
		Logger::Error("An error occured while trying to create a shortcut", 12, x.ErrText().GetMultiByteChars());
		return empty;
	}
	return empty;
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

bool Database::deleteCharacterSpells(int characterId)
{
	try
	{
		SACommand cmd(&this->db_con);
		cmd.setCommandText("delete from characters_spells where CharacterId = :1");
		cmd.Param(1).setAsNumeric() = (sa_uint64_t)characterId;
		cmd.Execute();
		if (cmd.isExecuted()) // could delete from list but not necessary
			return true;
		else
			return false;
	}
	catch (std::exception &e)
	{
		Logger::Error("An error occured while trying to delete a character spells", 12, e.what());
		return false;
	}
	catch (SAException& x)
	{
		Logger::Error("An error occured while trying to delete a character spells", 12, x.ErrText().GetMultiByteChars());
		return false;
	}
}

bool Database::deleteCharacterShortcuts(int characterId)
{
	try
	{
		SACommand cmd(&this->db_con);
		cmd.setCommandText("delete from characters_shortcuts where CharacterId = :1");
		cmd.Param(1).setAsNumeric() = (sa_uint64_t)characterId;
		cmd.Execute();
		if (cmd.isExecuted())
			return true;
		else
			return false;
	}
	catch (std::exception &e)
	{
		Logger::Error("An error occured while trying to delete a character spells", 12, e.what());
		return false;
	}
	catch (SAException& x)
	{
		Logger::Error("An error occured while trying to delete a character spells", 12, x.ErrText().GetMultiByteChars());
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
					
					if (this->deleteCharacterStats(characterRecord.get("Id")) && this->deleteCharacterSpells(characterRecord.get("Id"))
						&& this->deleteCharacterShortcuts(characterRecord.get("Id")))
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
						return true;
					}
					else
						return false;
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

std::vector<camp::UserObject> Database::getCharacterSpells(int id)
{
	std::vector<camp::UserObject> spells;
	try
	{
		std::lock_guard<std::mutex> locker(this->m);
		int i = 0;
		while (i < this->_characters_spells.size())
		{
			camp::UserObject spell = this->_characters_spells[i];
			if (spell.pointer() != NULL)
			{
				if ((int)spell.get("CharacterId") == id)
					spells.push_back(spell);
			}
			i++;
		}
		return spells;
	}
	catch (std::exception &e)
	{
		Logger::Error("An error occured while trying to fetch a character stats spells", 12, e.what());
		return spells;
	}
	return spells;
}

std::vector<camp::UserObject> Database::getCharacterShortcuts(int id)
{
	std::vector<camp::UserObject> shortcuts;
	try
	{
		std::lock_guard<std::mutex> locker(this->m);
		int i = 0;
		while (i < this->_characters_shortcuts.size())
		{
			camp::UserObject shortcut = this->_characters_shortcuts[i];
			if (shortcut.pointer() != NULL)
			{
				if ((int)shortcut.get("CharacterId") == id)
					shortcuts.push_back(shortcut);
			}
			i++;
		}
		return shortcuts;
	}
	catch (std::exception &e)
	{
		Logger::Error("An error occured while trying to fetch a character stats spells", 12, e.what());
		return shortcuts;
	}
	return shortcuts;
}

int Database::getIndexModulo(std::vector<camp::UserObject> _objects, int askedId, int propertyId)
{
	int initialSize = _objects.size() - 1;
	int part = initialSize / 4;

	const camp::Class& record = _objects[0].getClass();
	CustomVisitor visitor = this->getVisitor(record.name());
	if (part > 0)
	{
		camp::UserObject first_quarter = _objects[(part * 1)];
		camp::UserObject second_quarter = _objects[(part * 2)];
		camp::UserObject three_quarter = _objects[(part * 3)];
		if (first_quarter.pointer() != NULL && (askedId <= (int)first_quarter.get(visitor.properties[propertyId].name())))
			return 0;
		else if (second_quarter.pointer() != NULL && (askedId <= (int)second_quarter.get(visitor.properties[propertyId].name())))
			return (part * 1);
		else if (three_quarter.pointer() != NULL && (askedId <= (int)three_quarter.get(visitor.properties[propertyId].name())))
			return (part * 2);
		else
			return initialSize;
	}
	return 0;
}

std::vector<camp::UserObject> Database::getVectorByRecord(std::string recordName)
{
	std::vector<camp::UserObject> toUse;
	if (recordName == "BreedsRecord")
		toUse = this->_breeds;
	else if (recordName == "ExperiencesRecord")
		toUse = this->_experiences;
	else if (recordName == "HeadsRecord")
		toUse = this->_heads;
	else if (recordName == "MapsPositionsRecord")
		toUse = this->_maps_positions;
	else if (recordName == "MapsRecord")
		toUse = this->_maps;
	else if (recordName == "MapsSubareasRecord")
		toUse = this->_maps_subareas;
	else if (recordName == "SpellsRecord")
		toUse = this->_spells;
	else if (recordName == "SpellsLevelsRecord")
		toUse = this->_spells_levels;
	else if (recordName == "ItemsRecord")
		return this->_items;
	else
		Logger::Error("Trying to get a not existing vector " + recordName + ", check the record name");
	return toUse;
}

camp::UserObject Database::getRecordObject(int index, std::string recordName, int propertyIndex)
{
	camp::UserObject empty;
	std::vector<camp::UserObject> toUse = this->getVectorByRecord(recordName);

	if (toUse.size() > 0)
	{
		try
		{
			const camp::Class& record = toUse[0].getClass();
			CustomVisitor visitor = this->getVisitor(record.name());

			int i = this->getIndexModulo(toUse, index, propertyIndex);
			bool isNegative = (i == (toUse.size() - 1));
			while ((!isNegative) ? i < toUse.size() : i >= 0)
			{
				camp::UserObject object = toUse[i];
				if ((int)object.get(visitor.properties[propertyIndex].name()) == index)
					return object;
				i = (!isNegative) ? i + 1 : i - 1;
			}
		}
		catch (std::exception &e)
		{
			Logger::Error("An error occured while trying to fetch a record", 12, e.what());
			return empty;
		}
	}
	return empty;
}