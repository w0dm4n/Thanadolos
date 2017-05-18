#include "Globals.h"
#include "ChatServerCopyMessage.hpp"

ChatServerCopyMessage::ChatServerCopyMessage(int channel, std::string content, int timestamp, std::string fingerprint, int receiverId, std::string receiverName) : ChatAbstractServerMessage(channel, content, timestamp, fingerprint)
{
	this->receiverId = receiverId;
	this->receiverName = receiverName;

}

ChatServerCopyMessage::ChatServerCopyMessage()
{

}

ushort ChatServerCopyMessage::getId()
{
	return id;
}

std::string ChatServerCopyMessage::getName()
{
	return "ChatServerCopyMessage";
}

void ChatServerCopyMessage::serialize(BinaryWriter& writer)
{
	ChatAbstractServerMessage::serialize(writer);
	writer.writeVarLong(this->receiverId);	writer.writeUTF(this->receiverName);
}

void ChatServerCopyMessage::deserialize(BinaryReader& reader)
{
	{		ChatAbstractServerMessage::deserialize(reader);		this->receiverId = reader.readVarUhLong();		this->receiverName = reader.readUTF();	}
}