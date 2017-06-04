#pragma once
#ifndef INVENTORYWEIGHTMESSAGE_THANADOLOS_HPP
#define INVENTORYWEIGHTMESSAGE_THANADOLOS_HPP

#include "imessage.h"


class InventoryWeightMessage : public IMessage
{
public:
	InventoryWeightMessage(int weight, int weightMax);
	InventoryWeightMessage();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 3009;

	/*VARS*/
	int weight;
	int weightMax;
};


#endif