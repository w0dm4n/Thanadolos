#pragma once
#ifndef AUTHENTICATIONTICKETMESSAGE_HPP
#define AUTHENTICATIONTICKETMESSAGE_HPP

#include "imessage.h"

class AuthenticationTicketMessage : public IMessage
{
public:
	AuthenticationTicketMessage(std::string lang, std::string ticket);
	AuthenticationTicketMessage() {}
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 110;

	/*VARS*/
	std::string lang;
	std::string ticket;
};


#endif