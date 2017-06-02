#pragma once
#ifndef CHARACTERDELETIONREQUESTMESSAGE_HPP
#define CHARACTERDELETIONREQUESTMESSAGE_HPP

#include "imessage.h"

class CharacterDeletionRequestMessage : public IMessage
{
public:
	CharacterDeletionRequestMessage(int characterId, std::string secretAnswerHash);
	CharacterDeletionRequestMessage();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 165;

	/*VARS*/
	int characterId;
	std::string secretAnswerHash;
};


#endif