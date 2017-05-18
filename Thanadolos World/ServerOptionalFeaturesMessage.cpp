#include "Globals.h"
#include "ServerOptionalFeaturesMessage.hpp"
#include <iostream>

ServerOptionalFeaturesMessage::ServerOptionalFeaturesMessage(ByteArray features)
{
	this->features = features;
}

ushort ServerOptionalFeaturesMessage::getId()
{
	return id;
}

std::string ServerOptionalFeaturesMessage::getName()
{
	return "ServerOptionalFeaturesMessage";
}

void ServerOptionalFeaturesMessage::serialize(BinaryWriter& writer)
{
	writer.writeShort(this->features.size());
	int i = 0;
	while (i < this->features.size())
		writer.writeByte(this->features[i++]);
}

void ServerOptionalFeaturesMessage::deserialize(BinaryReader& reader)
{
	//idc
}