#pragma once
#ifndef GAMEMAPMOVEMENTMESSAGE_THANADOLOS_HPP
#define GAMEMAPMOVEMENTMESSAGE_THANADOLOS_HPP

#include "imessage.h"


class GameMapMovementMessage : public IMessage
{
public:
	GameMapMovementMessage(std::vector<uint> keyMovements, int forcedDirection, int actorId);
	GameMapMovementMessage();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 951;

	/*VARS*/
	std::vector<uint> keyMovements;
	int forcedDirection;
	Int64 actorId;
};


#endif