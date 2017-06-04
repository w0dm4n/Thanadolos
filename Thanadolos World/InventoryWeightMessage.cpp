#include "Globals.h"
#include "InventoryWeightMessage.hpp"

InventoryWeightMessage::InventoryWeightMessage(int weight, int weightMax)
{
	this->weight = weight;
	this->weightMax = weightMax;

}

InventoryWeightMessage::InventoryWeightMessage()
{

}

ushort InventoryWeightMessage::getId()
{
	return id;
}

std::string InventoryWeightMessage::getName()
{
	return "InventoryWeightMessage";
}

void InventoryWeightMessage::serialize(BinaryWriter& writer)
{
	writer.writeVarShort(this->weight);	writer.writeVarShort(this->weightMax);
}

void InventoryWeightMessage::deserialize(BinaryReader& reader)
{
	{		this->weight = reader.readVarUhInt();		this->weightMax = reader.readVarUhInt();	}
}