#include "Globals.h"
#include "GameRolePlayHumanoidInformations.hpp"

GameRolePlayHumanoidInformations::GameRolePlayHumanoidInformations(int contextualId, EntityLook& look, EntityDispositionInformations& disposition, std::string name, HumanInformations& humanoidInfo, int accountId) : GameRolePlayNamedActorInformations(contextualId, look, disposition, name)
{
	this->humanoidInfo = humanoidInfo;
	this->accountId = accountId;

}

GameRolePlayHumanoidInformations::GameRolePlayHumanoidInformations()
{

}

ushort GameRolePlayHumanoidInformations::getId()
{
	return __id;
}

std::string GameRolePlayHumanoidInformations::getName()
{
	return "GameRolePlayHumanoidInformations";
}

void GameRolePlayHumanoidInformations::serialize(BinaryWriter& writer)
{
	GameRolePlayNamedActorInformations::serialize(writer);
	writer.writeShort(this->humanoidInfo.getId());	this->humanoidInfo.serialize(writer);	writer.writeInt(this->accountId);
}

void GameRolePlayHumanoidInformations::deserialize(BinaryReader& reader)
{
	{		GameRolePlayNamedActorInformations::deserialize(reader);		int _loc2_ = reader.readUnsignedShort();		this->humanoidInfo.deserialize(reader);		this->accountId = reader.readInt();	}
}