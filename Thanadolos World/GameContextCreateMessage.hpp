#pragma once
#ifndef GAMECONTEXTCREATEMESSAGE_THANADOLOS_HPP
#define GAMECONTEXTCREATEMESSAGE_THANADOLOS_HPP

#include "imessage.h"


class GameContextCreateMessage : public IMessage
{
public:
	GameContextCreateMessage(int context);
	GameContextCreateMessage();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 200;

	/*VARS*/
	int context;
};


#endif