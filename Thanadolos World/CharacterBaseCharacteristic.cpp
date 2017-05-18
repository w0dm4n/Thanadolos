#include "Globals.h"
#include "CharacterBaseCharacteristic.hpp"

CharacterBaseCharacteristic::CharacterBaseCharacteristic(int base, int additionnal, int objectsAndMountBonus, int alignGiftBonus, int contextModif)
{
	this->base = base;
	this->additionnal = additionnal;
	this->objectsAndMountBonus = objectsAndMountBonus;
	this->alignGiftBonus = alignGiftBonus;
	this->contextModif = contextModif;

}

CharacterBaseCharacteristic::CharacterBaseCharacteristic()
{

}

ushort CharacterBaseCharacteristic::getId()
{
	return __id;
}

std::string CharacterBaseCharacteristic::getName()
{
	return "CharacterBaseCharacteristic";
}

void CharacterBaseCharacteristic::serialize(BinaryWriter& writer)
{
	writer.writeVarShort(this->base);	writer.writeVarShort(this->additionnal);	writer.writeVarShort(this->objectsAndMountBonus);	writer.writeVarShort(this->alignGiftBonus);	writer.writeVarShort(this->contextModif);
}

void CharacterBaseCharacteristic::deserialize(BinaryReader& reader)
{
	{		this->base = reader.readVarShort();		this->additionnal = reader.readVarShort();		this->objectsAndMountBonus = reader.readVarShort();		this->alignGiftBonus = reader.readVarShort();		this->contextModif = reader.readVarShort();	}
}