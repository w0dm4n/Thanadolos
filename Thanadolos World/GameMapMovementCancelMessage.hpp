#pragma once
#ifndef GAMEMAPMOVEMENTCANCELMESSAGE_THANADOLOS_HPP
#define GAMEMAPMOVEMENTCANCELMESSAGE_THANADOLOS_HPP

#include "imessage.h"


class GameMapMovementCancelMessage : public IMessage
{
public:
	GameMapMovementCancelMessage(int cellId);
	GameMapMovementCancelMessage();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 953;

	/*VARS*/
	int cellId;
};


#endif