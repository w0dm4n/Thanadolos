#include "Globals.h"
#include "CharacterStatsListMessage.hpp"

CharacterStatsListMessage::CharacterStatsListMessage(CharacterCharacteristicsInformations& stats)
{
	this->stats = stats;

}

CharacterStatsListMessage::CharacterStatsListMessage()
{

}

ushort CharacterStatsListMessage::getId()
{
	return id;
}

std::string CharacterStatsListMessage::getName()
{
	return "CharacterStatsListMessage";
}

void CharacterStatsListMessage::serialize(BinaryWriter& writer)
{
	this->stats.serialize(writer);

}

void CharacterStatsListMessage::deserialize(BinaryReader& reader)
{
	{		this->stats.deserialize(reader);	}
}