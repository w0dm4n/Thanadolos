#pragma once
#ifndef SERVEROPTIONALFEATURESMESSAGE_HPP
#define SERVEROPTIONALFEATURESMESSAGE_HPP

#include "imessage.h"

class ServerOptionalFeaturesMessage : public IMessage
{
public:
	ServerOptionalFeaturesMessage(ByteArray features);
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 6305;

	/*VARS*/
	ByteArray features;
};


#endif