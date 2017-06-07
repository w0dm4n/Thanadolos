#include "Globals.h"
#include "Inventory.hpp"
#include "Character.hpp"

Inventory::Inventory(Character *character)
{
	this->character = character;
	this->items = character->getClient().getWorld()->getDatabase()->getCharacterItems(character->getCharacterRecord().get("Id"));
}

Inventory::Inventory()
{

}

std::vector<ObjectItem> Inventory::getObjectItem()
{
	std::vector<ObjectItem> items;
	
	for (int i = 0; i < this->items.size(); i++)
		items.push_back(ObjectItem(this->items[i].getPosition(), this->items[i].getGID(), this->items[i].getEffects(), this->items[i].getUID(), this->items[i].getQuantity()));
	return items;
}