#include "Globals.h"
#include "SpellModifyFailureMessage.hpp"

SpellModifyFailureMessage::SpellModifyFailureMessage()
{

}

ushort SpellModifyFailureMessage::getId()
{
	return id;
}

std::string SpellModifyFailureMessage::getName()
{
	return "SpellModifyFailureMessage";
}

void SpellModifyFailureMessage::serialize(BinaryWriter& writer)
{

}

void SpellModifyFailureMessage::deserialize(BinaryReader& reader)
{
	{	}}