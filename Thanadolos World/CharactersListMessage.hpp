#pragma once
#ifndef CHARACTERSLISTMESSAGE_HPP
#define CHARACTERSLISTMESSAGE_HPP

#include "imessage.h"
#include "BasicCharactersListMessage.hpp"

class CharactersListMessage : public BasicCharactersListMessage
{
public:
	CharactersListMessage(std::vector<CharacterBaseInformations> characters, bool hasStartupActions);
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 151;

	/*VARS*/
	bool hasStartupActions;
};


#endif