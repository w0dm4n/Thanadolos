#include "Globals.h"
#include "Save.hpp"

Save::Save(Database *database, int timer) : database(database), timer(timer * 1000)
{
	this->saving = false;
	HANDLE       			hProcessThread;
	hProcessThread = CreateThread(NULL, 0, this->initializeThread, this, 0, NULL);
}

void Save::saveCharacters()
{
	int i = 0;
	while (i < this->database->_characters.size())
		this->database->saveObject(this->database->_characters[i++]);
}

void Save::saveCharactersStats()
{
	int i = 0;
	while (i < this->database->_characters_stats.size())
		this->database->saveObject(this->database->_characters_stats[i++]);
}

DWORD Save::handleSave(Save&)
{
	while (true)
	{
		Sleep(this->timer);
		Logger::Infos("Starting the save on world server...");
		this->saveCharacters();
		this->saveCharactersStats();
		Logger::Infos("The save on the world server is complete...");
	}
	return 0;
}