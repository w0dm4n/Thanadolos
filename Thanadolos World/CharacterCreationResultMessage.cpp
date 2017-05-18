#include "Globals.h"
#include "CharacterCreationResultMessage.hpp"

CharacterCreationResultMessage::CharacterCreationResultMessage(uint result)
{
	this->result = result;
}

ushort CharacterCreationResultMessage::getId()
{
	return id;
}

std::string CharacterCreationResultMessage::getName()
{
	return "CharacterCreationResultMessage";
}

void CharacterCreationResultMessage::serialize(BinaryWriter& writer)
{
	writer.writeByte(this->result);
}

void CharacterCreationResultMessage::deserialize(BinaryReader& reader)
{
	this->result = reader.readByte();
}