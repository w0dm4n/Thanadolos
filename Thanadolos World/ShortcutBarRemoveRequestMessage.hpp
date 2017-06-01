#pragma once
#ifndef SHORTCUTBARREMOVEREQUESTMESSAGE_THANADOLOS_HPP
#define SHORTCUTBARREMOVEREQUESTMESSAGE_THANADOLOS_HPP

#include "imessage.h"


class ShortcutBarRemoveRequestMessage : public IMessage
{
public:
	ShortcutBarRemoveRequestMessage(int barType, int slot);
	ShortcutBarRemoveRequestMessage();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 6228;

	/*VARS*/
	int barType;
	int slot;
};


#endif