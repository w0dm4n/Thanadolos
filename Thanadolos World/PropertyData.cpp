#include "Globals.h"
#include "PropertyData.hpp"

PropertyData::PropertyData(std::string name, int type) : name_property(name), type_property(type)
{

}

std::string PropertyData::name()
{
	return this->name_property;
}

int PropertyData::type()
{
	return this->type_property;
}