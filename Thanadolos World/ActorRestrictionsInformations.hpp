#pragma once
#ifndef ACTORRESTRICTIONSINFORMATIONS_THANADOLOS_HPP
#define ACTORRESTRICTIONSINFORMATIONS_THANADOLOS_HPP

#include "IType.hpp"


class ActorRestrictionsInformations : public IType
{
public:
	ActorRestrictionsInformations(bool cantBeAggressed, bool cantBeChallenged, bool cantTrade, bool cantBeAttackedByMutant, bool cantRun, bool forceSlowWalk, bool cantMinimize, bool cantMove, bool cantAggress, bool cantChallenge, bool cantExchange, bool cantAttack, bool cantChat, bool cantBeMerchant, bool cantUseObject, bool cantUseTaxCollector, bool cantUseInteractive, bool cantSpeakToNPC, bool cantChangeZone, bool cantAttackMonster, bool cantWalk8Directions);
	ActorRestrictionsInformations();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int __id = 204;

	/*VARS*/
	bool cantBeAggressed;
	bool cantBeChallenged;
	bool cantTrade;
	bool cantBeAttackedByMutant;
	bool cantRun;
	bool forceSlowWalk;
	bool cantMinimize;
	bool cantMove;
	bool cantAggress;
	bool cantChallenge;
	bool cantExchange;
	bool cantAttack;
	bool cantChat;
	bool cantBeMerchant;
	bool cantUseObject;
	bool cantUseTaxCollector;
	bool cantUseInteractive;
	bool cantSpeakToNPC;
	bool cantChangeZone;
	bool cantAttackMonster;
	bool cantWalk8Directions;
};


#endif