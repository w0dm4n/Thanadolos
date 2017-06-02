#include "Globals.h"
#include "HelloGameMessage.hpp"
#include <iostream>

HelloGameMessage::HelloGameMessage()
{
	
}

ushort HelloGameMessage::getId()
{
	return id;
}

std::string HelloGameMessage::getName()
{
	return "HelloGameMessage";
}
void HelloGameMessage::serialize(BinaryWriter& writer)
{
	
}

void HelloGameMessage::deserialize(BinaryReader& reader)
{

}