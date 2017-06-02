#pragma once
#pragma once
#ifndef SELECTEDSERVERDATAMESSAGE_HPP
#define SELECTEDSERVERDATAMESSAGE_HPP

#include "IMessage.h"

class SelectedServerDataMessage : public IMessage
{
public:
	SelectedServerDataMessage(
		short _serverid,
		std::string _adress,
		short port,
		bool canCreateNewCharacter,
		std::string ticket
	);
	SelectedServerDataMessage() { };

	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 42;

	/* VARIABLES */
	short serverId;
	std::string address;
	short port;
	bool canCreateNewCharacter;
	std::string ticket;
};


#endif