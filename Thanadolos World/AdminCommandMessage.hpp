#pragma once
#ifndef ADMINCOMMANDMESSAGE_THANADOLOS_HPP
#define ADMINCOMMANDMESSAGE_THANADOLOS_HPP

#include "imessage.h"


class AdminCommandMessage : public IMessage
{
public:
	AdminCommandMessage(std::string content);
	AdminCommandMessage();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 76;

	/*VARS*/
	std::string content;
};


#endif