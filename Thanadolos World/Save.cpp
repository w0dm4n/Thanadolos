#include "Globals.h"
#include "Save.hpp"
#include "World.hpp"
#include "Saver.hpp"

Save::Save(Database *database, World *world, int timer) : database(database), timer(timer * 1000), world(world)
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

void Save::saveCharactersSpells()
{
	int i = 0;
	while (i < this->database->_characters_spells.size())
		this->database->saveObject(this->database->_characters_spells[i++]);
}

void Save::saveCharactersShortcuts()
{
	int i = 0;
	while (i < this->database->_characters_shortcuts.size())
		this->database->saveObject(this->database->_characters_shortcuts[i++]);
}

DWORD Save::handleSave(Save&)
{
	std::vector<HANDLE>			subThreads;
	std::vector<Saver>			savers;
	std::vector<std::string>	params;
	std::vector<bool>			overs;

	while (true)
	{
		/*savers.push_back(Saver(this->database->_characters, this->database));
		savers.push_back(Saver(this->database->_characters_stats, this->database));
		savers.push_back(Saver(this->database->_characters_spells, this->database));
		savers.push_back(Saver(this->database->_characters_shortcuts, this->database));
		*/
		Sleep(this->timer);
		
		Logger::Infos("Starting the save on world server...");
		this->world->sendToAllOnlineClients(TextInformationMessage(1, 164, params));
		//this->database->m.lock();
		
		this->saveCharacters();
		this->saveCharactersStats();
		this->saveCharactersSpells();
		this->saveCharactersShortcuts();

		this->world->sendToAllOnlineClients(TextInformationMessage(1, 165, params));
		Logger::Infos("The save on the world server is complete...");

		/*for (int i = 0; i < savers.size(); i++)
			subThreads.push_back(CreateThread(NULL, 0, this->initializeSaver, &savers[i], 0, NULL));
		while (true)
		{
			for (int i = 0; i < savers.size(); i++)
			{
				if (savers[i].over == true)
					overs.push_back(true);
			}
			if (overs.size() == savers.size())
			{
				this->world->sendToAllOnlineClients(TextInformationMessage(1, 165, params));
				Logger::Infos("The save on the world server is complete...");

				//this->database->m.unlock();
				savers.clear();
				break;
			}
			else
				overs.clear();
			Sleep(1000);
		}*/
	}
	return 0;
}