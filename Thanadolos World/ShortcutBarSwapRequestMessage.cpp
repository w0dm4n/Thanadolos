#include "Globals.h"
#include "ShortcutBarSwapRequestMessage.hpp"

ShortcutBarSwapRequestMessage::ShortcutBarSwapRequestMessage(int barType, int firstSlot, int secondSlot)
{
	this->barType = barType;
	this->firstSlot = firstSlot;
	this->secondSlot = secondSlot;

}

ShortcutBarSwapRequestMessage::ShortcutBarSwapRequestMessage()
{

}

ushort ShortcutBarSwapRequestMessage::getId()
{
	return id;
}

std::string ShortcutBarSwapRequestMessage::getName()
{
	return "ShortcutBarSwapRequestMessage";
}

void ShortcutBarSwapRequestMessage::serialize(BinaryWriter& writer)
{
	writer.writeByte(this->barType);	writer.writeByte(this->firstSlot);	writer.writeByte(this->secondSlot);
}

void ShortcutBarSwapRequestMessage::deserialize(BinaryReader& reader)
{
	{		this->barType = reader.readByte();		this->firstSlot = reader.readByte();		this->secondSlot = reader.readByte();	}
}