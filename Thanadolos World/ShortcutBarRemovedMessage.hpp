#pragma once
#ifndef SHORTCUTBARREMOVEDMESSAGE_THANADOLOS_HPP
#define SHORTCUTBARREMOVEDMESSAGE_THANADOLOS_HPP

#include "imessage.h"


class ShortcutBarRemovedMessage : public IMessage
{
public:
	ShortcutBarRemovedMessage(int barType, int slot);
	ShortcutBarRemovedMessage();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 6224;

	/*VARS*/
	int barType;
	int slot;
};


#endif