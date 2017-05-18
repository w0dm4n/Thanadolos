#pragma once

#ifndef MAPS_RECORD_HPP
# define MAPS_RECORD_HPP

#pragma comment(lib, "campd.lib")
class MapsRecord
{
public:
	static void declareRecord()
	{
		int relativeId;
		int mapType;
		int subareaId;
		int topNeighbourId;
		int bottomNeighbourId;
		int leftNeighbourId;
		int rightNeighbourId;
		int shadowBonusOnEntities;
		int useLowPassFilter;
		int useReverb;
		int presetId;
		int groundCRC;
		std::string cells;

		camp::Class::declare<MapsRecord>("MapsRecord")
			.constructor0()
			.property("id", &MapsRecord::getId, &MapsRecord::setId)
			.property("mapVersion", &MapsRecord::getmapVersion, &MapsRecord::setmapVersion)
			.property("relativeId", &MapsRecord::getrelativeId, &MapsRecord::setrelativeId)
			.property("mapType", &MapsRecord::getmapType, &MapsRecord::setmapType)
			.property("subareaId", &MapsRecord::getsubareaId, &MapsRecord::setsubareaId)
			.property("topNeighbourId", &MapsRecord::gettopNeighbourId, &MapsRecord::settopNeighbourId)
			.property("bottomNeighbourId", &MapsRecord::getbottomNeighbourId, &MapsRecord::setbottomNeighbourId)
			.property("leftNeighbourId", &MapsRecord::getleftNeighbourId, &MapsRecord::setleftNeighbourId)
			.property("rightNeighbourId", &MapsRecord::getrightNeighbourId, &MapsRecord::setrightNeighbourId)
			.property("shadowBonusOnEntities", &MapsRecord::getshadowBonusOnEntities, &MapsRecord::setshadowBonusOnEntities)
			.property("useLowPassFilter", &MapsRecord::getuseLowPassFilter, &MapsRecord::setuseLowPassFilter)
			.property("useReverb", &MapsRecord::getuseReverb, &MapsRecord::setuseReverb)
			.property("presetId", &MapsRecord::getpresetId, &MapsRecord::setpresetId)
			.property("groundCRC", &MapsRecord::getgroundCRC, &MapsRecord::setgroundCRC)
			.property("cells", &MapsRecord::getCells, &MapsRecord::setCells);
	}
	MapsRecord() { }

	int getId() const { return this->Id; }
	void setId(int id) { this->Id = id; }

	int getmapVersion() const { return this->mapVersion; }
	void setmapVersion(int id) { this->mapVersion = id; }

	int getrelativeId() const { return this->relativeId; }
	void setrelativeId(int id) { this->relativeId = id; }

	int getmapType() const { return this->mapType; }
	void setmapType(int id) { this->mapType = id; }

	int getsubareaId() const { return this->subareaId; }
	void setsubareaId(int id) { this->subareaId = id; }

	int gettopNeighbourId() const { return this->topNeighbourId; }
	void settopNeighbourId(int id) { this->topNeighbourId = id; }

	int getbottomNeighbourId() const { return this->bottomNeighbourId; }
	void setbottomNeighbourId(int id) { this->bottomNeighbourId = id; }

	int getleftNeighbourId() const { return this->leftNeighbourId; }
	void setleftNeighbourId(int id) { this->leftNeighbourId = id; }

	int getrightNeighbourId() const { return this->rightNeighbourId; }
	void setrightNeighbourId(int id) { this->rightNeighbourId = id; }

	int getshadowBonusOnEntities() const { return this->shadowBonusOnEntities; }
	void setshadowBonusOnEntities(int id) { this->shadowBonusOnEntities = id; }

	int getuseLowPassFilter() const { return this->useLowPassFilter; }
	void setuseLowPassFilter(int id) { this->useLowPassFilter = id; }

	int getuseReverb() const { return this->useReverb; }
	void setuseReverb(int id) { this->useReverb = id; }

	int getpresetId() const { return this->presetId; }
	void setpresetId(int id) { this->presetId = id; }

	int getgroundCRC() const { return this->groundCRC; }
	void setgroundCRC(int id) { this->groundCRC = id; }

	std::string getCells() const { return this->cells; }
	void setCells(std::string cells) { this->cells = cells; }

private:
	int Id;
	int mapVersion;
	int relativeId;
	int mapType;
	int subareaId;
	int topNeighbourId;
	int bottomNeighbourId;
	int leftNeighbourId;
	int rightNeighbourId;
	int shadowBonusOnEntities;
	int useLowPassFilter;
	int useReverb;
	int presetId;
	int groundCRC;
	std::string cells;
};

CAMP_TYPE(MapsRecord)

#endif
