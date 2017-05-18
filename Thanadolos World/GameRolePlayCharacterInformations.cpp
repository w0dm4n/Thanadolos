#include "Globals.h"
#include "GameRolePlayCharacterInformations.hpp"

GameRolePlayCharacterInformations::GameRolePlayCharacterInformations(int contextualId, EntityLook& look, EntityDispositionInformations& disposition, std::string name, HumanInformations& humanoidInfo, int accountId, ActorAlignmentInformations& alignmentInfos) : GameRolePlayHumanoidInformations(contextualId, look, disposition, name, humanoidInfo, accountId)
{
	this->alignmentInfos = alignmentInfos;

}

GameRolePlayCharacterInformations::GameRolePlayCharacterInformations()
{

}

ushort GameRolePlayCharacterInformations::getId()
{
	return __id;
}

std::string GameRolePlayCharacterInformations::getName()
{
	return "GameRolePlayCharacterInformations";
}

void GameRolePlayCharacterInformations::serialize(BinaryWriter& writer)
{
	GameRolePlayHumanoidInformations::serialize(writer);
	this->alignmentInfos.serialize(writer);

}

void GameRolePlayCharacterInformations::deserialize(BinaryReader& reader)
{
	{		GameRolePlayHumanoidInformations::deserialize(reader);		this->alignmentInfos.deserialize(reader);	}
}