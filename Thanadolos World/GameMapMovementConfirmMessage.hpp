#pragma once
#ifndef GAMEMAPMOVEMENTCONFIRMMESSAGE_THANADOLOS_HPP
#define GAMEMAPMOVEMENTCONFIRMMESSAGE_THANADOLOS_HPP

#include "imessage.h"


class GameMapMovementConfirmMessage : public IMessage
{
public:
	GameMapMovementConfirmMessage();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 952;

	/*VARS*/

};


#endif