#include "Globals.h"
#include "ServerStatusUpdateMessage.hpp"
#include <iostream>

ServerStatusUpdateMessage::ServerStatusUpdateMessage(GameServerInformations _informations)
{
	this->informations = _informations;
}

ushort ServerStatusUpdateMessage::getId()
{
	return id;
}

std::string ServerStatusUpdateMessage::getName()
{
	return "ServerStatusUpdateMessage";
}
void ServerStatusUpdateMessage::serialize(BinaryWriter& writer)
{
	this->informations.serialize(writer);
}

void ServerStatusUpdateMessage::deserialize(BinaryReader& reader)
{
	this->informations.deserialize(reader);
}