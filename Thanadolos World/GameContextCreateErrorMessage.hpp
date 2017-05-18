#pragma once
#ifndef GAMECONTEXTCREATEERRORMESSAGE_THANADOLOS_HPP
#define GAMECONTEXTCREATEERRORMESSAGE_THANADOLOS_HPP

#include "imessage.h"


class GameContextCreateErrorMessage : public IMessage
{
public:
	GameContextCreateErrorMessage();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 6024;

	/*VARS*/

};


#endif