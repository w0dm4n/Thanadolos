#include "Globals.h"
#include "ChatAbstractServerMessage.hpp"

ChatAbstractServerMessage::ChatAbstractServerMessage(int channel, std::string content, int timestamp, std::string fingerprint)
{
	this->channel = channel;
	this->content = content;
	this->timestamp = timestamp;
	this->fingerprint = fingerprint;

}

ChatAbstractServerMessage::ChatAbstractServerMessage()
{

}

ushort ChatAbstractServerMessage::getId()
{
	return id;
}

std::string ChatAbstractServerMessage::getName()
{
	return "ChatAbstractServerMessage";
}

void ChatAbstractServerMessage::serialize(BinaryWriter& writer)
{
	writer.writeByte(this->channel);	writer.writeUTF(this->content);	writer.writeInt(this->timestamp);	writer.writeUTF(this->fingerprint);
}

void ChatAbstractServerMessage::deserialize(BinaryReader& reader)
{
	{		this->channel = reader.readByte();		this->content = reader.readUTF();		this->timestamp = reader.readInt();		this->fingerprint = reader.readUTF();	}
}