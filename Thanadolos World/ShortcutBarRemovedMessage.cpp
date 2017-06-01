#include "Globals.h"
#include "ShortcutBarRemovedMessage.hpp"

ShortcutBarRemovedMessage::ShortcutBarRemovedMessage(int barType, int slot)
{
	this->barType = barType;
	this->slot = slot;

}

ShortcutBarRemovedMessage::ShortcutBarRemovedMessage()
{

}

ushort ShortcutBarRemovedMessage::getId()
{
	return id;
}

std::string ShortcutBarRemovedMessage::getName()
{
	return "ShortcutBarRemovedMessage";
}

void ShortcutBarRemovedMessage::serialize(BinaryWriter& writer)
{
	writer.writeByte(this->barType);	writer.writeByte(this->slot);
}

void ShortcutBarRemovedMessage::deserialize(BinaryReader& reader)
{
	{		this->barType = reader.readByte();		this->slot = reader.readByte();	}
}