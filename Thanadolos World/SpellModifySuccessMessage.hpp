#pragma once
#ifndef SPELLMODIFYSUCCESSMESSAGE_THANADOLOS_HPP
#define SPELLMODIFYSUCCESSMESSAGE_THANADOLOS_HPP

#include "imessage.h"


class SpellModifySuccessMessage : public IMessage
{
public:
	SpellModifySuccessMessage(int spellId, int spellLevel);
	SpellModifySuccessMessage();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 6654;

	/*VARS*/
	int spellId;
	int spellLevel;
};


#endif