#include "Globals.h"
#include "CharacterLevelUpMessage.hpp"

CharacterLevelUpMessage::CharacterLevelUpMessage(int newLevel)
{
	this->newLevel = newLevel;

}

CharacterLevelUpMessage::CharacterLevelUpMessage()
{

}

ushort CharacterLevelUpMessage::getId()
{
	return id;
}

std::string CharacterLevelUpMessage::getName()
{
	return "CharacterLevelUpMessage";
}

void CharacterLevelUpMessage::serialize(BinaryWriter& writer)
{
	writer.writeByte(this->newLevel);
}

void CharacterLevelUpMessage::deserialize(BinaryReader& reader)
{
	{	}
}