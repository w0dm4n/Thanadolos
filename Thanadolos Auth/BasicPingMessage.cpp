#include "BasicPingMessage.hpp"

BasicPingMessage::BasicPingMessage()
{
	
}

ushort BasicPingMessage::getId()
{
	return id;
}

std::string BasicPingMessage::getName()
{
	return "BasicPingMessage";
}
void BasicPingMessage::serialize(BinaryWriter& writer)
{
	writer.writeBool(quiet);
}

void BasicPingMessage::deserialize(BinaryReader& reader)
{
	this->quiet = reader.readBool();
}