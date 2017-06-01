#pragma once
#ifndef SHORTCUTBARADDREQUESTMESSAGE_THANADOLOS_HPP
#define SHORTCUTBARADDREQUESTMESSAGE_THANADOLOS_HPP

#include "imessage.h"
#include "Shortcut.hpp"
#include "ShortcutBarEnum.hpp"
#include "ShortcutSpell.hpp"
#include "ShortcutObjectItem.hpp"

class ShortcutBarAddRequestMessage : public IMessage
{
public:
	ShortcutBarAddRequestMessage(int barType, Shortcut *shortcut);
	ShortcutBarAddRequestMessage();
	~ShortcutBarAddRequestMessage();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 6225;

	/*VARS*/
	int barType;
	Shortcut *shortcut;
};


#endif