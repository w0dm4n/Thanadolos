#pragma once
#ifndef GAMECONTEXTCREATEREQUESTMESSAGE_THANADOLOS_HPP
#define GAMECONTEXTCREATEREQUESTMESSAGE_THANADOLOS_HPP

#include "imessage.h"


class GameContextCreateRequestMessage : public IMessage
{
public:
	GameContextCreateRequestMessage();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 250;

	/*VARS*/

};


#endif