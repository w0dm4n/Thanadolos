#pragma once
#ifndef NOTIFICATIONLISTMESSAGE_THANADOLOS_HPP
#define NOTIFICATIONLISTMESSAGE_THANADOLOS_HPP

#include "imessage.h"


class NotificationListMessage : public IMessage
{
public:
	NotificationListMessage(ByteArray flags);
	NotificationListMessage();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 6087;

	/*VARS*/
	ByteArray flags;
};


#endif