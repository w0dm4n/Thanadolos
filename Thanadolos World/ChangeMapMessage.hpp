#pragma once
#ifndef CHANGEMAPMESSAGE_THANADOLOS_HPP
#define CHANGEMAPMESSAGE_THANADOLOS_HPP

#include "imessage.h"

class ChangeMapMessage : public IMessage
{
public:
	ChangeMapMessage(int mapId);
	ChangeMapMessage();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 221;

	/*VARS*/
	int mapId;
};


#endif