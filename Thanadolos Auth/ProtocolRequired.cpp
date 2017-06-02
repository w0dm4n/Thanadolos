#include "ProtocolRequired.hpp"
#include <iostream>

ProtocolRequired::ProtocolRequired(int required, int current)
{
	this->requiredVersion = required;
	this->currentVersion = current;
}

ushort ProtocolRequired::getId()
{
	return id;
}

std::string ProtocolRequired::getName()
{
	return "ProtocolRequired";
}
void ProtocolRequired::serialize(BinaryWriter& writer)
{
	writer.writeInt(this->requiredVersion);
	writer.writeInt(this->currentVersion);
}

void ProtocolRequired::deserialize(BinaryReader& reader)
{
	this->requiredVersion = reader.readInt();
	this->currentVersion = reader.readInt();
}