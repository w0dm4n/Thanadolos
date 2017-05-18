#pragma once
#ifndef LIFEPOINTSREGENENDMESSAGE_THANADOLOS_HPP
#define LIFEPOINTSREGENENDMESSAGE_THANADOLOS_HPP

#include "imessage.h"
#include "UpdateLifePointsMessage.hpp"

class LifePointsRegenEndMessage : public UpdateLifePointsMessage
{
public:
	LifePointsRegenEndMessage(int lifePoints, int maxLifePoints, int lifePointsGained);
	LifePointsRegenEndMessage();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 5686;

	/*VARS*/
	int lifePointsGained;
};


#endif