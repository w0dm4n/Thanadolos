#pragma once
#ifndef VERSION_HPP
#define VERSION_HPP

#include "IType.hpp"

class Version : public IType
{
public:
	void initVersion(char _major, char _minor, char _release, int _revision, char _patch, char _buildType);
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 11;

	/* VARIABLES */

	char major;
	char minor;
	char release;
	int revision;
	char patch;
	char buildType;
};


#endif