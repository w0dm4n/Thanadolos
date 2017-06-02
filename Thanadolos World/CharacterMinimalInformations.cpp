#include "Globals.h"
#include "CharacterMinimalInformations.hpp"
#include "CharacterBasicMinimalInformations.cpp"

CharacterMinimalInformations::CharacterMinimalInformations(int id, std::string name, int level) : CharacterBasicMinimalInformations(id, name)
{
	this->level = level;
}

CharacterMinimalInformations::CharacterMinimalInformations()
{

}

ushort CharacterMinimalInformations::getId()
{
	return __id;
}

std::string CharacterMinimalInformations::getName()
{
	return "CharacterMinimalInformations";
}

void CharacterMinimalInformations::serialize(BinaryWriter& writer)
{
	CharacterBasicMinimalInformations::serialize(writer);
	writer.writeByte(this->level);
}

void CharacterMinimalInformations::deserialize(BinaryReader& reader)
{
	CharacterBasicMinimalInformations::deserialize(reader);
	this->level = reader.readUByte();
}