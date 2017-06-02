#pragma once
#ifndef GAMECONTEXTREMOVEELEMENTMESSAGE_THANADOLOS_HPP
#define GAMECONTEXTREMOVEELEMENTMESSAGE_THANADOLOS_HPP

#include "imessage.h"


class GameContextRemoveElementMessage : public IMessage
{
public:
	GameContextRemoveElementMessage(Int64 id);
	GameContextRemoveElementMessage();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 251;

	/*VARS*/
	Int64 id_actor;
};


#endif