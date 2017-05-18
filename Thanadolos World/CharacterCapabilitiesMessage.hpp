#pragma once
#ifndef CHARACTERCAPABILITIESMESSAGE_THANADOLOS_HPP
#define CHARACTERCAPABILITIESMESSAGE_THANADOLOS_HPP

#include "imessage.h"


class CharacterCapabilitiesMessage : public IMessage
{
public:
	CharacterCapabilitiesMessage(int guildEmblemSymbolCategories);
	CharacterCapabilitiesMessage();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 6339;

	/*VARS*/
	int guildEmblemSymbolCategories;
};


#endif