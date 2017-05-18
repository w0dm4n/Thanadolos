#pragma once
#pragma once
#ifndef IDENTIFICATIONFAILEDMESSAGE_HPP
#define IDENTIFICATIONFAILEDMESSAGE_HPP

#include "imessage.h"
#include "VersionExtended.hpp"

class IdentificationFailedMessage : public IMessage
{
public:
	IdentificationFailedMessage(uint reason);

	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 20;

	/* VARS */
	uint reason;
};


#endif 