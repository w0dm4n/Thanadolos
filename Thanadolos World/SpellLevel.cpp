#include "Globals.h"
#include "SpellLevel.hpp"

SpellLevel::SpellLevel()
{

}

SpellLevel::SpellLevel(int levelId, Database *database)
{
	this->levelRecord = database->getRecordObject(levelId, "SpellsLevelsRecord");
}