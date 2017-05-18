#pragma once
#ifndef HUMANOPTION_THANADOLOS_HPP
#define HUMANOPTION_THANADOLOS_HPP

#include "IType.hpp"


class HumanOption : public IType
{
public:
	HumanOption();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int __id = 406;

	/*VARS*/

};


#endif