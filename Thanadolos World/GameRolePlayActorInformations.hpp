#pragma once
#ifndef GAMEROLEPLAYACTORINFORMATIONS_THANADOLOS_HPP
#define GAMEROLEPLAYACTORINFORMATIONS_THANADOLOS_HPP

#include "IType.hpp"
#include "GameContextActorInformations.hpp"

class GameRolePlayActorInformations : public GameContextActorInformations
{
public:
	GameRolePlayActorInformations(int contextualId, EntityLook& look, EntityDispositionInformations& disposition);
	GameRolePlayActorInformations();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int __id = 141;

	/*VARS*/

};


#endif