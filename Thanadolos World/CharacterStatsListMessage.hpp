#pragma once
#ifndef CHARACTERSTATSLISTMESSAGE_THANADOLOS_HPP
#define CHARACTERSTATSLISTMESSAGE_THANADOLOS_HPP

#include "imessage.h"
#include "CharacterCharacteristicsInformations.hpp" 

class CharacterStatsListMessage : public IMessage
{
public:
	CharacterStatsListMessage(CharacterCharacteristicsInformations& stats);
	CharacterStatsListMessage();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 500;

	/*VARS*/
	CharacterCharacteristicsInformations stats;
};


#endif