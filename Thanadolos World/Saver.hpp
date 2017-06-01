#pragma once
#include "Database.hpp"
class Saver
{
public:
	Saver(std::vector<camp::UserObject> objects, Database *database);

	bool							over;
	void save();
	std::vector<camp::UserObject>	objects;
	Database						*database;
	DWORD							handleSaver(Saver&);
};