#pragma once
#ifndef CHARACTERCHARACTERISTICSINFORMATIONS_THANADOLOS_HPP
#define CHARACTERCHARACTERISTICSINFORMATIONS_THANADOLOS_HPP

#include "IType.hpp"
#include "ActorExtendedAlignmentInformations.hpp"
#include "CharacterSpellModification.hpp"
#include "CharacterBaseCharacteristic.hpp" 

class CharacterCharacteristicsInformations : public IType
{
public:
	CharacterCharacteristicsInformations(long long int experience, long long int experienceLevelFloor, long long int experienceNextLevelFloor, int experienceBonusLimit, int kamas, int statsPoints, int additionnalPoints, int spellsPoints, ActorExtendedAlignmentInformations& alignmentInfos, int lifePoints, int maxLifePoints, int energyPoints, int maxEnergyPoints, int actionPointsCurrent, int movementPointsCurrent, CharacterBaseCharacteristic& initiative, CharacterBaseCharacteristic& prospecting, CharacterBaseCharacteristic& actionPoints, CharacterBaseCharacteristic& movementPoints, CharacterBaseCharacteristic& strength, CharacterBaseCharacteristic& vitality, CharacterBaseCharacteristic& wisdom, CharacterBaseCharacteristic& chance, CharacterBaseCharacteristic& agility, CharacterBaseCharacteristic& intelligence, CharacterBaseCharacteristic& range, CharacterBaseCharacteristic& summonableCreaturesBoost, CharacterBaseCharacteristic& reflect, CharacterBaseCharacteristic& criticalHit, int criticalHitWeapon, CharacterBaseCharacteristic& criticalMiss, CharacterBaseCharacteristic& healBonus, CharacterBaseCharacteristic& allDamagesBonus, CharacterBaseCharacteristic& weaponDamagesBonusPercent, CharacterBaseCharacteristic& damagesBonusPercent, CharacterBaseCharacteristic& trapBonus, CharacterBaseCharacteristic& trapBonusPercent, CharacterBaseCharacteristic& glyphBonusPercent, CharacterBaseCharacteristic& runeBonusPercent, CharacterBaseCharacteristic& permanentDamagePercent, CharacterBaseCharacteristic& tackleBlock, CharacterBaseCharacteristic& tackleEvade, CharacterBaseCharacteristic& PAAttack, CharacterBaseCharacteristic& PMAttack, CharacterBaseCharacteristic& pushDamageBonus, CharacterBaseCharacteristic& criticalDamageBonus, CharacterBaseCharacteristic& neutralDamageBonus, CharacterBaseCharacteristic& earthDamageBonus, CharacterBaseCharacteristic& waterDamageBonus, CharacterBaseCharacteristic& airDamageBonus, CharacterBaseCharacteristic& fireDamageBonus, CharacterBaseCharacteristic& dodgePALostProbability, CharacterBaseCharacteristic& dodgePMLostProbability, CharacterBaseCharacteristic& neutralElementResistPercent, CharacterBaseCharacteristic& earthElementResistPercent, CharacterBaseCharacteristic& waterElementResistPercent, CharacterBaseCharacteristic& airElementResistPercent, CharacterBaseCharacteristic& fireElementResistPercent, CharacterBaseCharacteristic& neutralElementReduction, CharacterBaseCharacteristic& earthElementReduction, CharacterBaseCharacteristic& waterElementReduction, CharacterBaseCharacteristic& airElementReduction, CharacterBaseCharacteristic& fireElementReduction, CharacterBaseCharacteristic& pushDamageReduction, CharacterBaseCharacteristic& criticalDamageReduction, CharacterBaseCharacteristic& pvpNeutralElementResistPercent, CharacterBaseCharacteristic& pvpEarthElementResistPercent, CharacterBaseCharacteristic& pvpWaterElementResistPercent, CharacterBaseCharacteristic& pvpAirElementResistPercent, CharacterBaseCharacteristic& pvpFireElementResistPercent, CharacterBaseCharacteristic& pvpNeutralElementReduction, CharacterBaseCharacteristic& pvpEarthElementReduction, CharacterBaseCharacteristic& pvpWaterElementReduction, CharacterBaseCharacteristic& pvpAirElementReduction, CharacterBaseCharacteristic& pvpFireElementReduction, std::vector<CharacterSpellModification> spellModifications, int probationTime);
	CharacterCharacteristicsInformations();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int __id = 8;

