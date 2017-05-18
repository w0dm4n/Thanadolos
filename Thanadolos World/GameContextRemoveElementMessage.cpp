#include "Globals.h"
#include "GameContextRemoveElementMessage.hpp"

GameContextRemoveElementMessage::GameContextRemoveElementMessage(Int64 id)
{
	this->id_actor = id;

}

GameContextRemoveElementMessage::GameContextRemoveElementMessage()
{

}

ushort GameContextRemoveElementMessage::getId()
{
	return id;
}

std::string GameContextRemoveElementMessage::getName()
{
	return "GameContextRemoveElementMessage";
}

void GameContextRemoveElementMessage::serialize(BinaryWriter& writer)
{
	writer.writeDouble(this->id_actor.toNumber());
}

void GameContextRemoveElementMessage::deserialize(BinaryReader& reader)
{
	{		this->id_actor = reader.readInt64();	}
}