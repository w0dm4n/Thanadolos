#include "IpcDeletedCharacterMessage.hpp"

IpcDeletedCharacterMessage::IpcDeletedCharacterMessage(int accountId, int serverId)
{
	this->accountId = accountId;
	this->serverId = serverId;
}

ushort IpcDeletedCharacterMessage::getId()
{
	return id;
}

std::string IpcDeletedCharacterMessage::getName()
{
	return "IpcDeletedCharacterMessage";
}

void IpcDeletedCharacterMessage::serialize(BinaryWriter& writer)
{
	writer.writeInt(this->accountId);
	writer.writeInt(this->serverId);
}

void IpcDeletedCharacterMessage::deserialize(BinaryReader& reader)
{
	this->accountId = reader.readInt();
	this->serverId = reader.readInt();
}