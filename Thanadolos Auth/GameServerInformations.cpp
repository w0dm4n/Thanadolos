#include "GameServerInformations.hpp"

GameServerInformations::GameServerInformations(
	uint _id,
	int _type,
	uint _status,
	uint _completion,
	bool _isSelectable,
	uint _characterCount,
	uint _characterSlots,
	double _date
)
{
	id = _id;
	type = _type;
	status = _status;
	completion = _completion;
	isSelectable = _isSelectable;
	characterCount = _characterCount;
	characterSlots = _characterSlots;
	date = _date;
}

ushort GameServerInformations::getId()
{
	return __id;
}

std::string GameServerInformations::getName()
{
	return "GameServerInformations";
}

void GameServerInformations::serialize(BinaryWriter& writer)
{
	writer.writeVarShort(static_cast<short>(id));
	writer.writeByte(static_cast<char>(type));
	writer.writeByte(static_cast<char>(status));
	writer.writeByte(static_cast<char>(completion));
	writer.writeBool(isSelectable);
	writer.writeByte(static_cast<char>(characterCount));
	writer.writeByte(static_cast<char>(characterSlots));
	writer.writeDouble(date);
}

void GameServerInformations::deserialize(BinaryReader& reader)
{
	this->id = reader.readVarShort();
	this->type = reader.readByte();
	this->status = reader.readByte();
	this->completion = reader.readByte();
	this->isSelectable = reader.readBool();
	this->characterCount = reader.readByte();
	this->characterSlots = reader.readByte();
	this->date = 0.0;
}