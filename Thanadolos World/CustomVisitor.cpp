#include "Globals.h"
#include "CustomVisitor.hpp"
#include "Database.hpp"
#include "Loader.hpp"

void CustomVisitor::visit(const camp::SimpleProperty& property)
{
	properties.push_back(PropertyData(property.name(), property.type()));
}

std::string CustomVisitor::getTableNameByClassName()
{
	if (this->className == "CharacterStatsRecord")
		return "characters_stats";
	else if (this->className == "CharacterRecord")
		return "characters";
	else if (this->className == "BreedsRecord")
		return "breeds";
	else if (this->className == "ExperiencesRecord")
		return "experiences";
	else if (this->className == "HeadsRecord")
		return "heads";
	else if (this->className == "MapsPositionsRecord")
		return "maps_positions";
	else if (this->className == "MapsRecord")
		return "maps";
	else if (this->className == "MapsSubareasRecord")
		return "maps_subareas";
	else if (this->className == "SpellsRecord")
		return "spells";
	else if (this->className == "CharacterSpellsRecord")
		return "characters_spells";
	else if (this->className == "SpellsLevelsRecord")
		return "spells_levels";
	else if (this->className == "CharacterShortcutsRecord")
		return "characters_shortcuts";
	else
		Logger::Error("Trying to get the table name of an incorrect record " + this->className + ", check the name");
}

void CustomVisitor::addToVector(camp::UserObject object, Database *db)
{
	if (this->className == "CharacterStatsRecord")
		db->_characters_stats.push_back(object);
	else if (this->className == "CharacterRecord")
		db->_characters.push_back(object);
	else if (this->className == "BreedsRecord")
		db->_breeds.push_back(object);
	else if (this->className == "ExperiencesRecord")
		db->_experiences.push_back(object);
	else if (this->className == "HeadsRecord")
		db->_heads.push_back(object);
	else if (this->className == "MapsPositionsRecord")
		db->_maps_positions.push_back(object);
	else if (this->className == "MapsRecord")
		db->_maps.push_back(object);
	else if (this->className == "MapsSubareasRecord")
		db->_maps_subareas.push_back(object);
	else if (this->className == "SpellsRecord")
		db->_spells.push_back(object);
	else if (this->className == "CharacterSpellsRecord")
		db->_characters_spells.push_back(object);
	else if (this->className == "SpellsLevelsRecord")
		db->_spells_levels.push_back(object);
	else if (this->className == "CharacterShortcutsRecord")
		db->_characters_shortcuts.push_back(object);
	else
		Logger::Error("Trying to add object to an invalid record " + this->className + ", check the name");
}

std::string CustomVisitor::getSelect(std::string tableName)
{
	std::string data = "select * from ";
	data += tableName;
	return data;
}

void CustomVisitor::printLoaded(int loaded)
{
	std::string msg = std::to_string(loaded) + " " + this->getTableNameByClassName() + " loaded from database.";
	Logger::Infos(msg);
}

void CustomVisitor::setPropertyByType(camp::UserObject object, PropertyData data, SACommand &cmd)
{
	/*if (data.name() == "Kamas")
		std::cout << " TYPE :" << data.type() << std::endl;
	*/
	switch (data.type())
	{
		case TYPE_INTEGER:
			object.set(data.name(), (sa_uint64_t)cmd.Field(data.name().c_str()).asNumeric());
		break;

		case TYPE_STRING:
			object.set(data.name(), (const char*)cmd.Field(data.name().c_str()).asString());
		break;
	}
}

bool CustomVisitor::loadTable(Database *database, Loader *loader)
{
	const camp::Class &meta = camp::classByName(this->className);

	SACommand cmd(&loader->db_con);
	cmd.setCommandText(this->getSelect(this->getTableNameByClassName()).c_str());
	cmd.Execute();
	int loaded = 0;

	if (cmd.isResultSet() > 0)
	{
		while (cmd.FetchNext())
		{
			int i = 0;
			camp::UserObject object = meta.construct();
			
			while (i < this->properties.size())
				this->setPropertyByType(object, this->properties[i++], cmd);

			this->addToVector(object, database);
			loaded++;
		}
		this->printLoaded(loaded);
	}

	return true;
}

std::string CustomVisitor::buildUpdateQuery(const camp::UserObject &object, std::string className)
{
	std::string request;
	if (object.pointer() != NULL)
	{
		request = "update ";
		request += this->getTableNameByClassName();
		request += " set ";
		int i = 0;
		while (i < this->properties.size())
		{
			std::string data = object.get(this->properties[i].name());
			boost::replace_all(data, "'", "");
			request += this->properties[i].name();
			request += " = '";
			request += data;
			request += "'";
			if ((i + 1) < this->properties.size())
				request += ", ";
			i++;
		}

		std::string data = object.get(this->properties[0].name());
		boost::replace_all(data, "'", "");

		request += " where ";
		request += this->properties[0].name();
		request += " = '";
		request += data;
		request += "'";
	}
	return request;
}

std::string CustomVisitor::buildInsertQuery(const camp::UserObject &object, std::string className)
{
	std::string query;
	if (object.pointer() != NULL)
	{
		query = "insert into ";
		query += this->getTableNameByClassName();
		query += "(";

		int i = 0;
		while (i < this->properties.size())
		{
			if (this->properties[i].name() != "id" && this->properties[i].name() != "Id")
			{
				query += this->properties[i].name();
				if ((i + 1) < this->properties.size())
					query += ", ";
			}
			i++;
		}
		query += ") VALUES(";
		i = 0;
		while (i < this->properties.size())
		{
			if (this->properties[i].name() != "id" && this->properties[i].name() != "Id")
			{
				std::string data = object.get(this->properties[i].name());
				boost::replace_all(data, "'", "");
				query += "'";
				query += data;
				query += "'";
				if ((i + 1) < this->properties.size())
					query += ", ";
			}
			i++;
		}
		query += " )";
	}
	return query;
}
