#pragma once

#ifndef ITEMSRECORD_HPP
# define ITEMSRECORD_HPP

#include <iostream>
class ItemsRecord
{
public:
	static void declareRecord()
	{
		camp::Class::declare<ItemsRecord>("ItemsRecord")
			.constructor0().property("id", &ItemsRecord::getid, &ItemsRecord::setid)
			.property("resourcesBySubarea", &ItemsRecord::getresourcesBySubarea, &ItemsRecord::setresourcesBySubarea)
			.property("favoriteSubAreasBonus", &ItemsRecord::getfavoriteSubAreasBonus, &ItemsRecord::setfavoriteSubAreasBonus)
			.property("craftXpRatio", &ItemsRecord::getcraftXpRatio, &ItemsRecord::setcraftXpRatio)
			.property("itemRange", &ItemsRecord::getitemRange, &ItemsRecord::setitemRange)
			.property("bonusIsSecret", &ItemsRecord::getbonusIsSecret, &ItemsRecord::setbonusIsSecret)
			.property("criticalHitBonus", &ItemsRecord::getcriticalHitBonus, &ItemsRecord::setcriticalHitBonus)
			.property("criteriaTarget", &ItemsRecord::getcriteriaTarget, &ItemsRecord::setcriteriaTarget)
			.property("minRange", &ItemsRecord::getminRange, &ItemsRecord::setminRange)
			.property("containerIds", &ItemsRecord::getcontainerIds, &ItemsRecord::setcontainerIds)
			.property("maxCastPerTurn", &ItemsRecord::getmaxCastPerTurn, &ItemsRecord::setmaxCastPerTurn)
			.property("descriptionId", &ItemsRecord::getdescriptionId, &ItemsRecord::setdescriptionId)
			.property("recipeIds", &ItemsRecord::getrecipeIds, &ItemsRecord::setrecipeIds)
			.property("secretRecipe", &ItemsRecord::getsecretRecipe, &ItemsRecord::setsecretRecipe)
			.property("etheral", &ItemsRecord::getetheral, &ItemsRecord::setetheral)
			.property("appearanceId", &ItemsRecord::getappearanceId, &ItemsRecord::setappearanceId)
			.property("dropMonsterIds", &ItemsRecord::getdropMonsterIds, &ItemsRecord::setdropMonsterIds)
			.property("cursed", &ItemsRecord::getcursed, &ItemsRecord::setcursed)
			.property("exchangeable", &ItemsRecord::getexchangeable, &ItemsRecord::setexchangeable)
			.property("level", &ItemsRecord::getlevel, &ItemsRecord::setlevel)
			.property("realWeight", &ItemsRecord::getrealWeight, &ItemsRecord::setrealWeight)
			.property("castTestLos", &ItemsRecord::getcastTestLos, &ItemsRecord::setcastTestLos)
			.property("favoriteSubAreas", &ItemsRecord::getfavoriteSubAreas, &ItemsRecord::setfavoriteSubAreas)
			.property("criticalFailureProbability", &ItemsRecord::getcriticalFailureProbability, &ItemsRecord::setcriticalFailureProbability)
			.property("hideEffects", &ItemsRecord::gethideEffects, &ItemsRecord::sethideEffects)
			.property("criteria", &ItemsRecord::getcriteria, &ItemsRecord::setcriteria)
			.property("targetable", &ItemsRecord::gettargetable, &ItemsRecord::settargetable)
			.property("criticalHitProbability", &ItemsRecord::getcriticalHitProbability, &ItemsRecord::setcriticalHitProbability)
			.property("twoHanded", &ItemsRecord::gettwoHanded, &ItemsRecord::settwoHanded)
			.property("nonUsableOnAnother", &ItemsRecord::getnonUsableOnAnother, &ItemsRecord::setnonUsableOnAnother)
			.property("itemSetId", &ItemsRecord::getitemSetId, &ItemsRecord::setitemSetId)
			.property("nameId", &ItemsRecord::getnameId, &ItemsRecord::setnameId)
			.property("castInDiagonal", &ItemsRecord::getcastInDiagonal, &ItemsRecord::setcastInDiagonal)
			.property("price", &ItemsRecord::getprice, &ItemsRecord::setprice)
			.property("enhanceable", &ItemsRecord::getenhanceable, &ItemsRecord::setenhanceable)
			.property("needUseConfirm", &ItemsRecord::getneedUseConfirm, &ItemsRecord::setneedUseConfirm)
			.property("apCost", &ItemsRecord::getapCost, &ItemsRecord::setapCost)
			.property("usable", &ItemsRecord::getusable, &ItemsRecord::setusable)
			.property("castInLine", &ItemsRecord::getcastInLine, &ItemsRecord::setcastInLine)
			.property("possibleEffects", &ItemsRecord::getpossibleEffects, &ItemsRecord::setpossibleEffects)
			.property("useAnimationId", &ItemsRecord::getuseAnimationId, &ItemsRecord::setuseAnimationId)
			.property("iconId", &ItemsRecord::geticonId, &ItemsRecord::seticonId)
			.property("nuggetsBySubarea", &ItemsRecord::getnuggetsBySubarea, &ItemsRecord::setnuggetsBySubarea)
			.property("isDestructible", &ItemsRecord::getisDestructible, &ItemsRecord::setisDestructible)
			.property("typeId", &ItemsRecord::gettypeId, &ItemsRecord::settypeId)
			.property("recipeSlots", &ItemsRecord::getrecipeSlots, &ItemsRecord::setrecipeSlots);

	}
	ItemsRecord() { }

