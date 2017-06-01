#pragma once

#ifndef SPELLSLEVELSRECORD_HPP
# define SPELLSLEVELSRECORD_HPP

#include <iostream>
class SpellsLevelsRecord
{
public:
	static void declareRecord()
	{
		camp::Class::declare<SpellsLevelsRecord>("SpellsLevelsRecord")
			.constructor0().property("id", &SpellsLevelsRecord::getid, &SpellsLevelsRecord::setid)
			.property("spellId", &SpellsLevelsRecord::getspellId, &SpellsLevelsRecord::setspellId)
			.property("grade", &SpellsLevelsRecord::getgrade, &SpellsLevelsRecord::setgrade)
			.property("spellBreed", &SpellsLevelsRecord::getspellBreed, &SpellsLevelsRecord::setspellBreed)
			.property("apCost", &SpellsLevelsRecord::getapCost, &SpellsLevelsRecord::setapCost)
			.property("minRange", &SpellsLevelsRecord::getminRange, &SpellsLevelsRecord::setminRange)
			.property("rangeLevel", &SpellsLevelsRecord::getrangeLevel, &SpellsLevelsRecord::setrangeLevel)
			.property("castInLine", &SpellsLevelsRecord::getcastInLine, &SpellsLevelsRecord::setcastInLine)
			.property("castInDiagonal", &SpellsLevelsRecord::getcastInDiagonal, &SpellsLevelsRecord::setcastInDiagonal)
			.property("castTestLos", &SpellsLevelsRecord::getcastTestLos, &SpellsLevelsRecord::setcastTestLos)
			.property("criticalHitProbability", &SpellsLevelsRecord::getcriticalHitProbability, &SpellsLevelsRecord::setcriticalHitProbability)
			.property("needFreeCell", &SpellsLevelsRecord::getneedFreeCell, &SpellsLevelsRecord::setneedFreeCell)
			.property("needTakenCell", &SpellsLevelsRecord::getneedTakenCell, &SpellsLevelsRecord::setneedTakenCell)
			.property("needFreeTrapCell", &SpellsLevelsRecord::getneedFreeTrapCell, &SpellsLevelsRecord::setneedFreeTrapCell)
			.property("rangeCanBeBoosted", &SpellsLevelsRecord::getrangeCanBeBoosted, &SpellsLevelsRecord::setrangeCanBeBoosted)
			.property("maxStack", &SpellsLevelsRecord::getmaxStack, &SpellsLevelsRecord::setmaxStack)
			.property("maxCastPerTurn", &SpellsLevelsRecord::getmaxCastPerTurn, &SpellsLevelsRecord::setmaxCastPerTurn)
			.property("maxCastPerTarget", &SpellsLevelsRecord::getmaxCastPerTarget, &SpellsLevelsRecord::setmaxCastPerTarget)
			.property("minCastInterval", &SpellsLevelsRecord::getminCastInterval, &SpellsLevelsRecord::setminCastInterval)
			.property("initialCooldown", &SpellsLevelsRecord::getinitialCooldown, &SpellsLevelsRecord::setinitialCooldown)
			.property("globalCooldown", &SpellsLevelsRecord::getglobalCooldown, &SpellsLevelsRecord::setglobalCooldown)
			.property("minPlayerLevel", &SpellsLevelsRecord::getminPlayerLevel, &SpellsLevelsRecord::setminPlayerLevel)
			.property("hideEffects", &SpellsLevelsRecord::gethideEffects, &SpellsLevelsRecord::sethideEffects)
			.property("hidden", &SpellsLevelsRecord::gethidden, &SpellsLevelsRecord::sethidden)
			.property("playAnimation", &SpellsLevelsRecord::getplayAnimation, &SpellsLevelsRecord::setplayAnimation)
			.property("statesRequired", &SpellsLevelsRecord::getstatesRequired, &SpellsLevelsRecord::setstatesRequired)
			.property("statesForbidden", &SpellsLevelsRecord::getstatesForbidden, &SpellsLevelsRecord::setstatesForbidden)
			.property("effects", &SpellsLevelsRecord::geteffects, &SpellsLevelsRecord::seteffects)
			.property("criticalEffect", &SpellsLevelsRecord::getcriticalEffect, &SpellsLevelsRecord::setcriticalEffect);

	}
	SpellsLevelsRecord() { }

	int getid() { return this->id; }
	void setid(int var) { this->id = var; }

