#pragma once
#ifndef RELOGINTOKENREQUESTMESSAGE_HPP
#define RELOGINTOKENREQUESTMESSAGE_HPP

#include "imessage.h"

class ReloginTokenRequestMessage : public IMessage
{
public:
	ReloginTokenRequestMessage();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 6540;

	/*VARS*/

};


#endif