	int getid() { return this->id; }
	void setid(int var) { this->id = var; }

	std::string getresourcesBySubarea() { return this->resourcesBySubarea; }
	void setresourcesBySubarea(std::string var) { this->resourcesBySubarea = var; }

	int getfavoriteSubAreasBonus() { return this->favoriteSubAreasBonus; }
	void setfavoriteSubAreasBonus(int var) { this->favoriteSubAreasBonus = var; }

	int getcraftXpRatio() { return this->craftXpRatio; }
	void setcraftXpRatio(int var) { this->craftXpRatio = var; }

	int getitemRange() { return this->itemRange; }
	void setitemRange(int var) { this->itemRange = var; }

	int getbonusIsSecret() { return this->bonusIsSecret; }
	void setbonusIsSecret(int var) { this->bonusIsSecret = var; }

	int getcriticalHitBonus() { return this->criticalHitBonus; }
	void setcriticalHitBonus(int var) { this->criticalHitBonus = var; }

	std::string getcriteriaTarget() { return this->criteriaTarget; }
	void setcriteriaTarget(std::string var) { this->criteriaTarget = var; }

	int getminRange() { return this->minRange; }
	void setminRange(int var) { this->minRange = var; }

	std::string getcontainerIds() { return this->containerIds; }
	void setcontainerIds(std::string var) { this->containerIds = var; }

	int getmaxCastPerTurn() { return this->maxCastPerTurn; }
	void setmaxCastPerTurn(int var) { this->maxCastPerTurn = var; }

	int getdescriptionId() { return this->descriptionId; }
	void setdescriptionId(int var) { this->descriptionId = var; }

	std::string getrecipeIds() { return this->recipeIds; }
	void setrecipeIds(std::string var) { this->recipeIds = var; }

	int getsecretRecipe() { return this->secretRecipe; }
	void setsecretRecipe(int var) { this->secretRecipe = var; }

	int getetheral() { return this->etheral; }
	void setetheral(int var) { this->etheral = var; }

	int getappearanceId() { return this->appearanceId; }
	void setappearanceId(int var) { this->appearanceId = var; }

	std::string getdropMonsterIds() { return this->dropMonsterIds; }
	void setdropMonsterIds(std::string var) { this->dropMonsterIds = var; }

	int getcursed() { return this->cursed; }
	void setcursed(int var) { this->cursed = var; }

	int getexchangeable() { return this->exchangeable; }
	void setexchangeable(int var) { this->exchangeable = var; }

	int getlevel() { return this->level; }
	void setlevel(int var) { this->level = var; }

	int getrealWeight() { return this->realWeight; }
	void setrealWeight(int var) { this->realWeight = var; }

	int getcastTestLos() { return this->castTestLos; }
	void setcastTestLos(int var) { this->castTestLos = var; }

