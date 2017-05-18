#pragma once

#ifndef WORLDSCHARACTERS_HPP
# define WORLDSCHARACTERS_HPP

#pragma comment(lib, "campd.lib")
#include <camp/camptype.hpp>
#include <camp/class.hpp>
#include <SQLAPI.h>

#include <iostream>
class WorldsCharactersRecord
{
public:
	static void declareRecord()
	{
		camp::Class::declare<WorldsCharactersRecord>("WorldsCharactersRecord")
			.constructor0()
			.property("id", &WorldsCharactersRecord::getId, &WorldsCharactersRecord::setId)
			.property("account", &WorldsCharactersRecord::getAccountId, &WorldsCharactersRecord::setAccountId)
			.property("server", &WorldsCharactersRecord::getServerId, &WorldsCharactersRecord::setServerId)
			.property("count", &WorldsCharactersRecord::getCharactersCount, &WorldsCharactersRecord::setCharactersCount);
	}
	WorldsCharactersRecord() { }

	int getId() const { return this->Id; }
	void setId(int id) { this->Id = id; }

	int getAccountId() const { return this->AccountId; }
	void setAccountId(int id) { this->AccountId = id; }

	int getServerId() const { return this->ServerId; }
	void setServerId(int id) { this->ServerId = id; }

	int getCharactersCount() const { return this->CharactersCount; }
	void setCharactersCount(int id) { this->CharactersCount = id; }
private:
	int Id;
	int AccountId;
	int ServerId;
	int CharactersCount;
};

CAMP_TYPE(WorldsCharactersRecord)

#endif
