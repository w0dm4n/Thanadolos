#include "Globals.h"
#include "ShortcutBarContentMessage.hpp"

ShortcutBarContentMessage::ShortcutBarContentMessage(int barType, std::vector<Shortcut*> shortcuts)
{
	this->barType = barType;
	this->shortcuts = shortcuts;

}

ShortcutBarContentMessage::ShortcutBarContentMessage()
{

}

ShortcutBarContentMessage::~ShortcutBarContentMessage()
{
	for (int i = 0;i < this->shortcuts.size(); i++)
		delete this->shortcuts[i];
}

ushort ShortcutBarContentMessage::getId()
{
	return id;
}

std::string ShortcutBarContentMessage::getName()
{
	return "ShortcutBarContentMessage";
}

void ShortcutBarContentMessage::serialize(BinaryWriter& writer)
{
	writer.writeByte(this->barType);	writer.writeShort(this->shortcuts.size());	int _loc2_ = 0;
	while (_loc2_ < this->shortcuts.size())	{		writer.writeShort((this->shortcuts[_loc2_])->getId());		(this->shortcuts[_loc2_])->serialize(writer);		_loc2_++;	}
}

void ShortcutBarContentMessage::deserialize(BinaryReader& reader)
{
	{		int _loc4_ = 0;
		Shortcut *_loc5_ = new Shortcut();
		this->barType = reader.readByte();		int _loc2_ = reader.readUnsignedShort();		int _loc3_ = 0;
		while (_loc3_ < _loc2_)		{			_loc4_ = reader.readUnsignedShort();			_loc5_->deserialize(reader);			this->shortcuts.push_back(_loc5_);			_loc3_++;		}	}
}