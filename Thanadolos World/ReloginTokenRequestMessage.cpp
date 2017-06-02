#include "Globals.h"
#include "ReloginTokenRequestMessage.hpp"
#include <iostream>

ReloginTokenRequestMessage::ReloginTokenRequestMessage()
{

}

ushort ReloginTokenRequestMessage::getId()
{
	return id;
}

std::string ReloginTokenRequestMessage::getName()
{
	return "ReloginTokenRequestMessage";
}

void ReloginTokenRequestMessage::serialize(BinaryWriter& writer)
{

}

void ReloginTokenRequestMessage::deserialize(BinaryReader& reader)
{

}