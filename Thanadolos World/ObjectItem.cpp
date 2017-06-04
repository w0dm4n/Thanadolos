#include "Globals.h"
#include "ObjectItem.hpp"

ObjectItem::ObjectItem(int position, int objectGID, std::vector<ObjectEffect*> effects, int objectUID, int quantity) : Item()
{
	this->position = position;
	this->objectGID = objectGID;
	this->effects = effects;
	this->objectUID = objectUID;
	this->quantity = quantity;

}

ObjectItem::ObjectItem()
{

}


ObjectItem::~ObjectItem()
{
	for (int i = 0; i < this->effects.size(); i++)
		delete this->effects[i];
}

ushort ObjectItem::getId()
{
	return __id;
}

std::string ObjectItem::getName()
{
	return "ObjectItem";
}

void ObjectItem::serialize(BinaryWriter& writer)
{
	Item::serialize(writer);
	writer.writeByte(this->position);	writer.writeVarShort(this->objectGID);	writer.writeShort(this->effects.size());	int _loc2_ = 0;
	while (_loc2_ < this->effects.size())	{		writer.writeShort((this->effects[_loc2_])->getId());		(this->effects[_loc2_])->serialize(writer);		_loc2_++;	}	writer.writeVarShort(this->objectUID);	writer.writeVarShort(this->quantity);
}

void ObjectItem::deserialize(BinaryReader& reader)
{
	{		int _loc4_ = 0;
		ObjectEffect *_loc5_ = new ObjectEffect();
		Item::deserialize(reader);		this->position = reader.readUByte();		this->objectGID = reader.readVarUhShort();		int _loc2_ = reader.readUnsignedShort();		int _loc3_ = 0;
		while (_loc3_ < _loc2_)		{			_loc4_ = reader.readUnsignedShort();			_loc5_->deserialize(reader);			this->effects.push_back(_loc5_);			_loc3_++;		}		this->objectUID = reader.readVarUhInt();		this->quantity = reader.readVarUhInt();	}
}