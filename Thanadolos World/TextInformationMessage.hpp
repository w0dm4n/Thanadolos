#pragma once
#ifndef TEXTINFORMATIONMESSAGE_THANADOLOS_HPP
#define TEXTINFORMATIONMESSAGE_THANADOLOS_HPP

#include "imessage.h"


class TextInformationMessage : public IMessage
{
public:
	TextInformationMessage(int msgType, int msgId, std::vector<std::string> parameters);
	TextInformationMessage();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 780;

	/*VARS*/
	int msgType;
	int msgId;
	std::vector<std::string> parameters;
};


#endif