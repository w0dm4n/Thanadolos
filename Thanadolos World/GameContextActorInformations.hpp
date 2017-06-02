#pragma once
#ifndef GAMECONTEXTACTORINFORMATIONS_THANADOLOS_HPP
#define GAMECONTEXTACTORINFORMATIONS_THANADOLOS_HPP

#include "IType.hpp"
#include "EntityLook.hpp" 
#include "EntityDispositionInformations.hpp" 


class GameContextActorInformations : public IType
{
public:
	GameContextActorInformations(int contextualId, EntityLook& look, EntityDispositionInformations& disposition);
	GameContextActorInformations();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int __id = 150;

	/*VARS*/
	Int64 contextualId;
	EntityLook look;
	EntityDispositionInformations disposition;
};


#endif