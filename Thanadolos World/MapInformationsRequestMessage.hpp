#pragma once
#ifndef MAPINFORMATIONSREQUESTMESSAGE_THANADOLOS_HPP
#define MAPINFORMATIONSREQUESTMESSAGE_THANADOLOS_HPP

#include "imessage.h"


class MapInformationsRequestMessage : public IMessage
{
public:
	MapInformationsRequestMessage(int mapId);
	MapInformationsRequestMessage();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 225;

	/*VARS*/
	int mapId;
};


#endif