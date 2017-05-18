#include "Globals.h"
#include "InteractiveElementSkill.hpp"

InteractiveElementSkill::InteractiveElementSkill(int skillId, int skillInstanceUid)
{
	this->skillId = skillId;
	this->skillInstanceUid = skillInstanceUid;

}

InteractiveElementSkill::InteractiveElementSkill()
{

}

ushort InteractiveElementSkill::getId()
{
	return __id;
}

std::string InteractiveElementSkill::getName()
{
	return "InteractiveElementSkill";
}

void InteractiveElementSkill::serialize(BinaryWriter& writer)
{
	writer.writeVarInt(this->skillId);	writer.writeInt(this->skillInstanceUid);
}

void InteractiveElementSkill::deserialize(BinaryReader& reader)
{
	{		this->skillId = reader.readVarUhInt();		this->skillInstanceUid = reader.readInt();	}
}