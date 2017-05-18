#include "Globals.h"
#include "GameContextCreateMessage.hpp"

GameContextCreateMessage::GameContextCreateMessage(int context)
{
	this->context = context;

}

GameContextCreateMessage::GameContextCreateMessage()
{

}

ushort GameContextCreateMessage::getId()
{
	return id;
}

std::string GameContextCreateMessage::getName()
{
	return "GameContextCreateMessage";
}

void GameContextCreateMessage::serialize(BinaryWriter& writer)
{
	writer.writeByte(this->context);
}

void GameContextCreateMessage::deserialize(BinaryReader& reader)
{
	{		this->context = reader.readByte();	}
}