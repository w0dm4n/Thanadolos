#pragma once

#include "ObjectItem.hpp"
#include "ItemInventory.hpp"
class Character;
class Inventory
{
public:
	Inventory(Character *character);
	Inventory();
	std::vector<ObjectItem> getObjectItem();
private:
	Character *character;
	std::vector<ItemInventory> items;
};