#pragma once
#ifndef STATSUPGRADERESULTMESSAGE_THANADOLOS_HPP
#define STATSUPGRADERESULTMESSAGE_THANADOLOS_HPP

#include "imessage.h"


class StatsUpgradeResultMessage : public IMessage
{
public:
	StatsUpgradeResultMessage(int result, int nbCharacBoost);
	StatsUpgradeResultMessage();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 5609;

	/*VARS*/
	int result;
	int nbCharacBoost;
};


#endif