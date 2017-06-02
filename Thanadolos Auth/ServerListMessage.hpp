#pragma once
#ifndef SERVERLISTMESSAGE_HPP
#define SERVERLISTMESSAGE_HPP

#include "IMessage.h"
#include "GameServerInformations.hpp"

class ServerListMessage : public IMessage
{
public:
	ServerListMessage(
		std::vector<GameServerInformations> _servers,
		uint _alreadyConnectedToServerId = 0,
		bool _canCreateNewCharacter = true
	);

	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 30;

	/* VARIABLES */

	std::vector<GameServerInformations> servers;
	uint alreadyConnectedToServerId;
	bool canCreateNewCharacter;
};


#endif