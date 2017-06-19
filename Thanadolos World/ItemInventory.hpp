#pragma once
#include "ObjectEffect.hpp"
#include "ItemEffect.hpp"
class ItemInventory
{
public:
	ItemInventory(camp::UserObject characterItemRecord);
	int							getPosition();
	int							getGID();
	int							getUID();
	int							getQuantity();
	std::vector<ObjectEffect*>	getEffects();
	void						parseEffects();
private:
	camp::UserObject		characterItemRecord;
	std::vector<ItemEffect>	effects;
};