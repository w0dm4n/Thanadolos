#pragma once
#ifndef CHATABSTRACTCLIENTMESSAGE_THANADOLOS_HPP
#define CHATABSTRACTCLIENTMESSAGE_THANADOLOS_HPP

#include "imessage.h"


class ChatAbstractClientMessage : public IMessage
{
public:
	ChatAbstractClientMessage(std::string content);
	ChatAbstractClientMessage();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 850;

	/*VARS*/
	std::string content;
};


#endif