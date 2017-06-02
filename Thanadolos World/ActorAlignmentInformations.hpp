#pragma once
#ifndef ACTORALIGNMENTINFORMATIONS_THANADOLOS_HPP
#define ACTORALIGNMENTINFORMATIONS_THANADOLOS_HPP

#include "IType.hpp"


class ActorAlignmentInformations : public IType
{
public:
	ActorAlignmentInformations(int alignmentSide, int alignmentValue, int alignmentGrade, int characterPower);
	ActorAlignmentInformations();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int __id = 201;

	/*VARS*/
	int alignmentSide;
	int alignmentValue;
	int alignmentGrade;
	Int64 characterPower;
};


#endif