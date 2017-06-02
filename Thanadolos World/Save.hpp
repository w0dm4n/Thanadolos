#pragma once
#include "Database.hpp"
#include "TextInformationMessage.hpp"
#include "Saver.hpp"
class Save
{
public:
	Save(Database *database, World *world, int timer);
	static DWORD WINAPI initializeThread(void *p)
	{
		Save *Obj = reinterpret_cast<Save*>(p);
		return Obj->handleSave(*Obj);
	}
	static DWORD WINAPI initializeSaver(void *p)
	{
		Saver *Obj = reinterpret_cast<Saver*>(p);
		return Obj->handleSaver(*Obj);
	}

	DWORD handleSave(Save&);
	void saveCharactersSpells();
	void saveCharactersStats();
	void saveCharacters();
	void saveCharactersShortcuts();
private:
	Database	*database;
	World		*world;
	int timer;
	bool saving;
};