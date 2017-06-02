#pragma once
#ifndef CHARACTERSELECTEDSUCCESSMESSAGE_THANADOLOS_HPP
#define CHARACTERSELECTEDSUCCESSMESSAGE_THANADOLOS_HPP

#include "imessage.h"
#include "CharacterBaseInformations.hpp" 


class CharacterSelectedSuccessMessage : public IMessage
{
public:
	CharacterSelectedSuccessMessage(CharacterBaseInformations& infos, bool isCollectingStats);
	CharacterSelectedSuccessMessage();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 153;

	/*VARS*/
	CharacterBaseInformations infos;
	bool isCollectingStats;
};


#endif