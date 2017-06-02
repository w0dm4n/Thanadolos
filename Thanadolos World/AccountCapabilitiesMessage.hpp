#pragma once
#ifndef ACCOUNTCAPABILITIESMESSAGE_HPP
#define ACCOUNTCAPABILITIESMESSAGE_HPP

#include "imessage.h"

class AccountCapabilitiesMessage : public IMessage
{
public:
	AccountCapabilitiesMessage(uint accountId,
	bool tutorialAvailable,
	uint breedsVisible,
	uint breedsAvailable,
	int status,
	bool canCreateNewCharacter);
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 6216;

	/*VARS*/
	uint accountId;
	bool tutorialAvailable;
	uint breedsVisible;
	uint breedsAvailable;
	int status;
	bool canCreateNewCharacter;
};


#endif