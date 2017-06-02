#pragma once
#ifndef PROTOCOLREQUIRED_HPP
#define PROTOCOLREQUIRED_HPP

#include "imessage.h"

class ProtocolRequired : public IMessage
{
public:
	ProtocolRequired(int required, int current);
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 1;

	/*VARS*/
	int requiredVersion;
	int currentVersion;
};


#endif