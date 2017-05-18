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
	_loc2_ = BooleanByteWrapper::setFlag(_loc2_, 0, this->isOnSale);	_loc2_ = BooleanByteWrapper::setFlag(_loc2_, 1, this->isSaleLocked);	writer.writeByte(_loc2_);	writer.writeVarInt(this->houseId);	writer.writeShort(this->doorsOnMap.size());	int _loc3_ = 0;
	while (_loc3_ < this->doorsOnMap.size())	{		writer.writeInt(this->doorsOnMap[_loc3_]);		_loc3_++;	}	writer.writeUTF(this->ownerName);	writer.writeVarShort(this->modelId);
}

void HouseInformations::deserialize(BinaryReader& reader)
{
	{		int _loc5_ = 0;
		int _loc2_ = reader.readByte();		this->isOnSale = BooleanByteWrapper::getFlag(_loc2_, 0);		this->isSaleLocked = BooleanByteWrapper::getFlag(_loc2_, 1);		this->houseId = reader.readVarUhInt();		int _loc3_ = reader.readUnsignedShort();		int _loc4_ = 0;
		while (_loc4_ < _loc3_)		{			_loc5_ = reader.readInt();			this->doorsOnMap.push_back(_loc5_);			_loc4_++;		}		this->ownerName = reader.readUTF();		this->modelId = reader.readVarUhShort();	}
}