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
	_loc2_ = BooleanByteWrapper::setFlag(_loc2_, 0, this->cantBeAggressed);	_loc2_ = BooleanByteWrapper::setFlag(_loc2_, 1, this->cantBeChallenged);	_loc2_ = BooleanByteWrapper::setFlag(_loc2_, 2, this->cantTrade);	_loc2_ = BooleanByteWrapper::setFlag(_loc2_, 3, this->cantBeAttackedByMutant);	_loc2_ = BooleanByteWrapper::setFlag(_loc2_, 4, this->cantRun);	_loc2_ = BooleanByteWrapper::setFlag(_loc2_, 5, this->forceSlowWalk);	_loc2_ = BooleanByteWrapper::setFlag(_loc2_, 6, this->cantMinimize);	_loc2_ = BooleanByteWrapper::setFlag(_loc2_, 7, this->cantMove);	writer.writeByte(_loc2_);	int _loc3_ = 0;
	_loc3_ = BooleanByteWrapper::setFlag(_loc3_, 0, this->cantAggress);	_loc3_ = BooleanByteWrapper::setFlag(_loc3_, 1, this->cantChallenge);	_loc3_ = BooleanByteWrapper::setFlag(_loc3_, 2, this->cantExchange);	_loc3_ = BooleanByteWrapper::setFlag(_loc3_, 3, this->cantAttack);	_loc3_ = BooleanByteWrapper::setFlag(_loc3_, 4, this->cantChat);	_loc3_ = BooleanByteWrapper::setFlag(_loc3_, 5, this->cantBeMerchant);	_loc3_ = BooleanByteWrapper::setFlag(_loc3_, 6, this->cantUseObject);	_loc3_ = BooleanByteWrapper::setFlag(_loc3_, 7, this->cantUseTaxCollector);	writer.writeByte(_loc3_);	int _loc4_ = 0;
	_loc4_ = BooleanByteWrapper::setFlag(_loc4_, 0, this->cantUseInteractive);	_loc4_ = BooleanByteWrapper::setFlag(_loc4_, 1, this->cantSpeakToNPC);	_loc4_ = BooleanByteWrapper::setFlag(_loc4_, 2, this->cantChangeZone);	_loc4_ = BooleanByteWrapper::setFlag(_loc4_, 3, this->cantAttackMonster);	_loc4_ = BooleanByteWrapper::setFlag(_loc4_, 4, this->cantWalk8Directions);	writer.writeByte(_loc4_);
}

void ActorRestrictionsInformations::deserialize(BinaryReader& reader)
{
	{		int _loc2_ = reader.readByte();		this->cantBeAggressed = BooleanByteWrapper::getFlag(_loc2_, 0);		this->cantBeChallenged = BooleanByteWrapper::getFlag(_loc2_, 1);		this->cantTrade = BooleanByteWrapper::getFlag(_loc2_, 2);		this->cantBeAttackedByMutant = BooleanByteWrapper::getFlag(_loc2_, 3);		this->cantRun = BooleanByteWrapper::getFlag(_loc2_, 4);		this->forceSlowWalk = BooleanByteWrapper::getFlag(_loc2_, 5);		this->cantMinimize = BooleanByteWrapper::getFlag(_loc2_, 6);		this->cantMove = BooleanByteWrapper::getFlag(_loc2_, 7);		int _loc3_ = reader.readByte();		this->cantAggress = BooleanByteWrapper::getFlag(_loc3_, 0);		this->cantChallenge = BooleanByteWrapper::getFlag(_loc3_, 1);		this->cantExchange = BooleanByteWrapper::getFlag(_loc3_, 2);		this->cantAttack = BooleanByteWrapper::getFlag(_loc3_, 3);		this->cantChat = BooleanByteWrapper::getFlag(_loc3_, 4);		this->cantBeMerchant = BooleanByteWrapper::getFlag(_loc3_, 5);		this->cantUseObject = BooleanByteWrapper::getFlag(_loc3_, 6);		this->cantUseTaxCollector = BooleanByteWrapper::getFlag(_loc3_, 7);		int _loc4_ = reader.readByte();		this->cantUseInteractive = BooleanByteWrapper::getFlag(_loc4_, 0);		this->cantSpeakToNPC = BooleanByteWrapper::getFlag(_loc4_, 1);		this->cantChangeZone = BooleanByteWrapper::getFlag(_loc4_, 2);		this->cantAttackMonster = BooleanByteWrapper::getFlag(_loc4_, 3);		this->cantWalk8Directions = BooleanByteWrapper::getFlag(_loc4_, 4);	}
}