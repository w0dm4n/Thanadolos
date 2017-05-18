#include "Globals.h"
#include "CharacterCapabilitiesMessage.hpp"

CharacterCapabilitiesMessage::CharacterCapabilitiesMessage(int guildEmblemSymbolCategories)
{
	this->guildEmblemSymbolCategories = guildEmblemSymbolCategories;

}

CharacterCapabilitiesMessage::CharacterCapabilitiesMessage()
{

}

ushort CharacterCapabilitiesMessage::getId()
{
	return id;
}

std::string CharacterCapabilitiesMessage::getName()
{
	return "CharacterCapabilitiesMessage";
}

void CharacterCapabilitiesMessage::serialize(BinaryWriter& writer)
{
	writer.writeVarInt(this->guildEmblemSymbolCategories);
}

void CharacterCapabilitiesMessage::deserialize(BinaryReader& reader)
{
	{		this->guildEmblemSymbolCategories = reader.readVarUhInt();	}
}