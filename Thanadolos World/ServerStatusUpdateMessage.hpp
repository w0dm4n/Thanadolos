#pragma once
#pragma once
#ifndef SERVERSTATUSUPDATEMESSAGE_HPP
#define SERVERSTATUSUPDATEMESSAGE_HPP

#include "imessage.h"
#include "GameServerInformations.hpp"

class ServerStatusUpdateMessage : public IMessage
{
public:
	ServerStatusUpdateMessage(GameServerInformations _informations);
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 50;

	/*VARS*/
	GameServerInformations informations;
};


#endif