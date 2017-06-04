#include "Globals.h"
#include "ObjectEffectInteger.hpp"

ObjectEffectInteger::ObjectEffectInteger(int position, int objectGID, std::vector<ObjectEffect*> effects, int objectUID, int quantity, int value) : ObjectItem(position, objectGID, effects, objectUID, quantity)
{
	this->value = value;

}

ObjectEffectInteger::ObjectEffectInteger()
{

}

ushort ObjectEffectInteger::getId()
{
	return __id;
}

std::string ObjectEffectInteger::getName()
{
	return "ObjectEffectInteger";
}

void ObjectEffectInteger::serialize(BinaryWriter& writer)
{
	ObjectItem::serialize(writer);
	writer.writeVarShort(this->value);
}

void ObjectEffectInteger::deserialize(BinaryReader& reader)
{
	{		ObjectItem::deserialize(reader);		this->value = reader.readVarUhShort();	}
}