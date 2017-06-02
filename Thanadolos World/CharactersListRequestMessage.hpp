#pragma once
#ifndef CHARACTERSLISTREQUESTMESSAGE_HPP
#define CHARACTERSLISTREQUESTMESSAGE_HPP

#include "imessage.h"

class CharactersListRequestMessage : public IMessage
{
public:
	CharactersListRequestMessage();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 150;

	/*VARS*/
};


#endif