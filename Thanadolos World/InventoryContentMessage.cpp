#include "Globals.h"
#include "InventoryContentMessage.hpp"

InventoryContentMessage::InventoryContentMessage(std::vector<ObjectItem> objects, int kamas)
{
	this->objects = objects;
	this->kamas = kamas;

}

InventoryContentMessage::InventoryContentMessage()
{

}

ushort InventoryContentMessage::getId()
{
	return id;
}

std::string InventoryContentMessage::getName()
{
	return "InventoryContentMessage";
}

void InventoryContentMessage::serialize(BinaryWriter& writer)
{
	writer.writeShort(this->objects.size());	int _loc2_ = 0;
	while (_loc2_ < this->objects.size())	{		(this->objects[_loc2_]).serialize(writer);
		_loc2_++;	}	writer.writeVarLong(this->kamas);
}

void InventoryContentMessage::deserialize(BinaryReader& reader)
{
	{		ObjectItem _loc4_;
		int _loc2_ = reader.readUnsignedShort();		int _loc3_ = 0;
		while (_loc3_ < _loc2_)		{			_loc4_.deserialize(reader);			this->objects.push_back(_loc4_);			_loc3_++;		}		this->kamas = reader.readVarLong();	}
}