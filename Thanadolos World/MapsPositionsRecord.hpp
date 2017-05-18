#pragma once

#ifndef MAPS_POSITIONS_RECORD_HPP
# define MAPS_POSITIONS_RECORD_HPP

#pragma comment(lib, "campd.lib")
class MapsPositionsRecord
{
public:
	static void declareRecord()
	{
		camp::Class::declare<MapsPositionsRecord>("MapsPositionsRecord")
			.constructor0()
			.property("id", &MapsPositionsRecord::getId, &MapsPositionsRecord::setId)
			.property("posX", &MapsPositionsRecord::getposX, &MapsPositionsRecord::setposX)
			.property("posY", &MapsPositionsRecord::getposY, &MapsPositionsRecord::setposY)
			.property("outdoor", &MapsPositionsRecord::getoutdoor, &MapsPositionsRecord::setoutdoor)
			.property("capabilities", &MapsPositionsRecord::getcapabilities, &MapsPositionsRecord::setcapabilities)
			.property("nameId", &MapsPositionsRecord::getnameId, &MapsPositionsRecord::setnameId)
			.property("showNameOnFingerpost", &MapsPositionsRecord::getshowNameOnFingerpost, &MapsPositionsRecord::setshowNameOnFingerpost)
			.property("sounds", &MapsPositionsRecord::getsounds, &MapsPositionsRecord::setsounds)
			.property("playlists", &MapsPositionsRecord::getplaylists, &MapsPositionsRecord::setplaylists)
			.property("subAreaId", &MapsPositionsRecord::getsubAreaId, &MapsPositionsRecord::setsubAreaId)
			.property("worldMap", &MapsPositionsRecord::getworldMap, &MapsPositionsRecord::setworldMap)
			.property("hasPriorityOnWorldmap", &MapsPositionsRecord::gethasPriorityOnWorldmap, &MapsPositionsRecord::sethasPriorityOnWorldmap)
			.property("isUnderWater", &MapsPositionsRecord::getisUnderWater, &MapsPositionsRecord::setisUnderWater);
	}
	MapsPositionsRecord() { }

	int getId() const { return this->Id; }
	void setId(int id) { this->Id = id; }

	int getposX() const { return this->posX; }
	void setposX(int id) { this->posX = id; }

	int getposY() const { return this->posY; }
	void setposY(int id) { this->posY = id; }

	int getoutdoor() const { return this->outdoor; }
	void setoutdoor(int id) { this->outdoor = id; }

	int getcapabilities() const { return this->capabilities; }
	void setcapabilities(int id) { this->capabilities = id; }

	int getnameId() const { return this->nameId; }
	void setnameId(int id) { this->nameId = id; }

	int getshowNameOnFingerpost() const { return this->showNameOnFingerpost; }
	void setshowNameOnFingerpost(int id) { this->showNameOnFingerpost = id; }

	std::string getsounds() const { return this->sounds; }
	void setsounds(std::string id) { this->sounds = id; }

	std::string getplaylists() const { return this->playlists; }
	void setplaylists(std::string id) { this->playlists = id; }

	int getsubAreaId() const { return this->subAreaId; }
	void setsubAreaId(int id) { this->subAreaId = id; }

	int getworldMap() const { return this->worldMap; }
	void setworldMap(int id) { this->worldMap = id; }

	int gethasPriorityOnWorldmap() const { return this->hasPriorityOnWorldmap; }
	void sethasPriorityOnWorldmap(int id) { this->hasPriorityOnWorldmap = id; }

	int getisUnderWater() const { return this->isUnderWater; }
	void setisUnderWater(int id) { this->isUnderWater = id; }

private:
	int Id;
	int posX;
	int posY;
	int outdoor;
	int capabilities;
	int nameId;
	int showNameOnFingerpost;
	std::string sounds;
	std::string playlists;
	int subAreaId;
	int worldMap;
	int hasPriorityOnWorldmap;
	int isUnderWater;

};

CAMP_TYPE(MapsPositionsRecord)

#endif
