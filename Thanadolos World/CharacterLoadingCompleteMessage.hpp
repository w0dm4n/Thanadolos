#pragma once
#ifndef CHARACTERLOADINGCOMPLETEMESSAGE_THANADOLOS_HPP
#define CHARACTERLOADINGCOMPLETEMESSAGE_THANADOLOS_HPP

#include "imessage.h"


class CharacterLoadingCompleteMessage : public IMessage
{
public:
	CharacterLoadingCompleteMessage();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 6471;

	/*VARS*/

};


#endif