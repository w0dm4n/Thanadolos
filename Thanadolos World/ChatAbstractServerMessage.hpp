#pragma once
#ifndef CHATABSTRACTSERVERMESSAGE_THANADOLOS_HPP
#define CHATABSTRACTSERVERMESSAGE_THANADOLOS_HPP

#include "imessage.h"


class ChatAbstractServerMessage : public IMessage
{
public:
	ChatAbstractServerMessage(int channel, std::string content, int timestamp, std::string fingerprint);
	ChatAbstractServerMessage();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 880;

	/*VARS*/
	int channel;
	std::string content;
	int timestamp;
	std::string fingerprint;
};


#endif