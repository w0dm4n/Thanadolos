#pragma once
#ifndef RELOGINTOKENSTATUSMESSAGE_HPP
#define RELOGINTOKENSTATUSMESSAGE_HPP

#include "imessage.h"

class ReloginTokenStatusMessage : public IMessage
{
public:
	ReloginTokenStatusMessage(bool validToken, std::string ticket);
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 6539;

	/*VARS*/
	bool validToken;
	std::string ticket;
};


#endif