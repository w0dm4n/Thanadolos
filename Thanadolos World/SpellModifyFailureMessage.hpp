#pragma once
#ifndef SPELLMODIFYFAILUREMESSAGE_THANADOLOS_HPP
#define SPELLMODIFYFAILUREMESSAGE_THANADOLOS_HPP

#include "imessage.h"


class SpellModifyFailureMessage : public IMessage
{
public:
	SpellModifyFailureMessage();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 6653;

	/*VARS*/

};


#endif