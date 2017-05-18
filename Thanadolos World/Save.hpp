#pragma once
#include "Database.hpp"
class Save
{
public:
	Save(Database *database, int timer);
	static DWORD WINAPI initializeThread(void *p)
	{
		Save *Obj = reinterpret_cast<Save*>(p);
		return Obj->handleSave(*Obj);
	}

	DWORD handleSave(Save&);

	void saveCharacters();
	void saveCharactersStats();
private:
	Database *database;
	int timer;
	bool saving;
};