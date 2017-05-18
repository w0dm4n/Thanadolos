#include "Globals.h"
#include "GameContextActorInformations.hpp"

GameContextActorInformations::GameContextActorInformations(int contextualId, EntityLook& look, EntityDispositionInformations& disposition)
{
	this->contextualId = contextualId;
	this->look = look;
	this->disposition = disposition;

}

GameContextActorInformations::GameContextActorInformations()
{

}

ushort GameContextActorInformations::getId()
{
	return __id;
}

std::string GameContextActorInformations::getName()
{
	return "GameContextActorInformations";
}

void GameContextActorInformations::serialize(BinaryWriter& writer)
{
	writer.writeDouble(this->contextualId.toNumber());	this->look.serialize(writer);
	writer.writeShort(this->disposition.getId());	this->disposition.serialize(writer);
}

void GameContextActorInformations::deserialize(BinaryReader& reader)
{
	{		this->contextualId = reader.readInt64();		this->look.deserialize(reader);		int _loc2_ = reader.readUnsignedShort();		this->disposition.deserialize(reader);	}
}