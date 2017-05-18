#pragma once
#ifndef FIGHTOPTIONSINFORMATIONS_THANADOLOS_HPP
#define FIGHTOPTIONSINFORMATIONS_THANADOLOS_HPP

#include "IType.hpp"


class FightOptionsInformations : public IType
{
public:
	FightOptionsInformations(bool isSecret, bool isRestrictedToPartyOnly, bool isClosed, bool isAskingForHelp);
	FightOptionsInformations();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int __id = 20;

	/*VARS*/
	bool isSecret;
	bool isRestrictedToPartyOnly;
	bool isClosed;
	bool isAskingForHelp;
};


#endif