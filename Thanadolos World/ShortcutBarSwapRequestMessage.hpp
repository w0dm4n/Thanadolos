#pragma once
#ifndef SHORTCUTBARSWAPREQUESTMESSAGE_THANADOLOS_HPP
#define SHORTCUTBARSWAPREQUESTMESSAGE_THANADOLOS_HPP

#include "imessage.h"


class ShortcutBarSwapRequestMessage : public IMessage
{
public:
	ShortcutBarSwapRequestMessage(int barType, int firstSlot, int secondSlot);
	ShortcutBarSwapRequestMessage();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 6230;

	/*VARS*/
	int barType;
	int firstSlot;
	int secondSlot;
};


#endif