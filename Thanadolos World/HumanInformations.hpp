#pragma once
#ifndef HUMANINFORMATIONS_THANADOLOS_HPP
#define HUMANINFORMATIONS_THANADOLOS_HPP

#include "IType.hpp"
#include "ActorRestrictionsInformations.hpp" 
#include "HumanOption.hpp"


class HumanInformations : public IType
{
public:
	HumanInformations(ActorRestrictionsInformations& restrictions, bool sex, std::vector<HumanOption> options);
	HumanInformations();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int __id = 157;

	/*VARS*/
	ActorRestrictionsInformations restrictions;
	bool sex;
	std::vector<HumanOption> options;
};


#endif