#pragma once
#pragma once
#ifndef HELLOCONNECTMESSAGE_HPP
#define HELLOCONNECTMESSAGE_HPP

#include "imessage.h"

class HelloConnectMessage : public IMessage
{
public:
	HelloConnectMessage(std::string salt, int key);
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 3;

	/*VARS*/
	std::string salt;
	int key;
};


#endif