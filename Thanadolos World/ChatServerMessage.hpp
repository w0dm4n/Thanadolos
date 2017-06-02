#pragma once
#ifndef CHATSERVERMESSAGE_THANADOLOS_HPP
#define CHATSERVERMESSAGE_THANADOLOS_HPP

#include "imessage.h"
#include "ChatAbstractServerMessage.hpp"

class ChatServerMessage : public ChatAbstractServerMessage
{
public:
	ChatServerMessage(int channel, std::string content, int timestamp, std::string fingerprint, int senderId, std::string senderName, int senderAccountId);
	ChatServerMessage();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 881;

	/*VARS*/
	Int64 senderId;
	std::string senderName;
	int senderAccountId;
};


#endif