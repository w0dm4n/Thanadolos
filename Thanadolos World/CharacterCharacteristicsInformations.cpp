#include "Globals.h"
#include "CharacterCharacteristicsInformations.hpp"

CharacterCharacteristicsInformations::CharacterCharacteristicsInformations(long long int experience, long long int experienceLevelFloor, long long int experienceNextLevelFloor, int experienceBonusLimit, int kamas, int statsPoints, int additionnalPoints, int spellsPoints, ActorExtendedAlignmentInformations& alignmentInfos, int lifePoints, int maxLifePoints, int energyPoints, int maxEnergyPoints, int actionPointsCurrent, int movementPointsCurrent, CharacterBaseCharacteristic& initiative, CharacterBaseCharacteristic& prospecting, CharacterBaseCharacteristic& actionPoints, CharacterBaseCharacteristic& movementPoints, CharacterBaseCharacteristic& strength, CharacterBaseCharacteristic& vitality, CharacterBaseCharacteristic& wisdom, CharacterBaseCharacteristic& chance, CharacterBaseCharacteristic& agility, CharacterBaseCharacteristic& intelligence, CharacterBaseCharacteristic& range, CharacterBaseCharacteristic& summonableCreaturesBoost, CharacterBaseCharacteristic& reflect, CharacterBaseCharacteristic& criticalHit, int criticalHitWeapon, CharacterBaseCharacteristic& criticalMiss, CharacterBaseCharacteristic& healBonus, CharacterBaseCharacteristic& allDamagesBonus, CharacterBaseCharacteristic& weaponDamagesBonusPercent, CharacterBaseCharacteristic& damagesBonusPercent, CharacterBaseCharacteristic& trapBonus, CharacterBaseCharacteristic& trapBonusPercent, CharacterBaseCharacteristic& glyphBonusPercent, CharacterBaseCharacteristic& runeBonusPercent, CharacterBaseCharacteristic& permanentDamagePercent, CharacterBaseCharacteristic& tackleBlock, CharacterBaseCharacteristic& tackleEvade, CharacterBaseCharacteristic& PAAttack, CharacterBaseCharacteristic& PMAttack, CharacterBaseCharacteristic& pushDamageBonus, CharacterBaseCharacteristic& criticalDamageBonus, CharacterBaseCharacteristic& neutralDamageBonus, CharacterBaseCharacteristic& earthDamageBonus, CharacterBaseCharacteristic& waterDamageBonus, CharacterBaseCharacteristic& airDamageBonus, CharacterBaseCharacteristic& fireDamageBonus, CharacterBaseCharacteristic& dodgePALostProbability, CharacterBaseCharacteristic& dodgePMLostProbability, CharacterBaseCharacteristic& neutralElementResistPercent, CharacterBaseCharacteristic& earthElementResistPercent, CharacterBaseCharacteristic& waterElementResistPercent, CharacterBaseCharacteristic& airElementResistPercent, CharacterBaseCharacteristic& fireElementResistPercent, CharacterBaseCharacteristic& neutralElementReduction, CharacterBaseCharacteristic& earthElementReduction, CharacterBaseCharacteristic& waterElementReduction, CharacterBaseCharacteristic& airElementReduction, CharacterBaseCharacteristic& fireElementReduction, CharacterBaseCharacteristic& pushDamageReduction, CharacterBaseCharacteristic& criticalDamageReduction, CharacterBaseCharacteristic& pvpNeutralElementResistPercent, CharacterBaseCharacteristic& pvpEarthElementResistPercent, CharacterBaseCharacteristic& pvpWaterElementResistPercent, CharacterBaseCharacteristic& pvpAirElementResistPercent, CharacterBaseCharacteristic& pvpFireElementResistPercent, CharacterBaseCharacteristic& pvpNeutralElementReduction, CharacterBaseCharacteristic& pvpEarthElementReduction, CharacterBaseCharacteristic& pvpWaterElementReduction, CharacterBaseCharacteristic& pvpAirElementReduction, CharacterBaseCharacteristic& pvpFireElementReduction, std::vector<CharacterSpellModification> spellModifications, int probationTime)
{
	this->experience = experience;
	this->experienceLevelFloor = experienceLevelFloor;
	this->experienceNextLevelFloor = experienceNextLevelFloor;
	this->experienceBonusLimit = experienceBonusLimit;
	this->kamas = kamas;
	this->statsPoints = statsPoints;
	this->additionnalPoints = additionnalPoints;
	this->spellsPoints = spellsPoints;
	this->alignmentInfos = alignmentInfos;
	this->lifePoints = lifePoints;
	this->maxLifePoints = maxLifePoints;
	this->energyPoints = energyPoints;
	this->maxEnergyPoints = maxEnergyPoints;
	this->actionPointsCurrent = actionPointsCurrent;
	this->movementPointsCurrent = movementPointsCurrent;
	this->initiative = initiative;
	this->prospecting = prospecting;
	this->actionPoints = actionPoints;
	this->movementPoints = movementPoints;
	this->strength = strength;
	this->vitality = vitality;
	this->wisdom = wisdom;
	this->chance = chance;
	this->agility = agility;
	this->intelligence = intelligence;
	this->range = range;
	this->summonableCreaturesBoost = summonableCreaturesBoost;
	this->reflect = reflect;
	this->criticalHit = criticalHit;
	this->criticalHitWeapon = criticalHitWeapon;
	this->criticalMiss = criticalMiss;
	this->healBonus = healBonus;
	this->allDamagesBonus = allDamagesBonus;
	this->weaponDamagesBonusPercent = weaponDamagesBonusPercent;
	this->damagesBonusPercent = damagesBonusPercent;
	this->trapBonus = trapBonus;
	this->trapBonusPercent = trapBonusPercent;
	this->glyphBonusPercent = glyphBonusPercent;
	this->runeBonusPercent = runeBonusPercent;
	this->permanentDamagePercent = permanentDamagePercent;
	this->tackleBlock = tackleBlock;
	this->tackleEvade = tackleEvade;
	this->PAAttack = PAAttack;
	this->PMAttack = PMAttack;
	this->pushDamageBonus = pushDamageBonus;
	this->criticalDamageBonus = criticalDamageBonus;
	this->neutralDamageBonus = neutralDamageBonus;
	this->earthDamageBonus = earthDamageBonus;
	this->waterDamageBonus = waterDamageBonus;
	this->airDamageBonus = airDamageBonus;
	this->fireDamageBonus = fireDamageBonus;
	this->dodgePALostProbability = dodgePALostProbability;
	this->dodgePMLostProbability = dodgePMLostProbability;
	this->neutralElementResistPercent = neutralElementResistPercent;
	this->earthElementResistPercent = earthElementResistPercent;
	this->waterElementResistPercent = waterElementResistPercent;
	this->airElementResistPercent = airElementResistPercent;
	this->fireElementResistPercent = fireElementResistPercent;
	this->neutralElementReduction = neutralElementReduction;
	this->earthElementReduction = earthElementReduction;
	this->waterElementReduction = waterElementReduction;
	this->airElementReduction = airElementReduction;
	this->fireElementReduction = fireElementReduction;
	this->pushDamageReduction = pushDamageReduction;
	this->criticalDamageReduction = criticalDamageReduction;
	this->pvpNeutralElementResistPercent = pvpNeutralElementResistPercent;
	this->pvpEarthElementResistPercent = pvpEarthElementResistPercent;
	this->pvpWaterElementResistPercent = pvpWaterElementResistPercent;
	this->pvpAirElementResistPercent = pvpAirElementResistPercent;
	this->pvpFireElementResistPercent = pvpFireElementResistPercent;
	this->pvpNeutralElementReduction = pvpNeutralElementReduction;
	this->pvpEarthElementReduction = pvpEarthElementReduction;
	this->pvpWaterElementReduction = pvpWaterElementReduction;
	this->pvpAirElementReduction = pvpAirElementReduction;
	this->pvpFireElementReduction = pvpFireElementReduction;
	this->spellModifications = spellModifications;
	this->probationTime = probationTime;

}

