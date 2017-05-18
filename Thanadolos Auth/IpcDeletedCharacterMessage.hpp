#pragma once
#ifndef IPCDELETEDHARACTERMESSAGE_HPP
#define IPCDELETEDHARACTERMESSAGE_HPP

#include "IMessage.h"

class IpcDeletedCharacterMessage : public IMessage
{
public:
	IpcDeletedCharacterMessage(int accountId, int serverId);

	IpcDeletedCharacterMessage() { }

	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 668;

	/* VARIABLES */
	int accountId;
	int serverId;
};


#endif