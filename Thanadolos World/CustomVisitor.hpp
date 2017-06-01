#pragma once
#include "Utils.hpp"
#include <boost/algorithm/string/replace.hpp>
#include "PropertyData.hpp"

# define TYPE_INTEGER 2
# define TYPE_STRING 4

class Database;
class Loader;
class CustomVisitor : public camp::ClassVisitor
{
public:
	void addToVector(camp::UserObject, Database *database);
	std::string getSelect(std::string tableName);
	void setPropertyByType(camp::UserObject, PropertyData data, SACommand&);
	bool loadTable(Database *database, Loader *loader);
	void printLoaded(int loaded);
	void visit(const camp::SimpleProperty& property);
	std::string buildUpdateQuery(const camp::UserObject &object, std::string className);
	std::string buildInsertQuery(const camp::UserObject &object, std::string className);
	std::string getTableNameByClassName();
	std::vector<PropertyData> properties;
	std::string className;
};