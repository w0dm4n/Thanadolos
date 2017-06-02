#pragma once
#ifndef CHARACTERSELECTEDERRORMESSAGE_THANADOLOS_HPP
#define CHARACTERSELECTEDERRORMESSAGE_THANADOLOS_HPP

#include "imessage.h"


class CharacterSelectedErrorMessage : public IMessage
{
public:
	CharacterSelectedErrorMessage();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 5836;

	/*VARS*/

};


#endif