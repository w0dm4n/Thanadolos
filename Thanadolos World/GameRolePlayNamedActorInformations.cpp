#include "Globals.h"
#include "GameRolePlayNamedActorInformations.hpp"

GameRolePlayNamedActorInformations::GameRolePlayNamedActorInformations(int contextualId, EntityLook& look, EntityDispositionInformations& disposition, std::string name) : GameRolePlayActorInformations(contextualId, look, disposition)
{
	this->name = name;

}

GameRolePlayNamedActorInformations::GameRolePlayNamedActorInformations()
{

}

ushort GameRolePlayNamedActorInformations::getId()
{
	return __id;
}

std::string GameRolePlayNamedActorInformations::getName()
{
	return "GameRolePlayNamedActorInformations";
}

void GameRolePlayNamedActorInformations::serialize(BinaryWriter& writer)
{
	GameRolePlayActorInformations::serialize(writer);
	writer.writeUTF(this->name);
}

void GameRolePlayNamedActorInformations::deserialize(BinaryReader& reader)
{
	{		GameRolePlayActorInformations::deserialize(reader);		this->name = reader.readUTF();	}
}