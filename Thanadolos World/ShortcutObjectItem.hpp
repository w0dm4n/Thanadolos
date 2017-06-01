#pragma once
#ifndef SHORTCUTOBJECTITEM_THANADOLOS_HPP
#define SHORTCUTOBJECTITEM_THANADOLOS_HPP

#include "IType.hpp"
#include "Shortcut.hpp"

class ShortcutObjectItem : public Shortcut
{
public:
	ShortcutObjectItem(int slotId, int itemUID, int itemGID);
	ShortcutObjectItem();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int __id = 371;

	/*VARS*/
	int itemUID;
	int itemGID;
};


#endif