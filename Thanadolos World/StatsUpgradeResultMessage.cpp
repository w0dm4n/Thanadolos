#include "Globals.h"
#include "StatsUpgradeResultMessage.hpp"

StatsUpgradeResultMessage::StatsUpgradeResultMessage(int result, int nbCharacBoost)
{
	this->result = result;
	this->nbCharacBoost = nbCharacBoost;

}

StatsUpgradeResultMessage::StatsUpgradeResultMessage()
{

}

ushort StatsUpgradeResultMessage::getId()
{
	return id;
}

std::string StatsUpgradeResultMessage::getName()
{
	return "StatsUpgradeResultMessage";
}

void StatsUpgradeResultMessage::serialize(BinaryWriter& writer)
{
	writer.writeByte(this->result);	writer.writeVarShort(this->nbCharacBoost);
}

void StatsUpgradeResultMessage::deserialize(BinaryReader& reader)
{
	{		this->result = reader.readByte();		this->nbCharacBoost = reader.readVarUhShort();	}
}