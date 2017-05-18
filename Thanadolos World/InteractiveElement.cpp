#include "Globals.h"
#include "InteractiveElement.hpp"

InteractiveElement::InteractiveElement(int elementId, int elementTypeId, std::vector<InteractiveElementSkill> enabledSkills, std::vector<InteractiveElementSkill> disabledSkills, bool onCurrentMap)
{
	this->elementId = elementId;
	this->elementTypeId = elementTypeId;
	this->enabledSkills = enabledSkills;
	this->disabledSkills = disabledSkills;
	this->onCurrentMap = onCurrentMap;

}

InteractiveElement::InteractiveElement()
{

}

ushort InteractiveElement::getId()
{
	return __id;
}

std::string InteractiveElement::getName()
{
	return "InteractiveElement";
}

void InteractiveElement::serialize(BinaryWriter& writer)
{
	writer.writeInt(this->elementId);	writer.writeInt(this->elementTypeId);	writer.writeShort(this->enabledSkills.size());	int _loc2_ = 0;
	while (_loc2_ < this->enabledSkills.size())	{		writer.writeShort((this->enabledSkills[_loc2_]).getId());		(this->enabledSkills[_loc2_]).serialize(writer);		_loc2_++;	}	writer.writeShort(this->disabledSkills.size());	int _loc3_ = 0;
	while (_loc3_ < this->disabledSkills.size())	{		writer.writeShort((this->disabledSkills[_loc3_]).getId());		(this->disabledSkills[_loc3_]).serialize(writer);		_loc3_++;	}	writer.writeBool(this->onCurrentMap);
}

void InteractiveElement::deserialize(BinaryReader& reader)
{
	{		int _loc6_ = 0;
		InteractiveElementSkill _loc7_;
		int _loc8_ = 0;
		InteractiveElementSkill _loc9_;
		this->elementId = reader.readInt();		this->elementTypeId = reader.readInt();		int _loc2_ = reader.readUnsignedShort();		int _loc3_ = 0;
		while (_loc3_ < _loc2_)		{			_loc6_ = reader.readUnsignedShort();			_loc7_.deserialize(reader);			this->enabledSkills.push_back(_loc7_);			_loc3_++;		}		int _loc4_ = reader.readUnsignedShort();		int _loc5_ = 0;
		while (_loc5_ < _loc4_)		{			_loc8_ = reader.readUnsignedShort();			_loc9_.deserialize(reader);			this->disabledSkills.push_back(_loc9_);			_loc5_++;		}		this->onCurrentMap = reader.readBool();	}
}