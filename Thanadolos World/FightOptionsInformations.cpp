#include "Globals.h"
#include "FightOptionsInformations.hpp"

FightOptionsInformations::FightOptionsInformations(bool isSecret, bool isRestrictedToPartyOnly, bool isClosed, bool isAskingForHelp)
{
	this->isSecret = isSecret;
	this->isRestrictedToPartyOnly = isRestrictedToPartyOnly;
	this->isClosed = isClosed;
	this->isAskingForHelp = isAskingForHelp;

}

FightOptionsInformations::FightOptionsInformations()
{

}

ushort FightOptionsInformations::getId()
{
	return __id;
}

std::string FightOptionsInformations::getName()
{
	return "FightOptionsInformations";
}

void FightOptionsInformations::serialize(BinaryWriter& writer)
{
	int _loc2_ = 0;
	_loc2_ = BooleanByteWrapper::setFlag(_loc2_, 0, this->isSecret);	_loc2_ = BooleanByteWrapper::setFlag(_loc2_, 1, this->isRestrictedToPartyOnly);	_loc2_ = BooleanByteWrapper::setFlag(_loc2_, 2, this->isClosed);	_loc2_ = BooleanByteWrapper::setFlag(_loc2_, 3, this->isAskingForHelp);	writer.writeByte(_loc2_);
}

void FightOptionsInformations::deserialize(BinaryReader& reader)
{
	{		int _loc2_ = reader.readByte();		this->isSecret = BooleanByteWrapper::getFlag(_loc2_, 0);		this->isRestrictedToPartyOnly = BooleanByteWrapper::getFlag(_loc2_, 1);		this->isClosed = BooleanByteWrapper::getFlag(_loc2_, 2);		this->isAskingForHelp = BooleanByteWrapper::getFlag(_loc2_, 3);	}
}