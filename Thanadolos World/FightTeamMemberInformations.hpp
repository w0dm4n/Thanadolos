#pragma once
#ifndef FIGHTTEAMMEMBERINFORMATIONS_THANADOLOS_HPP
#define FIGHTTEAMMEMBERINFORMATIONS_THANADOLOS_HPP

#include "IType.hpp"


class FightTeamMemberInformations : public IType
{
public:
	FightTeamMemberInformations(int id);
	FightTeamMemberInformations();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int __id = 44;

	/*VARS*/
	Int64 id;
};


#endif