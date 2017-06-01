#pragma once
#ifndef SHORTCUTBARCONTENTMESSAGE_THANADOLOS_HPP
#define SHORTCUTBARCONTENTMESSAGE_THANADOLOS_HPP

#include "imessage.h"
#include "Shortcut.hpp"

class ShortcutBarContentMessage : public IMessage
{
public:
	ShortcutBarContentMessage(int barType, std::vector<Shortcut*> shortcuts);
	ShortcutBarContentMessage();
	~ShortcutBarContentMessage();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 6231;

	/*VARS*/
	int barType;
	std::vector<Shortcut*> shortcuts;
};


#endif