#include "Globals.h"
#include "HumanOption.hpp"

HumanOption::HumanOption()
{

}

ushort HumanOption::getId()
{
	return __id;
}

std::string HumanOption::getName()
{
	return "HumanOption";
}

void HumanOption::serialize(BinaryWriter& writer)
{

}

void HumanOption::deserialize(BinaryReader& reader)
{
	{	}
}