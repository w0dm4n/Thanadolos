#include "Globals.h"
#include "TrustStatusMessage.hpp"

TrustStatusMessage::TrustStatusMessage(bool trusted, bool certified)
{
	this->trusted = trusted;
	this->certified = certified;
}

ushort TrustStatusMessage::getId()
{
	return id;
}

std::string TrustStatusMessage::getName()
{
	return "TrustStatusMessage";
}

void TrustStatusMessage::serialize(BinaryWriter& writer)
{
	uint box0 = 0;
	box0 = BooleanByteWrapper::setFlag(box0, 0, this->trusted);
	box0 = BooleanByteWrapper::setFlag(box0, 1, this->certified);
	writer.writeByte(box0);
}

void TrustStatusMessage::deserialize(BinaryReader& reader)
{
	//idc
}