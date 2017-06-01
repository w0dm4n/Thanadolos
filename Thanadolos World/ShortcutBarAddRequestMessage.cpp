#include "Globals.h"
#include "ShortcutBarAddRequestMessage.hpp"


ShortcutBarAddRequestMessage::ShortcutBarAddRequestMessage(int barType, Shortcut *shortcut)
{
	this->barType = barType;
	this->shortcut = shortcut;

}

ShortcutBarAddRequestMessage::ShortcutBarAddRequestMessage()
{

}

ShortcutBarAddRequestMessage::~ShortcutBarAddRequestMessage()
{
	if (this->shortcut)
		delete this->shortcut;
}

ushort ShortcutBarAddRequestMessage::getId()
{
	return id;
}

std::string ShortcutBarAddRequestMessage::getName()
{
	return "ShortcutBarAddRequestMessage";
}

void ShortcutBarAddRequestMessage::serialize(BinaryWriter& writer)
{
	writer.writeByte(this->barType);	writer.writeShort(this->shortcut->getId());	this->shortcut->serialize(writer);
}

void ShortcutBarAddRequestMessage::deserialize(BinaryReader& reader)
{
	{		this->barType = reader.readByte();		int shortcutType = reader.readUnsignedShort();		switch (barType)		{			case ShortcutBarEnum::SPELL_SHORTCUT_BAR:				this->shortcut = new ShortcutSpell();			break;			case ShortcutBarEnum::GENERAL_SHORTCUT_BAR:				this->shortcut = new ShortcutObjectItem();			break;		}		if (this->shortcut)			this->shortcut->deserialize(reader);	}
}