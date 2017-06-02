#include "HelloConnectMessage.hpp"
#include <iostream>

HelloConnectMessage::HelloConnectMessage(std::string salt, int key)
{
	this->salt = salt;
	this->key = key;
}

ushort HelloConnectMessage::getId()
{
	return id;
}

std::string HelloConnectMessage::getName()
{
	return "HelloConnectMessage";
}
void HelloConnectMessage::serialize(BinaryWriter& writer)
{
	writer.writeUTF(this->salt);
	writer.writeVarInt(this->key);
	for (int i = 0;i < 303; i++)
	{
		writer.writeByte(i);
	}
}

void HelloConnectMessage::deserialize(BinaryReader& reader)
{
	this->salt = reader.readUTF();
	this->key = reader.readInt();
}