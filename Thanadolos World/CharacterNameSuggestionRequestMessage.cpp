#include "Globals.h"
#include "CharacterNameSuggestionRequestMessage.hpp"

CharacterNameSuggestionRequestMessage::CharacterNameSuggestionRequestMessage()
{

}

ushort CharacterNameSuggestionRequestMessage::getId()
{
	return id;
}

std::string CharacterNameSuggestionRequestMessage::getName()
{
	return "CharacterNameSuggestionRequestMessage";
}

void CharacterNameSuggestionRequestMessage::serialize(BinaryWriter& writer)
{

}

void CharacterNameSuggestionRequestMessage::deserialize(BinaryReader& reader)
{

}