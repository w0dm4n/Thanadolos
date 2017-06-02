#include "Globals.h"
#include "FighterStatsListMessage.hpp"

FighterStatsListMessage::FighterStatsListMessage(CharacterCharacteristicsInformations& stats)
{
	this->stats = stats;

}

FighterStatsListMessage::FighterStatsListMessage()
{

}

ushort FighterStatsListMessage::getId()
{
	return id;
}

std::string FighterStatsListMessage::getName()
{
	return "FighterStatsListMessage";
}

void FighterStatsListMessage::serialize(BinaryWriter& writer)
{
	this->stats.serialize(writer);

}

void FighterStatsListMessage::deserialize(BinaryReader& reader)
{
	{		this->stats.deserialize(reader);	}
}