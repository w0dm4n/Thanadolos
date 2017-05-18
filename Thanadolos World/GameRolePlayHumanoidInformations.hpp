#pragma once
#ifndef GAMEROLEPLAYHUMANOIDINFORMATIONS_THANADOLOS_HPP
#define GAMEROLEPLAYHUMANOIDINFORMATIONS_THANADOLOS_HPP

#include "IType.hpp"
#include "GameRolePlayNamedActorInformations.hpp"
#include "HumanInformations.hpp" 


class GameRolePlayHumanoidInformations : public GameRolePlayNamedActorInformations
{
public:
	GameRolePlayHumanoidInformations(int contextualId, EntityLook& look, EntityDispositionInformations& disposition, std::string name, HumanInformations& humanoidInfo, int accountId);
	GameRolePlayHumanoidInformations();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int __id = 159;

	/*VARS*/
	HumanInformations humanoidInfo;
	int accountId;
};


#endif