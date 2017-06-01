#include "Globals.h"
#include "ShortcutBarRemoveRequestMessage.hpp"

ShortcutBarRemoveRequestMessage::ShortcutBarRemoveRequestMessage(int barType, int slot)
{
	this->barType = barType;
	this->slot = slot;

}

ShortcutBarRemoveRequestMessage::ShortcutBarRemoveRequestMessage()
{

}

ushort ShortcutBarRemoveRequestMessage::getId()
{
	return id;
}

std::string ShortcutBarRemoveRequestMessage::getName()
{
	return "ShortcutBarRemoveRequestMessage";
}

void ShortcutBarRemoveRequestMessage::serialize(BinaryWriter& writer)
{
	writer.writeByte(this->barType);	writer.writeByte(this->slot);
}

void ShortcutBarRemoveRequestMessage::deserialize(BinaryReader& reader)
{
	{		this->barType = reader.readByte();		this->slot = reader.readByte();	}
}