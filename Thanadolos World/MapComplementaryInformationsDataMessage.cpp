#include "Globals.h"
#include "MapComplementaryInformationsDataMessage.hpp"

MapComplementaryInformationsDataMessage::MapComplementaryInformationsDataMessage(int subAreaId, int mapId, std::vector<HouseInformations> houses, std::vector<GameRolePlayActorInformations*> actors, std::vector<InteractiveElement> interactiveElements, std::vector<StatedElement> statedElements, std::vector<MapObstacle> obstacles, std::vector<FightCommonInformations> fights, bool hasAggressiveMonsters, FightStartingPositions& fightStartPositions)
{
	this->subAreaId = subAreaId;
	this->mapId = mapId;
	this->houses = houses;
	this->actors = actors;
	this->interactiveElements = interactiveElements;
	this->statedElements = statedElements;
	this->obstacles = obstacles;
	this->fights = fights;
	this->hasAggressiveMonsters = hasAggressiveMonsters;
	this->fightStartPositions = fightStartPositions;
}

MapComplementaryInformationsDataMessage::MapComplementaryInformationsDataMessage()
{

}

MapComplementaryInformationsDataMessage::~MapComplementaryInformationsDataMessage()
{
	int i = 0;
	while (i < this->actors.size())
		delete this->actors[i++];
}

ushort MapComplementaryInformationsDataMessage::getId()
{
	return id;
}

std::string MapComplementaryInformationsDataMessage::getName()
{
	return "MapComplementaryInformationsDataMessage";
}

void MapComplementaryInformationsDataMessage::serialize(BinaryWriter& writer)
{
	writer.writeVarShort(this->subAreaId);	writer.writeInt(this->mapId);	writer.writeShort(this->houses.size());	int _loc2_ = 0;
	while (_loc2_ < this->houses.size())	{		writer.writeShort((this->houses[_loc2_]).getId());		(this->houses[_loc2_]).serialize(writer);		_loc2_++;	}	writer.writeShort(this->actors.size());	int _loc3_ = 0;
	while (_loc3_ < this->actors.size())	{		writer.writeShort((this->actors[_loc3_])->getId());		(this->actors[_loc3_])->serialize(writer);		_loc3_++;	}	writer.writeShort(this->interactiveElements.size());	int _loc4_ = 0;
	while (_loc4_ < this->interactiveElements.size())	{		writer.writeShort((this->interactiveElements[_loc4_]).getId());		(this->interactiveElements[_loc4_]).serialize(writer);		_loc4_++;	}	writer.writeShort(this->statedElements.size());	int _loc5_ = 0;
	while (_loc5_ < this->statedElements.size())	{		(this->statedElements[_loc5_]).serialize(writer);
		_loc5_++;	}	writer.writeShort(this->obstacles.size());	int _loc6_ = 0;
	while (_loc6_ < this->obstacles.size())	{		(this->obstacles[_loc6_]).serialize(writer);
		_loc6_++;	}	writer.writeShort(this->fights.size());	int _loc7_ = 0;
	while (_loc7_ < this->fights.size())	{		(this->fights[_loc7_]).serialize(writer);
		_loc7_++;	}	writer.writeBool(this->hasAggressiveMonsters);	this->fightStartPositions.serialize(writer);
}

void MapComplementaryInformationsDataMessage::deserialize(BinaryReader& reader)
{
	{		int _loc14_ = 0;
		HouseInformations _loc15_;
		int _loc16_ = 0;
		GameRolePlayActorInformations *_loc17_ = new GameRolePlayActorInformations();
		int _loc18_ = 0;
		InteractiveElement _loc19_;
		StatedElement _loc20_;
		MapObstacle _loc21_;
		FightCommonInformations _loc22_;
		this->subAreaId = reader.readVarUhShort();		this->mapId = reader.readInt();		int _loc2_ = reader.readUnsignedShort();		int _loc3_ = 0;
		while (_loc3_ < _loc2_)		{			_loc14_ = reader.readUnsignedShort();			_loc15_.deserialize(reader);			this->houses.push_back(_loc15_);			_loc3_++;		}		int _loc4_ = reader.readUnsignedShort();		int _loc5_ = 0;
		while (_loc5_ < _loc4_)		{			_loc16_ = reader.readUnsignedShort();			_loc17_->deserialize(reader);			this->actors.push_back(_loc17_);			_loc5_++;		}		int _loc6_ = reader.readUnsignedShort();		int _loc7_ = 0;
		while (_loc7_ < _loc6_)		{			_loc18_ = reader.readUnsignedShort();			_loc19_.deserialize(reader);			this->interactiveElements.push_back(_loc19_);			_loc7_++;		}		int _loc8_ = reader.readUnsignedShort();		int _loc9_ = 0;
		while (_loc9_ < _loc8_)		{			_loc20_.deserialize(reader);			this->statedElements.push_back(_loc20_);			_loc9_++;		}		int _loc10_ = reader.readUnsignedShort();		int _loc11_ = 0;
		while (_loc11_ < _loc10_)		{			_loc21_.deserialize(reader);			this->obstacles.push_back(_loc21_);			_loc11_++;		}		int _loc12_ = reader.readUnsignedShort();		int _loc13_ = 0;
		while (_loc13_ < _loc12_)		{			_loc22_.deserialize(reader);			this->fights.push_back(_loc22_);			_loc13_++;		}		this->hasAggressiveMonsters = reader.readBool();		this->fightStartPositions.deserialize(reader);	}
}