#pragma once
#ifndef ITEM_THANADOLOS_HPP
#define ITEM_THANADOLOS_HPP

#include "IType.hpp"


class Item : public IType
{
public:
	Item();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int __id = 7;

	/*VARS*/

};


#endif