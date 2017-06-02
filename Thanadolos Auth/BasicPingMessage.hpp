#pragma once
#ifndef BASICPINGMESSAGE_HPP
#define BASICPINGMESSAGE_HPP

#include "imessage.h"

class BasicPingMessage : public IMessage
{
public:
	BasicPingMessage();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 182;

	/*VARS*/
	bool quiet;
};


#endif