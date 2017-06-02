#pragma once
#ifndef GAMESERVERINFORMATIONS_HPP
#define GAMESERVERINFORMATIONS_HPP

#include "IType.hpp"

class GameServerInformations : public IType
{
public:
	GameServerInformations(
		uint _id = 0,
		int _type = -1,
		uint _status = 1,
		uint _completion = 0,
		bool _isSelectable = true,
		uint _characterCount = 0,
		uint _characterSlots = 0,
		double _date = 0
	);
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int __id = 25;

	/* VARIABLES */

	uint id;
	int type;
	uint status;
	uint completion;
	bool isSelectable;
	uint characterCount;
	uint characterSlots;
	double date;
};


#endif