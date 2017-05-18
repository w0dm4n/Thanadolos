#include "Globals.h"
#include "GameRolePlayActorInformations.hpp"

GameRolePlayActorInformations::GameRolePlayActorInformations(int contextualId, EntityLook& look, EntityDispositionInformations& disposition) : GameContextActorInformations(contextualId, look, disposition)
{

}

GameRolePlayActorInformations::GameRolePlayActorInformations()
{

}

ushort GameRolePlayActorInformations::getId()
{
	return __id;
}

std::string GameRolePlayActorInformations::getName()
{
	return "GameRolePlayActorInformations";
}

void GameRolePlayActorInformations::serialize(BinaryWriter& writer)
{
	GameContextActorInformations::serialize(writer);
}

void GameRolePlayActorInformations::deserialize(BinaryReader& reader)
{
	{		GameContextActorInformations::deserialize(reader);	}
}