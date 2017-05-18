#include "AbstractCharacterInformation.hpp"

AbstractCharacterInformation::AbstractCharacterInformation(
	int id
)
{
	this->id = id;
}

AbstractCharacterInformation::AbstractCharacterInformation()
{

}

ushort AbstractCharacterInformation::getId()
{
	return __id;
}

std::string AbstractCharacterInformation::getName()
{
	return "AbstractCharacterInformation";
}

void AbstractCharacterInformation::serialize(BinaryWriter& writer)
{
	writer.writeVarLong(this->id);
}

void AbstractCharacterInformation::deserialize(BinaryReader& reader)
{
	this->id = reader.readVarLong();
}