#pragma once
#ifndef STATSUPGRADEREQUESTMESSAGE_THANADOLOS_HPP
#define STATSUPGRADEREQUESTMESSAGE_THANADOLOS_HPP

#include "imessage.h"


class StatsUpgradeRequestMessage : public IMessage
{
public:
	StatsUpgradeRequestMessage(bool useAdditionnal, int statId, int boostPoint);
	StatsUpgradeRequestMessage();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 5610;

	/*VARS*/
	bool useAdditionnal;
	int statId;
	int boostPoint;
};


#endif