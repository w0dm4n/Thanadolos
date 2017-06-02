#include "Globals.h"
#include "ServerSettingsMessage.hpp"
#include <iostream>

ServerSettingsMessage::ServerSettingsMessage(std::string lang,
uint community,
int gameType,
int arenaLeaveBanTime)
{
	this->lang = lang;
	this->community = community;
	this->gameType = gameType;
	this->arenaLeaveBanTime = arenaLeaveBanTime;
}

ushort ServerSettingsMessage::getId()
{
	return id;
}

std::string ServerSettingsMessage::getName()
{
	return "ServerSettingsMessage";
}
void ServerSettingsMessage::serialize(BinaryWriter& writer)
{
	writer.writeUTF(this->lang);
	writer.writeByte(this->community);
	writer.writeByte(this->gameType);
	writer.writeVarShort(this->arenaLeaveBanTime);
}

void ServerSettingsMessage::deserialize(BinaryReader& reader)
{
	//idc
}