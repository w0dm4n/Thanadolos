#pragma once
#ifndef INTERACTIVEELEMENTSKILL_THANADOLOS_HPP
#define INTERACTIVEELEMENTSKILL_THANADOLOS_HPP

#include "IType.hpp"


class InteractiveElementSkill : public IType
{
public:
	InteractiveElementSkill(int skillId, int skillInstanceUid);
	InteractiveElementSkill();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int __id = 219;

	/*VARS*/
	int skillId;
	int skillInstanceUid;
};


#endif