	std::string getfavoriteSubAreas() { return this->favoriteSubAreas; }
	void setfavoriteSubAreas(std::string var) { this->favoriteSubAreas = var; }

	int getcriticalFailureProbability() { return this->criticalFailureProbability; }
	void setcriticalFailureProbability(int var) { this->criticalFailureProbability = var; }

	int gethideEffects() { return this->hideEffects; }
	void sethideEffects(int var) { this->hideEffects = var; }

	std::string getcriteria() { return this->criteria; }
	void setcriteria(std::string var) { this->criteria = var; }

	int gettargetable() { return this->targetable; }
	void settargetable(int var) { this->targetable = var; }

	int getcriticalHitProbability() { return this->criticalHitProbability; }
	void setcriticalHitProbability(int var) { this->criticalHitProbability = var; }

	int gettwoHanded() { return this->twoHanded; }
	void settwoHanded(int var) { this->twoHanded = var; }

	int getnonUsableOnAnother() { return this->nonUsableOnAnother; }
	void setnonUsableOnAnother(int var) { this->nonUsableOnAnother = var; }

	int getitemSetId() { return this->itemSetId; }
	void setitemSetId(int var) { this->itemSetId = var; }

	int getnameId() { return this->nameId; }
	void setnameId(int var) { this->nameId = var; }

	int getcastInDiagonal() { return this->castInDiagonal; }
	void setcastInDiagonal(int var) { this->castInDiagonal = var; }

	int getprice() { return this->price; }
	void setprice(int var) { this->price = var; }

	int getenhanceable() { return this->enhanceable; }
	void setenhanceable(int var) { this->enhanceable = var; }

	int getneedUseConfirm() { return this->needUseConfirm; }
	void setneedUseConfirm(int var) { this->needUseConfirm = var; }

	int getapCost() { return this->apCost; }
	void setapCost(int var) { this->apCost = var; }

	int getusable() { return this->usable; }
	void setusable(int var) { this->usable = var; }

	int getcastInLine() { return this->castInLine; }
	void setcastInLine(int var) { this->castInLine = var; }

	std::string getpossibleEffects() { return this->possibleEffects; }
	void setpossibleEffects(std::string var) { this->possibleEffects = var; }

	int getuseAnimationId() { return this->useAnimationId; }
	void setuseAnimationId(int var) { this->useAnimationId = var; }

	int geticonId() { return this->iconId; }
	void seticonId(int var) { this->iconId = var; }

	std::string getnuggetsBySubarea() { return this->nuggetsBySubarea; }
	void setnuggetsBySubarea(std::string var) { this->nuggetsBySubarea = var; }

	int getisDestructible() { return this->isDestructible; }
	void setisDestructible(int var) { this->isDestructible = var; }

	int gettypeId() { return this->typeId; }
	void settypeId(int var) { this->typeId = var; }

	int getrecipeSlots() { return this->recipeSlots; }
	void setrecipeSlots(int var) { this->recipeSlots = var; }



private:
	int id;
	std::string resourcesBySubarea;
	int favoriteSubAreasBonus;
	int craftXpRatio;
	int itemRange;
	int bonusIsSecret;
	int criticalHitBonus;
	std::string criteriaTarget;
	int minRange;
	std::string containerIds;
	int maxCastPerTurn;
	int descriptionId;
	std::string recipeIds;
	int secretRecipe;
	int etheral;
	int appearanceId;
	std::string dropMonsterIds;
	int cursed;
	int exchangeable;
	int level;
	int realWeight;
	int castTestLos;
	std::string favoriteSubAreas;
	int criticalFailureProbability;
	int hideEffects;
	std::string criteria;
	int targetable;
	int criticalHitProbability;
	int twoHanded;
	int nonUsableOnAnother;
	int itemSetId;
	int nameId;
	int castInDiagonal;
	int price;
	int enhanceable;
	int needUseConfirm;
	int apCost;
	int usable;
	int castInLine;
	std::string possibleEffects;
	int useAnimationId;
	int iconId;
	std::string nuggetsBySubarea;
	int isDestructible;
	int typeId;
	int recipeSlots;
};

CAMP_TYPE(ItemsRecord)

#endif
