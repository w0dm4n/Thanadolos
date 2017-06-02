#pragma once
#ifndef CURRENTMAPMESSAGE_THANADOLOS_HPP
#define CURRENTMAPMESSAGE_THANADOLOS_HPP

#include "imessage.h"


class CurrentMapMessage : public IMessage
{
public:
	CurrentMapMessage(int mapId, std::string mapKey);
	CurrentMapMessage();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 220;

	/*VARS*/
	int mapId;
	std::string mapKey;
};


#endif