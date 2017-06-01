#pragma once
#ifndef SHORTCUT_THANADOLOS_HPP
#define SHORTCUT_THANADOLOS_HPP

#include "IType.hpp"


class Shortcut : public IType
{
public:
	Shortcut(int slot);
	Shortcut();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int __id = 369;

	/*VARS*/
	int slot;
};


#endif