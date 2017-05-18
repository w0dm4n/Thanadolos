#pragma once
#ifndef GAMEMAPMOVEMENTREQUESTMESSAGE_THANADOLOS_HPP
#define GAMEMAPMOVEMENTREQUESTMESSAGE_THANADOLOS_HPP

#include "imessage.h"


class GameMapMovementRequestMessage : public IMessage
{
public:
	GameMapMovementRequestMessage(std::vector<uint> keyMovements, int mapId);
	GameMapMovementRequestMessage();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 950;

	/*VARS*/
	std::vector<uint> keyMovements;
	int mapId;
};


#endif