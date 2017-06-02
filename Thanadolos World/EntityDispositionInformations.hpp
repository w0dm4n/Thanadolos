#pragma once
#ifndef ENTITYDISPOSITIONINFORMATIONS_THANADOLOS_HPP
#define ENTITYDISPOSITIONINFORMATIONS_THANADOLOS_HPP

#include "IType.hpp"


class EntityDispositionInformations : public IType
{
public:
	EntityDispositionInformations(int cellId, int direction);
	EntityDispositionInformations();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int __id = 60;

	/*VARS*/
	int cellId;
	int direction;
};


#endif