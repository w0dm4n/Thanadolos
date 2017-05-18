#pragma once
#ifndef ACTOREXTENDEDALIGNMENTINFORMATIONS_THANADOLOS_HPP
#define ACTOREXTENDEDALIGNMENTINFORMATIONS_THANADOLOS_HPP

#include "IType.hpp"
#include "ActorAlignmentInformations.hpp"

class ActorExtendedAlignmentInformations : public ActorAlignmentInformations
{
public:
	ActorExtendedAlignmentInformations(int alignmentSide, int alignmentValue, int alignmentGrade, int characterPower, int honor, int honorGradeFloor, int honorNextGradeFloor, int aggressable);
	ActorExtendedAlignmentInformations();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int __id = 202;

	/*VARS*/
	int honor;
	int honorGradeFloor;
	int honorNextGradeFloor;
	int aggressable;
};


#endif