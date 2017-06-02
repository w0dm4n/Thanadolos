#pragma once
#ifndef FIGHTERSTATSLISTMESSAGE_THANADOLOS_HPP
#define FIGHTERSTATSLISTMESSAGE_THANADOLOS_HPP

#include "imessage.h"
#include "CharacterCharacteristicsInformations.hpp" 


class FighterStatsListMessage : public IMessage
{
public:
	FighterStatsListMessage(CharacterCharacteristicsInformations& stats);
	FighterStatsListMessage();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 6322;

	/*VARS*/
	CharacterCharacteristicsInformations stats;
};


#endif