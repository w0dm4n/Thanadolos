#include "Globals.h"
#include "ItemInventory.hpp"

ItemInventory::ItemInventory(camp::UserObject characterItemRecord)
{
	this->characterItemRecord = characterItemRecord;
	this->parseEffects();
}

void ItemInventory::parseEffects()
{
	std::string encrypted_effects = this->characterItemRecord.get("Effects");
	if (encrypted_effects.length() > 0)
	{

	}
}

int ItemInventory::getPosition()
{
	return this->characterItemRecord.get("Position");
}

int ItemInventory::getGID()
{
	return this->characterItemRecord.get("TemplateId");
}

int ItemInventory::getUID()
{
	return this->characterItemRecord.get("Id");
}

int ItemInventory::getQuantity()
{
	return this->characterItemRecord.get("Quantity");
}

std::vector<ObjectEffect*> ItemInventory::getEffects()
{
	std::vector<ObjectEffect*> effects;

	return effects;
}