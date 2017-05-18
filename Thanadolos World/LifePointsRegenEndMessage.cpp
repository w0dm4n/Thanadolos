#include "Globals.h"
#include "LifePointsRegenEndMessage.hpp"

LifePointsRegenEndMessage::LifePointsRegenEndMessage(int lifePoints, int maxLifePoints, int lifePointsGained) : UpdateLifePointsMessage(lifePoints, maxLifePoints)
{
	this->lifePointsGained = lifePointsGained;
}

LifePointsRegenEndMessage::LifePointsRegenEndMessage()
{

}

ushort LifePointsRegenEndMessage::getId()
{
	return id;
}

std::string LifePointsRegenEndMessage::getName()
{
	return "LifePointsRegenEndMessage";
}

void LifePointsRegenEndMessage::serialize(BinaryWriter& writer)
{
	UpdateLifePointsMessage::serialize(writer);
	writer.writeVarInt(this->lifePointsGained);
}

void LifePointsRegenEndMessage::deserialize(BinaryReader& reader)
{
	{		UpdateLifePointsMessage::deserialize(reader);		this->lifePointsGained = reader.readVarUhInt();	}
}