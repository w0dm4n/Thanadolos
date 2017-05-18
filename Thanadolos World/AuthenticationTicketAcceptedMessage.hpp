#pragma once
#pragma once
#ifndef AUTHENTICATIONTICKETACCEPTEDMESSAGE_HPP
#define AUTHENTICATIONTICKETACCEPTEDMESSAGE_HPP

#include "imessage.h"

class AuthenticationTicketAcceptedMessage : public IMessage
{
public:
	AuthenticationTicketAcceptedMessage();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 111;

	/*VARS*/
};


#endif