#include "Globals.h"
#include "CharacterLoadingCompleteMessage.hpp"

CharacterLoadingCompleteMessage::CharacterLoadingCompleteMessage()
{

}


ushort CharacterLoadingCompleteMessage::getId()
{
	return id;
}

std::string CharacterLoadingCompleteMessage::getName()
{
	return "CharacterLoadingCompleteMessage";
}

void CharacterLoadingCompleteMessage::serialize(BinaryWriter& writer)
{

}

void CharacterLoadingCompleteMessage::deserialize(BinaryReader& reader)
{
	{	}
}