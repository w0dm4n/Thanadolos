#include "Globals.h"
#include "HumanInformations.hpp"

HumanInformations::HumanInformations(ActorRestrictionsInformations& restrictions, bool sex, std::vector<HumanOption> options)
{
	this->restrictions = restrictions;
	this->sex = sex;
	this->options = options;

}

HumanInformations::HumanInformations()
{

}

ushort HumanInformations::getId()
{
	return __id;
}

std::string HumanInformations::getName()
{
	return "HumanInformations";
}

void HumanInformations::serialize(BinaryWriter& writer)
{
	this->restrictions.serialize(writer);
	writer.writeBool(this->sex);	writer.writeShort(this->options.size());	int _loc2_ = 0;
	while (_loc2_ < this->options.size())	{		writer.writeShort((this->options[_loc2_]).getId());		(this->options[_loc2_]).serialize(writer);		_loc2_++;	}
}

void HumanInformations::deserialize(BinaryReader& reader)
{
	{		int _loc4_ = 0;
		HumanOption _loc5_;
		this->restrictions.deserialize(reader);		this->sex = reader.readBool();		int _loc2_ = reader.readUnsignedShort();		int _loc3_ = 0;
		while (_loc3_ < _loc2_)		{			_loc4_ = reader.readUnsignedShort();			_loc5_.deserialize(reader);			this->options.push_back(_loc5_);			_loc3_++;		}	}
}