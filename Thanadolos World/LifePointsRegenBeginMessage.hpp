#pragma once
#ifndef LIFEPOINTSREGENBEGINMESSAGE_THANADOLOS_HPP
#define LIFEPOINTSREGENBEGINMESSAGE_THANADOLOS_HPP

#include "imessage.h"

class LifePointsRegenBeginMessage : public IMessage
{
public:
	LifePointsRegenBeginMessage(int regenRate);
	LifePointsRegenBeginMessage();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 5684;

	/*VARS*/
	int regenRate;
};


#endif