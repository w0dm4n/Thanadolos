#include "Globals.h"
#include "CharacterDeletionErrorMessage.hpp"

CharacterDeletionErrorMessage::CharacterDeletionErrorMessage(uint reason)
{
	this->reason = reason;
}

ushort CharacterDeletionErrorMessage::getId()
{
	return id;
}

std::string CharacterDeletionErrorMessage::getName()
{
	return "CharacterDeletionErrorMessage";
}

void CharacterDeletionErrorMessage::serialize(BinaryWriter& writer)
{
	writer.writeByte(this->reason);
}

void CharacterDeletionErrorMessage::deserialize(BinaryReader& reader)
{
	this->reason = reader.readByte();
}