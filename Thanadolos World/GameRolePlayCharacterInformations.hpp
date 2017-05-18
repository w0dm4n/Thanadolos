#pragma once
#ifndef GAMEROLEPLAYCHARACTERINFORMATIONS_THANADOLOS_HPP
#define GAMEROLEPLAYCHARACTERINFORMATIONS_THANADOLOS_HPP

#include "IType.hpp"
#include "ActorAlignmentInformations.hpp" 
#include "GameRolePlayHumanoidInformations.hpp"

class GameRolePlayCharacterInformations : public GameRolePlayHumanoidInformations
{
public:
	GameRolePlayCharacterInformations(int contextualId, EntityLook& look, EntityDispositionInformations& disposition, std::string name, HumanInformations& humanoidInfo, int accountId, ActorAlignmentInformations& alignmentInfos);
	GameRolePlayCharacterInformations();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int __id = 36;

	/*VARS*/
	ActorAlignmentInformations alignmentInfos;
};


#endif