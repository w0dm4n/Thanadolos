#include "RawDataMessage.hpp"
#include <iostream>

RawDataMessage::RawDataMessage(ByteArray &content)
{
	this->content = content;
}

ushort RawDataMessage::getId()
{
	return id;
}

std::string RawDataMessage::getName()
{
	return "RawDataMessage";
}
void RawDataMessage::serialize(BinaryWriter& writer)
{
	writer.writeVarInt(content.size());

	for (int i = 0; i < content.size(); ++i)
	{
		writer.writeByte(content[i]);
	}
}

void RawDataMessage::deserialize(BinaryReader& reader)
{
	// idc
}