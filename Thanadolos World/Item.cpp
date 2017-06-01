#include "Globals.h"
#include "Item.hpp"

Item::Item()
{

}

ushort Item::getId()
{
	return __id;
}

std::string Item::getName()
{
	return "Item";
}

void Item::serialize(BinaryWriter& writer)
{

}

void Item::deserialize(BinaryReader& reader)
{
	{	}
}