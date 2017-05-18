#include "Globals.h"
#include "UpdateLifePointsMessage.hpp"

UpdateLifePointsMessage::UpdateLifePointsMessage(int lifePoints, int maxLifePoints)
{
	this->lifePoints = lifePoints;
	this->maxLifePoints = maxLifePoints;

}

UpdateLifePointsMessage::UpdateLifePointsMessage()
{

}

ushort UpdateLifePointsMessage::getId()
{
	return id;
}

std::string UpdateLifePointsMessage::getName()
{
	return "UpdateLifePointsMessage";
}

void UpdateLifePointsMessage::serialize(BinaryWriter& writer)
{
	writer.writeVarShort(this->lifePoints);	writer.writeVarShort(this->maxLifePoints);
}

void UpdateLifePointsMessage::deserialize(BinaryReader& reader)
{
	{		this->lifePoints = reader.readVarUhInt();		this->maxLifePoints = reader.readVarUhInt();	}
}