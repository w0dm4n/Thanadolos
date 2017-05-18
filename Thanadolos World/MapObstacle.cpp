#include "Globals.h"
#include "MapObstacle.hpp"

MapObstacle::MapObstacle(int obstacleCellId, int state)
{
	this->obstacleCellId = obstacleCellId;
	this->state = state;

}

MapObstacle::MapObstacle()
{

}

ushort MapObstacle::getId()
{
	return __id;
}

std::string MapObstacle::getName()
{
	return "MapObstacle";
}

void MapObstacle::serialize(BinaryWriter& writer)
{
	writer.writeVarShort(this->obstacleCellId);	writer.writeByte(this->state);
}

void MapObstacle::deserialize(BinaryReader& reader)
{
	{		this->obstacleCellId = reader.readVarUhShort();		this->state = reader.readByte();	}
}