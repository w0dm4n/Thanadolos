#pragma once
#ifndef IMESSAGE_H
#define IMESSAGE_H

#include <vector>
#include <string>

#include "BinaryReader.hpp"
#include "BinaryWriter.hpp"
#include "BooleanByteWrapper.hpp"

class IMessage
{
public:
	virtual ushort getId() = 0;
	virtual std::string getName() = 0;
	virtual void serialize(BinaryWriter& writer) = 0;
	virtual void deserialize(BinaryReader& reader) = 0;
};

#endif 