	int getspellId() { return this->spellId; }
	void setspellId(int var) { this->spellId = var; }

	int getgrade() { return this->grade; }
	void setgrade(int var) { this->grade = var; }

	int getspellBreed() { return this->spellBreed; }
	void setspellBreed(int var) { this->spellBreed = var; }

	int getapCost() { return this->apCost; }
	void setapCost(int var) { this->apCost = var; }

	int getminRange() { return this->minRange; }
	void setminRange(int var) { this->minRange = var; }

	int getrangeLevel() { return this->rangeLevel; }
	void setrangeLevel(int var) { this->rangeLevel = var; }

	int getcastInLine() { return this->castInLine; }
	void setcastInLine(int var) { this->castInLine = var; }

	int getcastInDiagonal() { return this->castInDiagonal; }
	void setcastInDiagonal(int var) { this->castInDiagonal = var; }

	int getcastTestLos() { return this->castTestLos; }
	void setcastTestLos(int var) { this->castTestLos = var; }

	int getcriticalHitProbability() { return this->criticalHitProbability; }
	void setcriticalHitProbability(int var) { this->criticalHitProbability = var; }

	int getneedFreeCell() { return this->needFreeCell; }
	void setneedFreeCell(int var) { this->needFreeCell = var; }

	int getneedTakenCell() { return this->needTakenCell; }
	void setneedTakenCell(int var) { this->needTakenCell = var; }

	int getneedFreeTrapCell() { return this->needFreeTrapCell; }
	void setneedFreeTrapCell(int var) { this->needFreeTrapCell = var; }

	int getrangeCanBeBoosted() { return this->rangeCanBeBoosted; }
	void setrangeCanBeBoosted(int var) { this->rangeCanBeBoosted = var; }

	int getmaxStack() { return this->maxStack; }
	void setmaxStack(int var) { this->maxStack = var; }

	int getmaxCastPerTurn() { return this->maxCastPerTurn; }
	void setmaxCastPerTurn(int var) { this->maxCastPerTurn = var; }

	int getmaxCastPerTarget() { return this->maxCastPerTarget; }
	void setmaxCastPerTarget(int var) { this->maxCastPerTarget = var; }

	int getminCastInterval() { return this->minCastInterval; }
	void setminCastInterval(int var) { this->minCastInterval = var; }

	int getinitialCooldown() { return this->initialCooldown; }
	void setinitialCooldown(int var) { this->initialCooldown = var; }

	int getglobalCooldown() { return this->globalCooldown; }
	void setglobalCooldown(int var) { this->globalCooldown = var; }

	int getminPlayerLevel() { return this->minPlayerLevel; }
	void setminPlayerLevel(int var) { this->minPlayerLevel = var; }

	int gethideEffects() { return this->hideEffects; }
	void sethideEffects(int var) { this->hideEffects = var; }

	int gethidden() { return this->hidden; }
	void sethidden(int var) { this->hidden = var; }

	int getplayAnimation() { return this->playAnimation; }
	void setplayAnimation(int var) { this->playAnimation = var; }

	std::string getstatesRequired() { return this->statesRequired; }
	void setstatesRequired(std::string var) { this->statesRequired = var; }

	std::string getstatesForbidden() { return this->statesForbidden; }
	void setstatesForbidden(std::string var) { this->statesForbidden = var; }

	std::string geteffects() { return this->effects; }
	void seteffects(std::string var) { this->effects = var; }

	std::string getcriticalEffect() { return this->criticalEffect; }
	void setcriticalEffect(std::string var) { this->criticalEffect = var; }



private:
	int id;
	int spellId;
	int grade;
	int spellBreed;
	int apCost;
	int minRange;
	int rangeLevel;
	int castInLine;
	int castInDiagonal;
	int castTestLos;
	int criticalHitProbability;
	int needFreeCell;
	int needTakenCell;
	int needFreeTrapCell;
	int rangeCanBeBoosted;
	int maxStack;
	int maxCastPerTurn;
	int maxCastPerTarget;
	int minCastInterval;
	int initialCooldown;
	int globalCooldown;
	int minPlayerLevel;
	int hideEffects;
	int hidden;
	int playAnimation;
	std::string statesRequired;
	std::string statesForbidden;
	std::string effects;
	std::string criticalEffect;
};

CAMP_TYPE(SpellsLevelsRecord)

#endif
