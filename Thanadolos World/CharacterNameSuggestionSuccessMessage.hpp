#pragma once
#ifndef CHARACTERNAMESUGGESTIONSUCCESSMESSAGE_HPP
#define CHARACTERNAMESUGGESTIONSUCCESSMESSAGE_HPP

#include "imessage.h"

class CharacterNameSuggestionSuccessMessage : public IMessage
{
public:
	CharacterNameSuggestionSuccessMessage(std::string suggestion);
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 5544;

	/*VARS*/
	std::string suggestion;
};


#endif