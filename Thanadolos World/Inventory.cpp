#include "Globals.h"
#include "Inventory.hpp"
#include "Character.hpp"

Inventory::Inventory(Character *character)
{
	this->character = character;
}

Inventory::Inventory()
{

}

std::vector<ObjectItem> Inventory::getObjectItem()
{
	std::vector<ObjectItem> items;
	std::vector <ObjectEffect*> effects;
	items.push_back(ObjectItem(63, 2438, effects, 1, 1));

	return items;
}