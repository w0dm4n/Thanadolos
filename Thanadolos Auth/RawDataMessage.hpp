#pragma once
#pragma once
#pragma once
#ifndef RAWDATAMESSAGE_HPP
#define RAWDATAMESSAGE_HPP

#include "imessage.h"

class RawDataMessage : public IMessage
{
public:
	RawDataMessage(ByteArray &content);
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 6253;

	/*VARS*/
	ByteArray content;
};


#endif