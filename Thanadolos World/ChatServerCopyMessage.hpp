#pragma once
#ifndef CHATSERVERCOPYMESSAGE_THANADOLOS_HPP
#define CHATSERVERCOPYMESSAGE_THANADOLOS_HPP

#include "imessage.h"
#include "ChatAbstractServerMessage.hpp"

class ChatServerCopyMessage : public ChatAbstractServerMessage
{
public:
	ChatServerCopyMessage(int channel, std::string content, int timestamp, std::string fingerprint, int receiverId, std::string receiverName);
	ChatServerCopyMessage();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 882;

	/*VARS*/
	int receiverId;
	std::string receiverName;
};


#endif