#pragma once
#ifndef BASICCHARACTERSLISTMESSAGE_HPP
#define BASICCHARACTERSLISTMESSAGE_HPP

#include "imessage.h"
#include "CharacterBaseInformations.hpp"

class BasicCharactersListMessage : public IMessage
{
public:
	BasicCharactersListMessage(std::vector<CharacterBaseInformations> characters);
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 6475;

	/*VARS*/
	std::vector<CharacterBaseInformations> characters;
};


#endif