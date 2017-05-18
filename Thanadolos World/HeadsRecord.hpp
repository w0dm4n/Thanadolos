#pragma once

#ifndef HEADS_RECORD_HPP
# define HEADS_RECORD_HPP

#pragma comment(lib, "campd.lib")
class HeadsRecord
{
public:
	static void declareRecord()
	{
		camp::Class::declare<HeadsRecord>("HeadsRecord")
			.constructor0()
			.property("id", &HeadsRecord::getId, &HeadsRecord::setId)
			.property("skins", &HeadsRecord::getSkins, &HeadsRecord::setSkins)
			.property("breed", &HeadsRecord::getBreed, &HeadsRecord::setBreed)
			.property("gender", &HeadsRecord::getGender, &HeadsRecord::setGender);
	}
	HeadsRecord() { }

	int getId() const { return this->Id; }
	void setId(int id) { this->Id = id; }

	int getSkins() const { return this->Skins; }
	void setSkins(int skins) { this->Skins = skins; }

	int getBreed() const { return this->Breed; }
	void setBreed(int breed) { this->Breed = breed; }

	bool getGender() const { return this->Gender; }
	void setGender(bool gender) { this->Gender = gender; }

private:
	int Id;
	int Skins;
	int Breed;
	bool Gender;
};

CAMP_TYPE(HeadsRecord)

#endif
