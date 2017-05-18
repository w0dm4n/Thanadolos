#pragma once
#pragma once
#ifndef SERVERSELECTIONMESSAGE_HPP
#define SERVERSELECTIONMESSAGE_HPP

#include "IMessage.h"

class ServerSelectionMessage : public IMessage
{
public:
	ServerSelectionMessage(
		short _serverid
	);
	ServerSelectionMessage() { };

	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 40;

	/* VARIABLES */
	short serverId;
};


#endif