#pragma once
#ifndef HELLOGAMEMESSAGE_HPP
#define HELLOGAMEMESSAGE_HPP

#include "imessage.h"

class HelloGameMessage : public IMessage
{
public:
	HelloGameMessage();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 101;

	/*VARS*/
	
};


#endif