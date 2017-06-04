#include "Globals.h"
#include "ObjectEffect.hpp"

ObjectEffect::ObjectEffect(int actionId)
{
	this->actionId = actionId;

}

ObjectEffect::ObjectEffect()
{

}

ushort ObjectEffect::getId()
{
	return __id;
}

std::string ObjectEffect::getName()
{
	return "ObjectEffect";
}

void ObjectEffect::serialize(BinaryWriter& writer)
{
	writer.writeVarShort(this->actionId);
}

void ObjectEffect::deserialize(BinaryReader& reader)
{
	{		this->actionId = reader.readVarUhShort();	}
}