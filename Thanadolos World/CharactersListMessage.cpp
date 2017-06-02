#include "Globals.h"
#include "CharactersListMessage.hpp"
#include <iostream>

CharactersListMessage::CharactersListMessage(std::vector<CharacterBaseInformations> characters, bool hasStartupActions) : BasicCharactersListMessage(characters)
{
	this->hasStartupActions = hasStartupActions;
}

ushort CharactersListMessage::getId()
{
	return id;
}

std::string CharactersListMessage::getName()
{
	return "CharactersListMessage";
}

void CharactersListMessage::serialize(BinaryWriter& writer)
{
	BasicCharactersListMessage::serialize(writer);
	writer.writeBool(this->hasStartupActions);
}

void CharactersListMessage::deserialize(BinaryReader& reader)
{
	//idc
}