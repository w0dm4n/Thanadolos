#include "Globals.h"
#include "Loader.hpp"

Loader::Loader(Database *database, CustomVisitor visitor) : database(database), visitor(visitor), over(false)
{
	HANDLE       			hProcessThread;
	hProcessThread = CreateThread(NULL, 0, this->initializeThread, this, 0, NULL);
}

DWORD Loader::handler(Loader &loader)
{
	loader.db_con.Connect(loader.database->database.c_str(), loader.database->user.c_str(), loader.database->password.c_str(), SA_MySQL_Client);

	SACommand command(&loader.db_con);
	command.setCommandText("SET NAMES 'utf8'");
	command.Execute();
	loader.over = this->visitor.loadTable(loader.database, this);
	loader.db_con.Disconnect();
	return 0;
}