#pragma once
#ifndef CHATCLIENTMULTIMESSAGE_THANADOLOS_HPP
#define CHATCLIENTMULTIMESSAGE_THANADOLOS_HPP

#include "imessage.h"
#include "ChatAbstractClientMessage.hpp"

class ChatClientMultiMessage : public ChatAbstractClientMessage
{
public:
	ChatClientMultiMessage(std::string content, int channel);
	ChatClientMultiMessage();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 861;

	/*VARS*/
	int channel;
};


#endif