#pragma once
#ifndef ABSTRACTCHARACTERINFORMATION_HPP
#define ABSTRACTCHARACTERINFORMATION_HPP

#include "IType.hpp"

class AbstractCharacterInformation : public IType
{
public:
	AbstractCharacterInformation(int id
	);
	AbstractCharacterInformation();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int __id = 400;

	/* VARIABLES */
	int id;
};


#endif