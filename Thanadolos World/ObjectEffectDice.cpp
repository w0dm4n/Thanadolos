#include "Globals.h"
#include "ObjectEffectDice.hpp"

ObjectEffectDice::ObjectEffectDice(int position, int objectGID, std::vector<ObjectEffect*> effects, int objectUID, int quantity, int diceNum, int diceSide, int diceConst) : ObjectItem(position, objectGID, effects, objectUID, quantity)
{
	this->diceNum = diceNum;
	this->diceSide = diceSide;
	this->diceConst = diceConst;

}

ObjectEffectDice::ObjectEffectDice()
{

}

ushort ObjectEffectDice::getId()
{
	return __id;
}

std::string ObjectEffectDice::getName()
{
	return "ObjectEffectDice";
}

void ObjectEffectDice::serialize(BinaryWriter& writer)
{
	ObjectItem::serialize(writer);
	writer.writeVarShort(this->diceNum);	writer.writeVarShort(this->diceSide);	writer.writeVarShort(this->diceConst);
}

void ObjectEffectDice::deserialize(BinaryReader& reader)
{
	{		ObjectItem::deserialize(reader);		this->diceNum = reader.readVarUhShort();		this->diceSide = reader.readVarUhShort();		this->diceConst = reader.readVarUhShort();	}
}