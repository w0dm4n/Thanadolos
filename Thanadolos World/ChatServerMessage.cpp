#include "Globals.h"
#include "ChatServerMessage.hpp"

ChatServerMessage::ChatServerMessage(int channel, std::string content, int timestamp, std::string fingerprint, int senderId, std::string senderName, int senderAccountId) : ChatAbstractServerMessage(channel, content, timestamp, fingerprint)
{
	this->senderId = senderId;
	this->senderName = senderName;
	this->senderAccountId = senderAccountId;

}

ChatServerMessage::ChatServerMessage()
{

}

ushort ChatServerMessage::getId()
{
	return id;
}

std::string ChatServerMessage::getName()
{
	return "ChatServerMessage";
}

void ChatServerMessage::serialize(BinaryWriter& writer)
{
	ChatAbstractServerMessage::serialize(writer);
	writer.writeDouble(this->senderId.toNumber());	writer.writeUTF(this->senderName);	writer.writeInt(this->senderAccountId);
}

void ChatServerMessage::deserialize(BinaryReader& reader)
{
	{		ChatAbstractServerMessage::deserialize(reader);		this->senderId = reader.readInt64();		this->senderName = reader.readUTF();		this->senderAccountId = reader.readInt();	}
}