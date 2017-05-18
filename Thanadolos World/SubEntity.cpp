#include "Globals.h"
#include "SubEntity.hpp"
#include "EntityLook.hpp"
SubEntity::SubEntity(uint bindingPointCategory,
	uint bindingPointIndex,
	EntityLook *subEntityLook)
{
	this->bindingPointCategory = bindingPointCategory;
	this->bindingPointIndex = bindingPointIndex;
	this->subEntityLook = subEntityLook;
}

SubEntity::SubEntity()
{

}

ushort SubEntity::getId()
{
	return __id;
}

std::string SubEntity::getName()
{
	return "SubEntity";
}

void SubEntity::serialize(BinaryWriter& writer)
{
	writer.writeByte(this->bindingPointCategory);
	writer.writeByte(this->bindingPointIndex);
	this->subEntityLook->serialize(writer);
}

void SubEntity::deserialize(BinaryReader& reader)
{
	this->bindingPointCategory = reader.readByte();
	this->bindingPointIndex = reader.readByte();
	this->subEntityLook->deserialize(reader);
}