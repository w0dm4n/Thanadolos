#include "Globals.h"
#include "AuthenticationTicketAcceptedMessage.hpp"
#include <iostream>

AuthenticationTicketAcceptedMessage::AuthenticationTicketAcceptedMessage()
{

}

ushort AuthenticationTicketAcceptedMessage::getId()
{
	return id;
}

std::string AuthenticationTicketAcceptedMessage::getName()
{
	return "AuthenticationTicketAcceptedMessage";
}
void AuthenticationTicketAcceptedMessage::serialize(BinaryWriter& writer)
{
	
}

void AuthenticationTicketAcceptedMessage::deserialize(BinaryReader& reader)
{

}