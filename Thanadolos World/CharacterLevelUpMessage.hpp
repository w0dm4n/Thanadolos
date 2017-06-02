#pragma once
#ifndef CHARACTERLEVELUPMESSAGE_THANADOLOS_HPP
#define CHARACTERLEVELUPMESSAGE_THANADOLOS_HPP

#include "imessage.h"


class CharacterLevelUpMessage : public IMessage
{
public:
	CharacterLevelUpMessage(int newLevel);
	CharacterLevelUpMessage();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 5670;

	/*VARS*/
	int newLevel;
};


#endif