#include "Globals.h"
#include "GameMapMovementConfirmMessage.hpp"

GameMapMovementConfirmMessage::GameMapMovementConfirmMessage()
{

}

ushort GameMapMovementConfirmMessage::getId()
{
	return id;
}

std::string GameMapMovementConfirmMessage::getName()
{
	return "GameMapMovementConfirmMessage";
}

void GameMapMovementConfirmMessage::serialize(BinaryWriter& writer)
{

}

void GameMapMovementConfirmMessage::deserialize(BinaryReader& reader)
{
	{	}
}