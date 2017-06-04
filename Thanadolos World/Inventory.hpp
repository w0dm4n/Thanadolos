#pragma once

#include "ObjectItem.hpp"
class Character;
class Inventory
{
public:
	Inventory(Character *character);
	Inventory();
	std::vector<ObjectItem> getObjectItem();
private:
	Character *character;
};