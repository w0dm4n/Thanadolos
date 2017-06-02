#include "Globals.h"
#include "CharacterCreationRequestMessage.hpp"

CharacterCreationRequestMessage::CharacterCreationRequestMessage(std::string name,
	int breed,
	bool sex,
	std::vector<int> colors,
	uint cosmeticId)
{
	this->name = name;
	this->breed = breed;
	this->sex = sex;
	this->colors = colors;
	this->cosmeticId = cosmeticId;
}

CharacterCreationRequestMessage::CharacterCreationRequestMessage()
{

}

ushort CharacterCreationRequestMessage::getId()
{
	return id;
}

std::string CharacterCreationRequestMessage::getName()
{
	return "CharacterCreationRequestMessage";
}

void CharacterCreationRequestMessage::serialize(BinaryWriter& writer)
{

}

void CharacterCreationRequestMessage::deserialize(BinaryReader& reader)
{
	this->name = reader.readUTF();
	this->breed = reader.readByte();
	this->sex = reader.readBool();
	int i = 0;
	while (i < 5)
	{
		colors.push_back(reader.readInt());
		i++;
	}
	this->cosmeticId = reader.readVarUhShort();
}