#include "Globals.h"
#include "CharacterExperienceGainMessage.hpp"

CharacterExperienceGainMessage::CharacterExperienceGainMessage(int experienceCharacter, int experienceMount, int experienceGuild, int experienceIncarnation)
{
	this->experienceCharacter = experienceCharacter;
	this->experienceMount = experienceMount;
	this->experienceGuild = experienceGuild;
	this->experienceIncarnation = experienceIncarnation;

}

CharacterExperienceGainMessage::CharacterExperienceGainMessage()
{

}

ushort CharacterExperienceGainMessage::getId()
{
	return id;
}

std::string CharacterExperienceGainMessage::getName()
{
	return "CharacterExperienceGainMessage";
}

void CharacterExperienceGainMessage::serialize(BinaryWriter& writer)
{
	writer.writeVarLong(this->experienceCharacter);	writer.writeVarLong(this->experienceMount);	writer.writeVarLong(this->experienceGuild);	writer.writeVarLong(this->experienceIncarnation);
}

void CharacterExperienceGainMessage::deserialize(BinaryReader& reader)
{
	{		this->experienceCharacter = reader.readVarUhLong();		this->experienceMount = reader.readVarUhLong();		this->experienceGuild = reader.readVarUhLong();		this->experienceIncarnation = reader.readVarUhLong();	}
}