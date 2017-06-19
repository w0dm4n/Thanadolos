#pragma once
#ifndef INVENTORYCONTENTMESSAGE_THANADOLOS_HPP
#define INVENTORYCONTENTMESSAGE_THANADOLOS_HPP

#include "imessage.h"
#include "ObjectItem.hpp"

class InventoryContentMessage : public IMessage
{
public:
	InventoryContentMessage(std::vector<ObjectItem> objects, int kamas);
	InventoryContentMessage();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 3016;

	/*VARS*/
	std::vector<ObjectItem> objects;
	int kamas;
};


#endif