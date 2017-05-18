#include "Globals.h"
#include "ReloginTokenStatusMessage.hpp"
#include <iostream>

ReloginTokenStatusMessage::ReloginTokenStatusMessage(bool validToken, std::string ticket)
{
	this->validToken = validToken;
	this->ticket = ticket;
}

ushort ReloginTokenStatusMessage::getId()
{
	return id;
}

std::string ReloginTokenStatusMessage::getName()
{
	return "ReloginTokenStatusMessage";
}

void ReloginTokenStatusMessage::serialize(BinaryWriter& writer)
{
	writer.writeBool(this->validToken);
	writer.writeVarInt(this->ticket.length());
	int i = 0;
	while (i < this->ticket.length())
		writer.writeByte(this->ticket[i++]);
}

void ReloginTokenStatusMessage::deserialize(BinaryReader& reader)
{
	this->validToken = reader.readBool();
	int len = reader.readVarInt();
	int i = 0;
	while (i < len)
	{
		this->ticket += reader.readByte();
		i++;
	}
}