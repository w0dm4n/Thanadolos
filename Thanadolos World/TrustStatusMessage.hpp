#pragma once
#ifndef TRUSTSTATUSMESSAGE_HPP
#define TRUSTSTATUSMESSAGE_HPP

#include "imessage.h"

class TrustStatusMessage : public IMessage
{
public:
	TrustStatusMessage(bool trusted, bool certified);
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 6267;

	/*VARS*/
	bool trusted;
	bool certified;
};


#endif