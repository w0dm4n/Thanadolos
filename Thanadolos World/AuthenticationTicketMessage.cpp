#include "Globals.h"
#include "AuthenticationTicketMessage.hpp"
#include <iostream>

AuthenticationTicketMessage::AuthenticationTicketMessage(std::string lang, std::string ticket)
{
	this->lang = lang;
	this->ticket = ticket;
}

ushort AuthenticationTicketMessage::getId()
{
	return id;
}

std::string AuthenticationTicketMessage::getName()
{
	return "AuthenticationTicketMessage";
}
void AuthenticationTicketMessage::serialize(BinaryWriter& writer)
{
	writer.writeUTF(this->lang);
	writer.writeUTF(this->ticket);
}

void AuthenticationTicketMessage::deserialize(BinaryReader& reader)
{
	this->lang = reader.readUTF();
	this->ticket = reader.readUTF();
}