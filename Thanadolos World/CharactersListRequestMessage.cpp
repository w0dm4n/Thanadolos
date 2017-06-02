#include "Globals.h"
#include "CharactersListRequestMessage.hpp"
#include <iostream>

CharactersListRequestMessage::CharactersListRequestMessage()
{

}

ushort CharactersListRequestMessage::getId()
{
	return id;
}

std::string CharactersListRequestMessage::getName()
{
	return "CharactersListRequestMessage";
}

void CharactersListRequestMessage::serialize(BinaryWriter& writer)
{

}

void CharactersListRequestMessage::deserialize(BinaryReader& reader)
{

}