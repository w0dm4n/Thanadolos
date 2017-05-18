#include "Globals.h"
#include "NotificationListMessage.hpp"

NotificationListMessage::NotificationListMessage(ByteArray flags)
{
	this->flags = flags;

}

NotificationListMessage::NotificationListMessage()
{

}

ushort NotificationListMessage::getId()
{
	return id;
}

std::string NotificationListMessage::getName()
{
	return "NotificationListMessage";
}

void NotificationListMessage::serialize(BinaryWriter& writer)
{
	writer.writeShort(this->flags.size());	int _loc2_ = 0;
	while (_loc2_ < this->flags.size())	{		writer.writeVarInt(this->flags[_loc2_]);		_loc2_++;	}
}

void NotificationListMessage::deserialize(BinaryReader& reader)
{
	{		int _loc4_ = 0;
		int _loc2_ = reader.readUnsignedShort();		int _loc3_ = 0;
		while (_loc3_ < _loc2_)		{			_loc4_ = reader.readVarInt();			this->flags.push_back(_loc4_);			_loc3_++;		}	}
}