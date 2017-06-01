#pragma once
#ifndef SPELLMODIFYREQUESTMESSAGE_THANADOLOS_HPP
#define SPELLMODIFYREQUESTMESSAGE_THANADOLOS_HPP

#include "imessage.h"


class SpellModifyRequestMessage : public IMessage
{
public:
	SpellModifyRequestMessage(int spellId, int spellLevel);
	SpellModifyRequestMessage();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 6655;

	/*VARS*/
	int spellId;
	int spellLevel;
};


#endif