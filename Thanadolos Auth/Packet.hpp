#pragma once
#ifndef PACKET_HPP
#define PACKET_HPP

#include "imessage.h"
#include "BinaryReader.hpp"
#include "BinaryWriter.hpp"

class Packet
{
public:
	Packet();
	~Packet();

	void serialize(IMessage& message, ByteArray& buffer);
	bool deserialize(ByteArray& buffer);

	ushort id();
	uint length();
	ByteArray data();

private:
	ushort _header;
	ushort _id;
	ushort _lengthType;
	uint _length;
	ByteArray _data;

	ushort getMessageId(ushort header);
	ushort getMessageLengthType(ushort header);
	uint getMessageLength(ushort lengthType, BinaryReader& reader);
	ushort computeLengthType(uint length);
	ushort computeHeader(ushort id, ushort lengthType);
};
#endif 