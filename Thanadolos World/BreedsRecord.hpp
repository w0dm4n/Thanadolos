#pragma once

#ifndef BREEDSRECORD_HPP
# define BREEDSRECORD_HPP

#include <iostream>
class BreedsRecord
{
public:
	static void declareRecord()
	{
		camp::Class::declare<BreedsRecord>("BreedsRecord")
			.constructor0().property("id", &BreedsRecord::getid, &BreedsRecord::setid)
			.property("shortNameId", &BreedsRecord::getshortNameId, &BreedsRecord::setshortNameId)
			.property("longNameId", &BreedsRecord::getlongNameId, &BreedsRecord::setlongNameId)
			.property("descriptionId", &BreedsRecord::getdescriptionId, &BreedsRecord::setdescriptionId)
			.property("maleLook", &BreedsRecord::getmaleLook, &BreedsRecord::setmaleLook)
			.property("femaleLook", &BreedsRecord::getfemaleLook, &BreedsRecord::setfemaleLook)
			.property("creatureBonesId", &BreedsRecord::getcreatureBonesId, &BreedsRecord::setcreatureBonesId)
			.property("maleArtwork", &BreedsRecord::getmaleArtwork, &BreedsRecord::setmaleArtwork)
			.property("femaleArtwork", &BreedsRecord::getfemaleArtwork, &BreedsRecord::setfemaleArtwork)
			.property("statsPointsForStrength", &BreedsRecord::getstatsPointsForStrength, &BreedsRecord::setstatsPointsForStrength)
			.property("statsPointsForIntelligence", &BreedsRecord::getstatsPointsForIntelligence, &BreedsRecord::setstatsPointsForIntelligence)
			.property("statsPointsForChance", &BreedsRecord::getstatsPointsForChance, &BreedsRecord::setstatsPointsForChance)
			.property("statsPointsForAgility", &BreedsRecord::getstatsPointsForAgility, &BreedsRecord::setstatsPointsForAgility)
			.property("statsPointsForVitality", &BreedsRecord::getstatsPointsForVitality, &BreedsRecord::setstatsPointsForVitality)
			.property("statsPointsForWisdom", &BreedsRecord::getstatsPointsForWisdom, &BreedsRecord::setstatsPointsForWisdom)
			.property("breedSpellsId", &BreedsRecord::getbreedSpellsId, &BreedsRecord::setbreedSpellsId)
			.property("breedRoles", &BreedsRecord::getbreedRoles, &BreedsRecord::setbreedRoles)
			.property("maleColors", &BreedsRecord::getmaleColors, &BreedsRecord::setmaleColors)
			.property("femaleColors", &BreedsRecord::getfemaleColors, &BreedsRecord::setfemaleColors)
			.property("complexity", &BreedsRecord::getcomplexity, &BreedsRecord::setcomplexity)
			.property("sortIndex", &BreedsRecord::getsortIndex, &BreedsRecord::setsortIndex);

	}
	BreedsRecord() { }

	int getid() { return this->id; }
	void setid(int var) { this->id = var; }

	int getshortNameId() { return this->shortNameId; }
	void setshortNameId(int var) { this->shortNameId = var; }

	int getlongNameId() { return this->longNameId; }
	void setlongNameId(int var) { this->longNameId = var; }

	int getdescriptionId() { return this->descriptionId; }
	void setdescriptionId(int var) { this->descriptionId = var; }

	std::string getmaleLook() { return this->maleLook; }
	void setmaleLook(std::string var) { this->maleLook = var; }

	std::string getfemaleLook() { return this->femaleLook; }
	void setfemaleLook(std::string var) { this->femaleLook = var; }

	int getcreatureBonesId() { return this->creatureBonesId; }
	void setcreatureBonesId(int var) { this->creatureBonesId = var; }

	int getmaleArtwork() { return this->maleArtwork; }
	void setmaleArtwork(int var) { this->maleArtwork = var; }

	int getfemaleArtwork() { return this->femaleArtwork; }
	void setfemaleArtwork(int var) { this->femaleArtwork = var; }

	std::string getstatsPointsForStrength() { return this->statsPointsForStrength; }
	void setstatsPointsForStrength(std::string var) { this->statsPointsForStrength = var; }

	std::string getstatsPointsForIntelligence() { return this->statsPointsForIntelligence; }
	void setstatsPointsForIntelligence(std::string var) { this->statsPointsForIntelligence = var; }

	std::string getstatsPointsForChance() { return this->statsPointsForChance; }
	void setstatsPointsForChance(std::string var) { this->statsPointsForChance = var; }

	std::string getstatsPointsForAgility() { return this->statsPointsForAgility; }
	void setstatsPointsForAgility(std::string var) { this->statsPointsForAgility = var; }

	std::string getstatsPointsForVitality() { return this->statsPointsForVitality; }
	void setstatsPointsForVitality(std::string var) { this->statsPointsForVitality = var; }

	std::string getstatsPointsForWisdom() { return this->statsPointsForWisdom; }
	void setstatsPointsForWisdom(std::string var) { this->statsPointsForWisdom = var; }

	std::string getbreedSpellsId() { return this->breedSpellsId; }
	void setbreedSpellsId(std::string var) { this->breedSpellsId = var; }

	std::string getbreedRoles() { return this->breedRoles; }
	void setbreedRoles(std::string var) { this->breedRoles = var; }

	std::string getmaleColors() { return this->maleColors; }
	void setmaleColors(std::string var) { this->maleColors = var; }

	std::string getfemaleColors() { return this->femaleColors; }
	void setfemaleColors(std::string var) { this->femaleColors = var; }

	int getcomplexity() { return this->complexity; }
	void setcomplexity(int var) { this->complexity = var; }

	int getsortIndex() { return this->sortIndex; }
	void setsortIndex(int var) { this->sortIndex = var; }



private:
	int id;
	int shortNameId;
	int longNameId;
	int descriptionId;
	std::string maleLook;
	std::string femaleLook;
	int creatureBonesId;
	int maleArtwork;
	int femaleArtwork;
	std::string statsPointsForStrength;
	std::string statsPointsForIntelligence;
	std::string statsPointsForChance;
	std::string statsPointsForAgility;
	std::string statsPointsForVitality;
	std::string statsPointsForWisdom;
	std::string breedSpellsId;
	std::string breedRoles;
	std::string maleColors;
	std::string femaleColors;
	int complexity;
	int sortIndex;
};

CAMP_TYPE(BreedsRecord)

#endif
