#include "Globals.h"
#include "GameContextCreateErrorMessage.hpp"

GameContextCreateErrorMessage::GameContextCreateErrorMessage()
{

}

ushort GameContextCreateErrorMessage::getId()
{
	return id;
}

std::string GameContextCreateErrorMessage::getName()
{
	return "GameContextCreateErrorMessage";
}

void GameContextCreateErrorMessage::serialize(BinaryWriter& writer)
{

}

void GameContextCreateErrorMessage::deserialize(BinaryReader& reader)
{
	{	}
}