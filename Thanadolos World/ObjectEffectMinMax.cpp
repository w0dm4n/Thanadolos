#include "Globals.h"
#include "ObjectEffectMinMax.hpp"

ObjectEffectMinMax::ObjectEffectMinMax(int position, int objectGID, std::vector<ObjectEffect*> effects, int objectUID, int quantity, int value, int min, int max) : ObjectItem(position, objectGID, effects, objectUID, quantity)
{
	this->min = min;
	this->max = max;

}

ObjectEffectMinMax::ObjectEffectMinMax()
{

}

ushort ObjectEffectMinMax::getId()
{
	return __id;
}

std::string ObjectEffectMinMax::getName()
{
	return "ObjectEffectMinMax";
}

void ObjectEffectMinMax::serialize(BinaryWriter& writer)
{
	ObjectItem::serialize(writer);
	writer.writeVarInt(this->min);	writer.writeVarInt(this->max);
}

void ObjectEffectMinMax::deserialize(BinaryReader& reader)
{
	{		ObjectItem::deserialize(reader);		this->min = reader.readVarUhInt();		this->max = reader.readVarUhInt();	}
}