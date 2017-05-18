#include "Globals.h"
#include "HouseInformations.hpp"

HouseInformations::HouseInformations(int houseId, std::vector<uint> doorsOnMap, std::string ownerName, bool isOnSale, bool isSaleLocked, int modelId)
{
	this->houseId = houseId;
	this->doorsOnMap = doorsOnMap;
	this->ownerName = ownerName;
	this->isOnSale = isOnSale;
	this->isSaleLocked = isSaleLocked;
	this->modelId = modelId;

}

HouseInformations::HouseInformations()
{

}

ushort HouseInformations::getId()
{
	return __id;
}

std::string HouseInformations::getName()
{
	return "HouseInformations";
}

void HouseInformations::serialize(BinaryWriter& writer)
{
	int _loc2_ = 0;
	_loc2_ = BooleanByteWrapper::setFlag(_loc2_, 0, this->isOnSale);
	while (_loc3_ < this->doorsOnMap.size())
}

void HouseInformations::deserialize(BinaryReader& reader)
{
	{
		int _loc2_ = reader.readByte();
		while (_loc4_ < _loc3_)
}