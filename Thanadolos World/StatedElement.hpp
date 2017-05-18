#pragma once
#ifndef STATEDELEMENT_THANADOLOS_HPP
#define STATEDELEMENT_THANADOLOS_HPP

#include "IType.hpp"


class StatedElement : public IType
{
public:
	StatedElement(int elementId, int elementCellId, int elementState, bool onCurrentMap);
	StatedElement();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int __id = 108;

	/*VARS*/
	int elementId;
	int elementCellId;
	int elementState;
	bool onCurrentMap;
};


#endif