#include "Globals.h"
#include "ShortcutObjectItem.hpp"

ShortcutObjectItem::ShortcutObjectItem(int slotId, int itemUID, int itemGID) : Shortcut(slotId)
{
	this->itemUID = itemUID;
	this->itemGID = itemGID;

}

ShortcutObjectItem::ShortcutObjectItem()
{

}

ushort ShortcutObjectItem::getId()
{
	return __id;
}

std::string ShortcutObjectItem::getName()
{
	return "ShortcutObjectItem";
}

void ShortcutObjectItem::serialize(BinaryWriter& writer)
{
	Shortcut::serialize(writer);
	writer.writeInt(this->itemUID);	writer.writeInt(this->itemGID);
}

void ShortcutObjectItem::deserialize(BinaryReader& reader)
{
	{		Shortcut::deserialize(reader);		this->itemUID = reader.readInt();		this->itemGID = reader.readInt();	}
}