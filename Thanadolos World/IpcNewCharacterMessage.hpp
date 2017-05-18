#pragma once
#ifndef IPCNEWCHARACTERMESSAGE_HPP
#define IPCNEWCHARACTERMESSAGE_HPP

#include "IMessage.h"

class IpcNewCharacterMessage : public IMessage
{
public:
	IpcNewCharacterMessage(int accountId, int serverId);

	IpcNewCharacterMessage() { }

	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 667;

	/* VARIABLES */
	int accountId;
	int serverId;
};


#endif