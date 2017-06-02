#pragma once
#ifndef CHARACTERCREATIONRESULTMESSAGE_HPP
#define CHARACTERCREATIONRESULTMESSAGE_HPP

#include "imessage.h"

class CharacterCreationResultMessage : public IMessage
{
public:
	CharacterCreationResultMessage(uint result);
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 161;

	/*VARS*/
	uint result;
};


#endif