#include "Globals.h"
#include "IpcNewCharacterMessage.hpp"

IpcNewCharacterMessage::IpcNewCharacterMessage(int accountId, int serverId)
{
	this->accountId = accountId;
	this->serverId = serverId;
}

ushort IpcNewCharacterMessage::getId()
{
	return id;
}

std::string IpcNewCharacterMessage::getName()
{
	return "IpcNewCharacterMessage";
}

void IpcNewCharacterMessage::serialize(BinaryWriter& writer)
{
	writer.writeInt(this->accountId);
	writer.writeInt(this->serverId);
}

void IpcNewCharacterMessage::deserialize(BinaryReader& reader)
{
	this->accountId = reader.readInt();
	this->serverId = reader.readInt();
}