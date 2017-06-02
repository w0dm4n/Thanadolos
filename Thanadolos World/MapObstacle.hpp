#pragma once
#ifndef MAPOBSTACLE_THANADOLOS_HPP
#define MAPOBSTACLE_THANADOLOS_HPP

#include "IType.hpp"


class MapObstacle : public IType
{
public:
	MapObstacle(int obstacleCellId, int state);
	MapObstacle();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int __id = 200;

	/*VARS*/
	int obstacleCellId;
	int state;
};


#endif