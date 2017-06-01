#include "Globals.h"
#include "Saver.hpp"

Saver::Saver(std::vector<camp::UserObject> objects, Database *database)
{
	this->objects = objects;
	this->database = database;
	this->over = false;
}

DWORD Saver::handleSaver(Saver& saver)
{
	saver.save();
	return 0;
}

void Saver::save()
{
	SAConnection					db_con;
	if (this->objects.size() == 0)
	{
		Logger::Error("An error occurred while trying to save an empty camp list");
		return ;
	}
	try
	{
		db_con.Connect(this->database->database.c_str(), this->database->user.c_str(), this->database->password.c_str(), SA_MySQL_Client);

		SACommand command(&db_con);
		command.setCommandText("SET NAMES 'utf8'");
		command.Execute();
	}
	catch (SAException& x)
	{
		Logger::Error("An error occured while trying to save an object", 12, x.ErrText().GetMultiByteChars());
	}
	CustomVisitor visitor;
	const camp::Class& currentClass = this->objects[0].getClass();
	visitor.className = currentClass.name();

	const camp::Class& metaclass = camp::classByName(currentClass.name());
	metaclass.visit(visitor);
	for (int i = 0; i < this->objects.size(); i++)
	{
		try
		{
			std::string query = visitor.buildUpdateQuery(this->objects[i], currentClass.name());
			SACommand cmd(&db_con);
			cmd.setCommandText(query.c_str());
			cmd.Execute();
			cmd.Reset();
		}
		catch (std::exception &e)
		{
			Logger::Error("An error occured while trying to save an object", 12, e.what());
		}
		catch (SAException& x)
		{
			Logger::Error("An error occured while trying to save an object", 12, x.ErrText().GetMultiByteChars());
		}
	}
	db_con.Disconnect();
	this->over = true;
}