CharacterCharacteristicsInformations::CharacterCharacteristicsInformations()
{

}

ushort CharacterCharacteristicsInformations::getId()
{
	return __id;
}

std::string CharacterCharacteristicsInformations::getName()
{
	return "CharacterCharacteristicsInformations";
}

void CharacterCharacteristicsInformations::serialize(BinaryWriter& writer)
{
	writer.writeVarLong(this->experience);
	writer.writeVarShort(this->lifePoints);
	this->prospecting.serialize(writer);
	this->actionPoints.serialize(writer);
	this->movementPoints.serialize(writer);
	this->strength.serialize(writer);
	this->vitality.serialize(writer);
	this->wisdom.serialize(writer);
	this->chance.serialize(writer);
	this->agility.serialize(writer);
	this->intelligence.serialize(writer);
	this->range.serialize(writer);
	this->summonableCreaturesBoost.serialize(writer);
	this->reflect.serialize(writer);
	this->criticalHit.serialize(writer);
	writer.writeVarShort(this->criticalHitWeapon);
	this->healBonus.serialize(writer);
	this->allDamagesBonus.serialize(writer);
	this->weaponDamagesBonusPercent.serialize(writer);
	this->damagesBonusPercent.serialize(writer);
	this->trapBonus.serialize(writer);
	this->trapBonusPercent.serialize(writer);
	this->glyphBonusPercent.serialize(writer);
	this->runeBonusPercent.serialize(writer);
	this->permanentDamagePercent.serialize(writer);
	this->tackleBlock.serialize(writer);
	this->tackleEvade.serialize(writer);
	this->PAAttack.serialize(writer);
	this->PMAttack.serialize(writer);
	this->pushDamageBonus.serialize(writer);
	this->criticalDamageBonus.serialize(writer);
	this->neutralDamageBonus.serialize(writer);
	this->earthDamageBonus.serialize(writer);
	this->waterDamageBonus.serialize(writer);
	this->airDamageBonus.serialize(writer);
	this->fireDamageBonus.serialize(writer);
	this->dodgePALostProbability.serialize(writer);
	this->dodgePMLostProbability.serialize(writer);
	this->neutralElementResistPercent.serialize(writer);
	this->earthElementResistPercent.serialize(writer);
	this->waterElementResistPercent.serialize(writer);
	this->airElementResistPercent.serialize(writer);
	this->fireElementResistPercent.serialize(writer);
	this->neutralElementReduction.serialize(writer);
	this->earthElementReduction.serialize(writer);
	this->waterElementReduction.serialize(writer);
	this->airElementReduction.serialize(writer);
	this->fireElementReduction.serialize(writer);
	this->pushDamageReduction.serialize(writer);
	this->criticalDamageReduction.serialize(writer);
	this->pvpNeutralElementResistPercent.serialize(writer);
	this->pvpEarthElementResistPercent.serialize(writer);
	this->pvpWaterElementResistPercent.serialize(writer);
	this->pvpAirElementResistPercent.serialize(writer);
	this->pvpFireElementResistPercent.serialize(writer);
	this->pvpNeutralElementReduction.serialize(writer);
	this->pvpEarthElementReduction.serialize(writer);
	this->pvpWaterElementReduction.serialize(writer);
	this->pvpAirElementReduction.serialize(writer);
	this->pvpFireElementReduction.serialize(writer);
	writer.writeShort(this->spellModifications.size());
	while (_loc2_ < this->spellModifications.size())
		_loc2_++;
}

void CharacterCharacteristicsInformations::deserialize(BinaryReader& reader)
{
	{
		this->experience = reader.readVarUhLong();
		while (_loc3_ < _loc2_)
}