#pragma once
#ifndef HOUSEINFORMATIONS_THANADOLOS_HPP
#define HOUSEINFORMATIONS_THANADOLOS_HPP

#include "IType.hpp"


class HouseInformations : public IType
{
public:
	HouseInformations(int houseId, std::vector<uint> doorsOnMap, std::string ownerName, bool isOnSale, bool isSaleLocked, int modelId);
	HouseInformations();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int __id = 111;

	/*VARS*/
	int houseId;
	std::vector<uint> doorsOnMap;
	std::string ownerName;
	bool isOnSale;
	bool isSaleLocked;
	int modelId;
};


#endif