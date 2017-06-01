#pragma once

#ifndef SPELLSRECORD_HPP
# define SPELLSRECORD_HPP

#include <iostream>
class SpellsRecord
{
public:
	static void declareRecord()
	{
		camp::Class::declare<SpellsRecord>("SpellsRecord")
			.constructor0().property("id", &SpellsRecord::getid, &SpellsRecord::setid)
			.property("nameId", &SpellsRecord::getnameId, &SpellsRecord::setnameId)
			.property("descriptionId", &SpellsRecord::getdescriptionId, &SpellsRecord::setdescriptionId)
			.property("typeId", &SpellsRecord::gettypeId, &SpellsRecord::settypeId)
			.property("orderBy", &SpellsRecord::getorderBy, &SpellsRecord::setorderBy)
			.property("scriptParams", &SpellsRecord::getscriptParams, &SpellsRecord::setscriptParams)
			.property("scriptParamsCritical", &SpellsRecord::getscriptParamsCritical, &SpellsRecord::setscriptParamsCritical)
			.property("scriptId", &SpellsRecord::getscriptId, &SpellsRecord::setscriptId)
			.property("scriptIdCritical", &SpellsRecord::getscriptIdCritical, &SpellsRecord::setscriptIdCritical)
			.property("iconId", &SpellsRecord::geticonId, &SpellsRecord::seticonId)
			.property("spellLevels", &SpellsRecord::getspellLevels, &SpellsRecord::setspellLevels)
			.property("verbose_cast", &SpellsRecord::getverbose_cast, &SpellsRecord::setverbose_cast);
	}
	SpellsRecord() { }

	int getid() { return this->id; }
	void setid(int var) { this->id = var; }

	int getnameId() { return this->nameId; }
	void setnameId(int var) { this->nameId = var; }

	int getdescriptionId() { return this->descriptionId; }
	void setdescriptionId(int var) { this->descriptionId = var; }

	int gettypeId() { return this->typeId; }
	void settypeId(int var) { this->typeId = var; }

	int getorderBy() { return this->orderBy; }
	void setorderBy(int var) { this->orderBy = var; }

	std::string getscriptParams() { return this->scriptParams; }
	void setscriptParams(std::string var) { this->scriptParams = var; }

	std::string getscriptParamsCritical() { return this->scriptParamsCritical; }
	void setscriptParamsCritical(std::string var) { this->scriptParamsCritical = var; }

	int getscriptId() { return this->scriptId; }
	void setscriptId(int var) { this->scriptId = var; }

	int getscriptIdCritical() { return this->scriptIdCritical; }
	void setscriptIdCritical(int var) { this->scriptIdCritical = var; }

	int geticonId() { return this->iconId; }
	void seticonId(int var) { this->iconId = var; }

	std::string getspellLevels() { return this->spellLevels; }
	void setspellLevels(std::string var) { this->spellLevels = var; }

	int getverbose_cast() { return this->verbose_cast; }
	void setverbose_cast(int var) { this->verbose_cast = var; }


private:
	int id;
	int nameId;
	int descriptionId;
	int typeId;
	int orderBy;
	std::string scriptParams;
	std::string scriptParamsCritical;
	int scriptId;
	int scriptIdCritical;
	int iconId;
	std::string spellLevels;
	int verbose_cast;

};

CAMP_TYPE(SpellsRecord)

#endif
