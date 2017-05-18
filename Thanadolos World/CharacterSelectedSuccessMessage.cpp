#include "Globals.h"
#include "CharacterSelectedSuccessMessage.hpp"

CharacterSelectedSuccessMessage::CharacterSelectedSuccessMessage(CharacterBaseInformations& infos, bool isCollectingStats)
{
	this->infos = infos;
	this->isCollectingStats = isCollectingStats;

}

CharacterSelectedSuccessMessage::CharacterSelectedSuccessMessage()
{

}

ushort CharacterSelectedSuccessMessage::getId()
{
	return id;
}

std::string CharacterSelectedSuccessMessage::getName()
{
	return "CharacterSelectedSuccessMessage";
}

void CharacterSelectedSuccessMessage::serialize(BinaryWriter& writer)
{
	this->infos.serialize(writer);
	writer.writeBool(this->isCollectingStats);
}

void CharacterSelectedSuccessMessage::deserialize(BinaryReader& reader)
{
	{		this->infos.deserialize(reader);		this->isCollectingStats = reader.readBool();	}
}