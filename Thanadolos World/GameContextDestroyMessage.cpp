#include "Globals.h"
#include "GameContextDestroyMessage.hpp"

GameContextDestroyMessage::GameContextDestroyMessage()
{

}

ushort GameContextDestroyMessage::getId()
{
	return id;
}

std::string GameContextDestroyMessage::getName()
{
	return "GameContextDestroyMessage";
}

void GameContextDestroyMessage::serialize(BinaryWriter& writer)
{

}

void GameContextDestroyMessage::deserialize(BinaryReader& reader)
{
	{	}
}