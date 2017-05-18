#include "Globals.h"
#include "LifePointsRegenBeginMessage.hpp"

LifePointsRegenBeginMessage::LifePointsRegenBeginMessage(int regenRate)
{
	this->regenRate = regenRate;

}

LifePointsRegenBeginMessage::LifePointsRegenBeginMessage()
{

}

ushort LifePointsRegenBeginMessage::getId()
{
	return id;
}

std::string LifePointsRegenBeginMessage::getName()
{
	return "LifePointsRegenBeginMessage";
}

void LifePointsRegenBeginMessage::serialize(BinaryWriter& writer)
{
	writer.writeByte(this->regenRate);
}

void LifePointsRegenBeginMessage::deserialize(BinaryReader& reader)
{
	{		this->regenRate = reader.readByte();	}
}