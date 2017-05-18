#include "ServerSelectionMessage.hpp"

ServerSelectionMessage::ServerSelectionMessage(
	short _serverId
)
{
	serverId = _serverId;
}

ushort ServerSelectionMessage::getId()
{
	return id;
}

std::string ServerSelectionMessage::getName()
{
	return "ServerSelectionMessage";
}

void ServerSelectionMessage::serialize(BinaryWriter& writer)
{
	writer.writeVarShort(this->serverId);
}

void ServerSelectionMessage::deserialize(BinaryReader& reader)
{
	this->serverId = reader.readVarShort();
}