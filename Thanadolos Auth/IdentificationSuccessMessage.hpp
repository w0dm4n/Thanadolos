#pragma once
#ifndef IDENTIFICATIONSUCCESSMESSAGE_HPP
#define IDENTIFICATIONSUCCESSMESSAGE_HPP

#include "imessage.h"
#include "VersionExtended.hpp"

class IdentificationSuccessMessage : public IMessage
{
public:
	IdentificationSuccessMessage(std::string _login, std::string _nickname, uint _accountId, uint _communityId,
		bool _hasRights, std::string _secretQuestion, double _accountCreation, double _subscriptionElapsedDuration,
		double _subscriptionEndDate, bool _wasAlreadyConnected, uint havenbagAvailableRoom);

	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 22;

	/* VARS */

	std::string login;
	std::string nickname;
	uint accountId;
	uint communityId;
	bool hasRights;
	std::string secretQuestion;
	double accountCreation;
	double subscriptionElapsedDuration;
	double subscriptionEndDate;
	bool wasAlreadyConnected;
	uint havenbagAvailableRoom;
};


#endif 