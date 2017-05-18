#include "Globals.h"
#include "ActorRestrictionsInformations.hpp"

ActorRestrictionsInformations::ActorRestrictionsInformations(bool cantBeAggressed, bool cantBeChallenged, bool cantTrade, bool cantBeAttackedByMutant, bool cantRun, bool forceSlowWalk, bool cantMinimize, bool cantMove, bool cantAggress, bool cantChallenge, bool cantExchange, bool cantAttack, bool cantChat, bool cantBeMerchant, bool cantUseObject, bool cantUseTaxCollector, bool cantUseInteractive, bool cantSpeakToNPC, bool cantChangeZone, bool cantAttackMonster, bool cantWalk8Directions)
{
	this->cantBeAggressed = cantBeAggressed;
	this->cantBeChallenged = cantBeChallenged;
	this->cantTrade = cantTrade;
	this->cantBeAttackedByMutant = cantBeAttackedByMutant;
	this->cantRun = cantRun;
	this->forceSlowWalk = forceSlowWalk;
	this->cantMinimize = cantMinimize;
	this->cantMove = cantMove;
	this->cantAggress = cantAggress;
	this->cantChallenge = cantChallenge;
	this->cantExchange = cantExchange;
	this->cantAttack = cantAttack;
	this->cantChat = cantChat;
	this->cantBeMerchant = cantBeMerchant;
	this->cantUseObject = cantUseObject;
	this->cantUseTaxCollector = cantUseTaxCollector;
	this->cantUseInteractive = cantUseInteractive;
	this->cantSpeakToNPC = cantSpeakToNPC;
	this->cantChangeZone = cantChangeZone;
	this->cantAttackMonster = cantAttackMonster;
	this->cantWalk8Directions = cantWalk8Directions;

}

ActorRestrictionsInformations::ActorRestrictionsInformations()
{

}

ushort ActorRestrictionsInformations::getId()
{
	return __id;
}

std::string ActorRestrictionsInformations::getName()
{
	return "ActorRestrictionsInformations";
}

void ActorRestrictionsInformations::serialize(BinaryWriter& writer)
{
	int _loc2_ = 0;
	_loc2_ = BooleanByteWrapper::setFlag(_loc2_, 0, this->cantBeAggressed);
	_loc3_ = BooleanByteWrapper::setFlag(_loc3_, 0, this->cantAggress);
	_loc4_ = BooleanByteWrapper::setFlag(_loc4_, 0, this->cantUseInteractive);
}

void ActorRestrictionsInformations::deserialize(BinaryReader& reader)
{
	{
}