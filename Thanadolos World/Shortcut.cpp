#include "Globals.h"
#include "Shortcut.hpp"

Shortcut::Shortcut(int slot)
{
	this->slot = slot;

}

Shortcut::Shortcut()
{

}

ushort Shortcut::getId()
{
	return __id;
}

std::string Shortcut::getName()
{
	return "Shortcut";
}

void Shortcut::serialize(BinaryWriter& writer)
{
	writer.writeByte(this->slot);
}

void Shortcut::deserialize(BinaryReader& reader)
{
	{		this->slot = reader.readByte();	}
}