#pragma once
#ifndef OBJECTITEM_THANADOLOS_HPP
#define OBJECTITEM_THANADOLOS_HPP

#include "IType.hpp"
#include "ObjectEffect.hpp"
#include "Item.hpp"

class ObjectItem : public Item
{
public:
	ObjectItem(int position, int objectGID, std::vector<ObjectEffect*> effects, int objectUID, int quantity);
	ObjectItem();
	~ObjectItem();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int __id = 37;

	/*VARS*/
	int position;
	int objectGID;
	std::vector<ObjectEffect*> effects;
	int objectUID;
	int quantity;
};


#endif