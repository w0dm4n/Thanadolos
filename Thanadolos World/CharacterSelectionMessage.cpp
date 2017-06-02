#include "Globals.h"
#include "CharacterSelectionMessage.hpp"

CharacterSelectionMessage::CharacterSelectionMessage()
{

}

ushort CharacterSelectionMessage::getId()
{
	return id;
}

std::string CharacterSelectionMessage::getName()
{
	return "CharacterSelectionMessage";
}

void CharacterSelectionMessage::serialize(BinaryWriter& writer)
{
	writer.writeVarLong(this->characterId);
}

void CharacterSelectionMessage::deserialize(BinaryReader& reader)
{
	this->characterId = reader.readVarUhLong();
}