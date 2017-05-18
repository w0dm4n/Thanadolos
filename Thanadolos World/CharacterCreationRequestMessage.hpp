#pragma once
#ifndef CHARACTERCREATIONREQUESTMESSAGE_HPP
#define CHARACTERCREATIONREQUESTMESSAGE_HPP

#include "imessage.h"

class CharacterCreationRequestMessage : public IMessage
{
public:
	CharacterCreationRequestMessage(std::string name,
		int breed,
		bool sex,
		std::vector<int> colors,
		uint cosmeticId);
	CharacterCreationRequestMessage();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 160;

	/*VARS*/
	std::string name;
	int breed;
	bool sex;
	std::vector<int> colors;
	uint cosmeticId;
};


#endif