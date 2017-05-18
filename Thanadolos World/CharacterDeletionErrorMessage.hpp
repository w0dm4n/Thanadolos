#pragma once
#ifndef CHARACTEDELETIONERRORMESSAGE_HPP
#define CHARACTEDELETIONERRORMESSAGE_HPP

#include "imessage.h"

class CharacterDeletionErrorMessage : public IMessage
{
public:
	CharacterDeletionErrorMessage(uint reason);
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 166;

	/*VARS*/
	uint reason;
};


#endif