#pragma once

#include "Database.hpp"
class Loader
{
public:
	Loader(Database *database, CustomVisitor visitor);
	static DWORD WINAPI initializeThread(void *p)
	{
		Loader *Obj = reinterpret_cast<Loader*>(p);
		return Obj->handler(*Obj);
	}
	DWORD handler(Loader&);
	SAConnection	db_con;
	Database		*database;
	CustomVisitor	visitor;
	bool			over;
};