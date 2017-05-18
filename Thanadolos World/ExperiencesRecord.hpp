#pragma once

#ifndef EXPERIENCESRECORD_HPP
# define EXPERIENCESRECORD_HPP

#include <iostream>
class ExperiencesRecord
{
public:
	static void declareRecord()
	{
		camp::Class::declare<ExperiencesRecord>("ExperiencesRecord")
			.constructor0().property("Level", &ExperiencesRecord::getLevel, &ExperiencesRecord::setLevel)
			.property("Xp", &ExperiencesRecord::getXp, &ExperiencesRecord::setXp)
			.property("Honor", &ExperiencesRecord::getHonor, &ExperiencesRecord::setHonor)
			.property("Guild", &ExperiencesRecord::getGuild, &ExperiencesRecord::setGuild);

	}
	ExperiencesRecord() { }

	int getLevel() { return this->Level; }
	void setLevel(int var) { this->Level = var; }

	std::string getXp() { return this->Xp; }
	void setXp(std::string var) { this->Xp = var; }

	int getHonor() { return this->Honor; }
	void setHonor(int var) { this->Honor = var; }

	int getGuild() { return this->Guild; }
	void setGuild(int var) { this->Guild = var; }


private:
	int Level;
	std::string Xp;
	int Honor;
	int Guild;
};

CAMP_TYPE(ExperiencesRecord)

#endif
