#include "Globals.h"
#include "CharacterNameSuggestionSuccessMessage.hpp"

CharacterNameSuggestionSuccessMessage::CharacterNameSuggestionSuccessMessage(std::string suggestion)
{
	this->suggestion = suggestion;
}

ushort CharacterNameSuggestionSuccessMessage::getId()
{
	return id;
}

std::string CharacterNameSuggestionSuccessMessage::getName()
{
	return "CharacterNameSuggestionSuccessMessage";
}

void CharacterNameSuggestionSuccessMessage::serialize(BinaryWriter& writer)
{
	writer.writeUTF(this->suggestion);
}

void CharacterNameSuggestionSuccessMessage::deserialize(BinaryReader& reader)
{
	this->suggestion = reader.readUTF();
}