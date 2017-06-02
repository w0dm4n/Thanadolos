#pragma once
#ifndef CHARACTERSELECTIONMESSAGE_HPP
#define CHARACTERSELECTIONMESSAGE_HPP

#include "imessage.h"

class CharacterSelectionMessage : public IMessage
{
public:
	CharacterSelectionMessage();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 152;

	/*VARS*/
	int characterId;
};


#endif