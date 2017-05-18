#pragma once
#ifndef CHARACTERNAMESUGGESTIONREQUESTMESSAGE_HPP
#define CHARACTERNAMESUGGESTIONREQUESTMESSAGE_HPP

#include "imessage.h"

class CharacterNameSuggestionRequestMessage : public IMessage
{
public:
	CharacterNameSuggestionRequestMessage();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 162;

	/*VARS*/
};


#endif