#pragma once
#ifndef UPDATELIFEPOINTSMESSAGE_THANADOLOS_HPP
#define UPDATELIFEPOINTSMESSAGE_THANADOLOS_HPP

#include "imessage.h"


class UpdateLifePointsMessage : public IMessage
{
public:
	UpdateLifePointsMessage(int lifePoints, int maxLifePoints);
	UpdateLifePointsMessage();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 5658;

	/*VARS*/
	int lifePoints;
	int maxLifePoints;
};


#endif