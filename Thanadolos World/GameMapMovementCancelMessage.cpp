#include "Globals.h"
#include "GameMapMovementCancelMessage.hpp"

GameMapMovementCancelMessage::GameMapMovementCancelMessage(int cellId)
{
	this->cellId = cellId;

}

GameMapMovementCancelMessage::GameMapMovementCancelMessage()
{

}

ushort GameMapMovementCancelMessage::getId()
{
	return id;
}

std::string GameMapMovementCancelMessage::getName()
{
	return "GameMapMovementCancelMessage";
}

void GameMapMovementCancelMessage::serialize(BinaryWriter& writer)
{
	writer.writeVarShort(this->cellId);
}

void GameMapMovementCancelMessage::deserialize(BinaryReader& reader)
{
	{		this->cellId = reader.readVarUhShort();	}
}