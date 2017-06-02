#pragma once
#ifndef CHATCLIENTPRIVATEMESSAGE_THANADOLOS_HPP
#define CHATCLIENTPRIVATEMESSAGE_THANADOLOS_HPP

#include "imessage.h"
#include "ChatAbstractClientMessage.hpp"

class ChatClientPrivateMessage : public ChatAbstractClientMessage
{
public:
	ChatClientPrivateMessage(std::string content, std::string receiver);
	ChatClientPrivateMessage();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 851;

	/*VARS*/
	std::string receiver;
};


#endif