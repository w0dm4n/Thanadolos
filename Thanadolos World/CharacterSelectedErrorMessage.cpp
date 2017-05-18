#include "Globals.h"
#include "CharacterSelectedErrorMessage.hpp"

CharacterSelectedErrorMessage::CharacterSelectedErrorMessage()
{

}

ushort CharacterSelectedErrorMessage::getId()
{
	return id;
}

std::string CharacterSelectedErrorMessage::getName()
{
	return "CharacterSelectedErrorMessage";
}

void CharacterSelectedErrorMessage::serialize(BinaryWriter& writer)
{

}

void CharacterSelectedErrorMessage::deserialize(BinaryReader& reader)
{
	{	}
}