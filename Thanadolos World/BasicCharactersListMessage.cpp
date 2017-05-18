#include "Globals.h"
#include "BasicCharactersListMessage.hpp"

BasicCharactersListMessage::BasicCharactersListMessage(std::vector<CharacterBaseInformations> characters)
{
	this->characters = characters;
}

ushort BasicCharactersListMessage::getId()
{
	return id;
}

std::string BasicCharactersListMessage::getName()
{
	return "BasicCharactersListMessage";
}

void BasicCharactersListMessage::serialize(BinaryWriter& writer)
{
	writer.writeShort(this->characters.size());
	int i = 0;
	while (i < this->characters.size())
	{
		writer.writeShort(this->characters[i].__id);
		this->characters[i].serialize(writer);
		i++;
	}
}

void BasicCharactersListMessage::deserialize(BinaryReader& reader)
{
	//idc
}