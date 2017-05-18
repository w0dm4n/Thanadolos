#pragma once
#ifndef GAMEROLEPLAYNAMEDACTORINFORMATIONS_THANADOLOS_HPP
#define GAMEROLEPLAYNAMEDACTORINFORMATIONS_THANADOLOS_HPP

#include "IType.hpp"
#include "GameRolePlayActorInformations.hpp"

class GameRolePlayNamedActorInformations : public GameRolePlayActorInformations
{
public:
	GameRolePlayNamedActorInformations(int contextualId, EntityLook& look, EntityDispositionInformations& disposition, std::string name);
	GameRolePlayNamedActorInformations();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int __id = 154;

	/*VARS*/
	std::string name;
};


#endif