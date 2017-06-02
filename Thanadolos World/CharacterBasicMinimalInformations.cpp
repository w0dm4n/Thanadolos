#include "Globals.h"
#include "CharacterBasicMinimalInformations.hpp"

CharacterBasicMinimalInformations::CharacterBasicMinimalInformations(int id, std::string name) : AbstractCharacterInformation(id)
{
	this->name = name;
}

CharacterBasicMinimalInformations::CharacterBasicMinimalInformations()
{

}

ushort CharacterBasicMinimalInformations::getId()
{
	return __id;
}

std::string CharacterBasicMinimalInformations::getName()
{
	return "CharacterBasicMinimalInformations";
}

void CharacterBasicMinimalInformations::serialize(BinaryWriter& writer)
{
	AbstractCharacterInformation::serialize(writer);
	writer.writeUTF(this->name);
}

void CharacterBasicMinimalInformations::deserialize(BinaryReader& reader)
{
	AbstractCharacterInformation::deserialize(reader);
	this->name = reader.readUTF();
}