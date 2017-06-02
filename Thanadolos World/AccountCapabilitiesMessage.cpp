#include "Globals.h"
#include "AccountCapabilitiesMessage.hpp"
#include <iostream>

AccountCapabilitiesMessage::AccountCapabilitiesMessage(uint accountId,
	bool tutorialAvailable,
	uint breedsVisible,
	uint breedsAvailable,
	int status,
	bool canCreateNewCharacter)
{
	this->accountId = accountId;
	this->tutorialAvailable = tutorialAvailable;
	this->breedsVisible = breedsVisible;
	this->breedsAvailable = breedsAvailable;
	this->status = status;
	this->canCreateNewCharacter = canCreateNewCharacter;
}

ushort AccountCapabilitiesMessage::getId()
{
	return id;
}

std::string AccountCapabilitiesMessage::getName()
{
	return "AccountCapabilitiesMessage";
}

void AccountCapabilitiesMessage::serialize(BinaryWriter& writer)
{
	uint box0 = 0;
	box0 = BooleanByteWrapper::setFlag(box0, 0, this->tutorialAvailable);
	box0 = BooleanByteWrapper::setFlag(box0, 1, this->canCreateNewCharacter);
	writer.writeByte(box0);
	writer.writeInt(this->accountId);
	writer.writeVarInt(this->breedsVisible);
	writer.writeVarInt(this->breedsAvailable);
	writer.writeByte(this->status);

}

void AccountCapabilitiesMessage::deserialize(BinaryReader& reader)
{
	//idc
}