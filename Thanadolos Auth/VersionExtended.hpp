#pragma once
#ifndef VERSION_EXTENDED_HPP
#define VERSION_EXTENDED_HPP

#include "Version.hpp"

class VersionExtended : public Version
{
public:
	void initVersionExtended(char _install, char _technology);
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 393;

	/* VARIABLES */

	char install;
	char technology;
};


#endif