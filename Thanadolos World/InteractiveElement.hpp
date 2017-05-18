#pragma once
#ifndef INTERACTIVEELEMENT_THANADOLOS_HPP
#define INTERACTIVEELEMENT_THANADOLOS_HPP

#include "IType.hpp"
#include "InteractiveElementSkill.hpp"

class InteractiveElement : public IType
{
public:
	InteractiveElement(int elementId, int elementTypeId, std::vector<InteractiveElementSkill> enabledSkills, std::vector<InteractiveElementSkill> disabledSkills, bool onCurrentMap);
	InteractiveElement();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int __id = 80;

	/*VARS*/
	int elementId;
	int elementTypeId;
	std::vector<InteractiveElementSkill> enabledSkills;
	std::vector<InteractiveElementSkill> disabledSkills;
	bool onCurrentMap;
};


#endif