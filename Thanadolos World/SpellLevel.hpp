#pragma once
#include "Database.hpp"
class SpellLevel
{
public:
	SpellLevel();
	SpellLevel(int levelId, Database *database);
	camp::UserObject levelRecord;
};