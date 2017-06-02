#pragma once
#ifndef GAMECONTEXTDESTROYMESSAGE_THANADOLOS_HPP
#define GAMECONTEXTDESTROYMESSAGE_THANADOLOS_HPP

#include "imessage.h"


class GameContextDestroyMessage : public IMessage
{
public:
	GameContextDestroyMessage();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 201;

	/*VARS*/

};


#endif