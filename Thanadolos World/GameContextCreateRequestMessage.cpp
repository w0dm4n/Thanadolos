#include "Globals.h"
#include "GameContextCreateRequestMessage.hpp"

GameContextCreateRequestMessage::GameContextCreateRequestMessage()
{

}

ushort GameContextCreateRequestMessage::getId()
{
	return id;
}

std::string GameContextCreateRequestMessage::getName()
{
	return "GameContextCreateRequestMessage";
}

void GameContextCreateRequestMessage::serialize(BinaryWriter& writer)
{

}

void GameContextCreateRequestMessage::deserialize(BinaryReader& reader)
{
	{	}
}