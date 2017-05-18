#include "Globals.h"
#include "ActorExtendedAlignmentInformations.hpp"

ActorExtendedAlignmentInformations::ActorExtendedAlignmentInformations(int alignmentSide, int alignmentValue, int alignmentGrade, int characterPower, int honor, int honorGradeFloor, int honorNextGradeFloor, int aggressable) : ActorAlignmentInformations(alignmentSide, alignmentValue, alignmentGrade, characterPower)
{
	this->honor = honor;
	this->honorGradeFloor = honorGradeFloor;
	this->honorNextGradeFloor = honorNextGradeFloor;
	this->aggressable = aggressable;

}

ActorExtendedAlignmentInformations::ActorExtendedAlignmentInformations()
{

}

ushort ActorExtendedAlignmentInformations::getId()
{
	return __id;
}

std::string ActorExtendedAlignmentInformations::getName()
{
	return "ActorExtendedAlignmentInformations";
}

void ActorExtendedAlignmentInformations::serialize(BinaryWriter& writer)
{
	ActorAlignmentInformations::serialize(writer);
	writer.writeVarShort(this->honor);	writer.writeVarShort(this->honorGradeFloor);	writer.writeVarShort(this->honorNextGradeFloor);	writer.writeByte(this->aggressable);
}

void ActorExtendedAlignmentInformations::deserialize(BinaryReader& reader)
{
	{		ActorAlignmentInformations::deserialize(reader);		this->honor = reader.readVarUhShort();		this->honorGradeFloor = reader.readVarUhShort();		this->honorNextGradeFloor = reader.readVarUhShort();		this->aggressable = reader.readByte();	}
}