	/*VARS*/
	long long int experience;
	long long int experienceLevelFloor;
	long long int experienceNextLevelFloor;
	int experienceBonusLimit;
	int kamas;
	int statsPoints;
	int additionnalPoints;
	int spellsPoints;
	ActorExtendedAlignmentInformations alignmentInfos;
	int lifePoints;
	int maxLifePoints;
	int energyPoints;
	int maxEnergyPoints;
	int actionPointsCurrent;
	int movementPointsCurrent;
	CharacterBaseCharacteristic initiative;
	CharacterBaseCharacteristic prospecting;
	CharacterBaseCharacteristic actionPoints;
	CharacterBaseCharacteristic movementPoints;
	CharacterBaseCharacteristic strength;
	CharacterBaseCharacteristic vitality;
	CharacterBaseCharacteristic wisdom;
	CharacterBaseCharacteristic chance;
	CharacterBaseCharacteristic agility;
	CharacterBaseCharacteristic intelligence;
	CharacterBaseCharacteristic range;
	CharacterBaseCharacteristic summonableCreaturesBoost;
	CharacterBaseCharacteristic reflect;
	CharacterBaseCharacteristic criticalHit;
	int criticalHitWeapon;
	CharacterBaseCharacteristic criticalMiss;
	CharacterBaseCharacteristic healBonus;
	CharacterBaseCharacteristic allDamagesBonus;
	CharacterBaseCharacteristic weaponDamagesBonusPercent;
	CharacterBaseCharacteristic damagesBonusPercent;
	CharacterBaseCharacteristic trapBonus;
	CharacterBaseCharacteristic trapBonusPercent;
	CharacterBaseCharacteristic glyphBonusPercent;
	CharacterBaseCharacteristic runeBonusPercent;
	CharacterBaseCharacteristic permanentDamagePercent;
	CharacterBaseCharacteristic tackleBlock;
	CharacterBaseCharacteristic tackleEvade;
	CharacterBaseCharacteristic PAAttack;
	CharacterBaseCharacteristic PMAttack;
	CharacterBaseCharacteristic pushDamageBonus;
	CharacterBaseCharacteristic criticalDamageBonus;
	CharacterBaseCharacteristic neutralDamageBonus;
	CharacterBaseCharacteristic earthDamageBonus;
	CharacterBaseCharacteristic waterDamageBonus;
	CharacterBaseCharacteristic airDamageBonus;
	CharacterBaseCharacteristic fireDamageBonus;
	CharacterBaseCharacteristic dodgePALostProbability;
	CharacterBaseCharacteristic dodgePMLostProbability;
	CharacterBaseCharacteristic neutralElementResistPercent;
	CharacterBaseCharacteristic earthElementResistPercent;
	CharacterBaseCharacteristic waterElementResistPercent;
	CharacterBaseCharacteristic airElementResistPercent;
	CharacterBaseCharacteristic fireElementResistPercent;
	CharacterBaseCharacteristic neutralElementReduction;
	CharacterBaseCharacteristic earthElementReduction;
	CharacterBaseCharacteristic waterElementReduction;
	CharacterBaseCharacteristic airElementReduction;
	CharacterBaseCharacteristic fireElementReduction;
	CharacterBaseCharacteristic pushDamageReduction;
	CharacterBaseCharacteristic criticalDamageReduction;
	CharacterBaseCharacteristic pvpNeutralElementResistPercent;
	CharacterBaseCharacteristic pvpEarthElementResistPercent;
	CharacterBaseCharacteristic pvpWaterElementResistPercent;
	CharacterBaseCharacteristic pvpAirElementResistPercent;
	CharacterBaseCharacteristic pvpFireElementResistPercent;
	CharacterBaseCharacteristic pvpNeutralElementReduction;
	CharacterBaseCharacteristic pvpEarthElementReduction;
	CharacterBaseCharacteristic pvpWaterElementReduction;
	CharacterBaseCharacteristic pvpAirElementReduction;
	CharacterBaseCharacteristic pvpFireElementReduction;
	std::vector<CharacterSpellModification> spellModifications;
	int probationTime;
};


#endif