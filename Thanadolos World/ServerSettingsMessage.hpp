#pragma once
#ifndef SERVERSETTINGSMESSAGE_HPP
#define SERVERSETTINGSMESSAGE_HPP

#include "imessage.h"

class ServerSettingsMessage : public IMessage
{
public:
	ServerSettingsMessage(std::string lang,
		uint community,
		int gameType,
		int arenaLeaveBanTime);
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 6340;

	/*VARS*/
	std::string lang;
	uint community;
	int gameType;
	int arenaLeaveBanTime;
};


#endif