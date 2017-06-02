#pragma once

#ifndef MAPSSUBAREASRECORD_HPP
# define MAPSSUBAREASRECORD_HPP

#pragma comment(lib, "campd.lib")
class MapsSubareasRecord
{
public:
	static void declareRecord()
	{
		camp::Class::declare<MapsSubareasRecord>("MapsSubareasRecord")
			.constructor0().property("id", &MapsSubareasRecord::getId, &MapsSubareasRecord::setId)
			.property("nameId", &MapsSubareasRecord::getnameId, &MapsSubareasRecord::setnameId)
			.property("areaId", &MapsSubareasRecord::getareaId, &MapsSubareasRecord::setareaId)
			.property("ambientSounds", &MapsSubareasRecord::getambientSounds, &MapsSubareasRecord::setambientSounds)
			.property("playlists", &MapsSubareasRecord::getplaylists, &MapsSubareasRecord::setplaylists)
			.property("mapIds", &MapsSubareasRecord::getmapIds, &MapsSubareasRecord::setmapIds)
			.property("bounds", &MapsSubareasRecord::getbounds, &MapsSubareasRecord::setbounds)
			.property("shape", &MapsSubareasRecord::getshape, &MapsSubareasRecord::setshape)
			.property("customWorldMap", &MapsSubareasRecord::getcustomWorldMap, &MapsSubareasRecord::setcustomWorldMap)
			.property("packId", &MapsSubareasRecord::getpackId, &MapsSubareasRecord::setpackId)
			.property("level", &MapsSubareasRecord::getlevel, &MapsSubareasRecord::setlevel)
			.property("isConquestVillage", &MapsSubareasRecord::getisConquestVillage, &MapsSubareasRecord::setisConquestVillage)
			.property("basicAccountAllowed", &MapsSubareasRecord::getbasicAccountAllowed, &MapsSubareasRecord::setbasicAccountAllowed)
			.property("displayOnWorldMap", &MapsSubareasRecord::getdisplayOnWorldMap, &MapsSubareasRecord::setdisplayOnWorldMap)
			.property("monsters", &MapsSubareasRecord::getmonsters, &MapsSubareasRecord::setmonsters)
			.property("entranceMapIds", &MapsSubareasRecord::getentranceMapIds, &MapsSubareasRecord::setentranceMapIds)
			.property("exitMapIds", &MapsSubareasRecord::getexitMapIds, &MapsSubareasRecord::setexitMapIds)
			.property("capturable", &MapsSubareasRecord::getcapturable, &MapsSubareasRecord::setcapturable)
			.property("achievements", &MapsSubareasRecord::getachievements, &MapsSubareasRecord::setachievements)
			.property("quests", &MapsSubareasRecord::getquests, &MapsSubareasRecord::setquests)
			.property("npcs", &MapsSubareasRecord::getnpcs, &MapsSubareasRecord::setnpcs)
			.property("exploreAchievementId", &MapsSubareasRecord::getexploreAchievementId, &MapsSubareasRecord::setexploreAchievementId)
			.property("harvestables", &MapsSubareasRecord::getharvestables, &MapsSubareasRecord::setharvestables);

	}
	MapsSubareasRecord() { }

	int getId() { return this->Id; }
	void setId(int var) { this->Id = var; }

	int getnameId() { return this->nameId; }
	void setnameId(int var) { this->nameId = var; }

	int getareaId() { return this->areaId; }
	void setareaId(int var) { this->areaId = var; }

	std::string getambientSounds() { return this->ambientSounds; }
	void setambientSounds(std::string var) { this->ambientSounds = var; }

	std::string getplaylists() { return this->playlists; }
	void setplaylists(std::string var) { this->playlists = var; }

	std::string getmapIds() { return this->mapIds; }
	void setmapIds(std::string var) { this->mapIds = var; }

	std::string getbounds() { return this->bounds; }
	void setbounds(std::string var) { this->bounds = var; }

	std::string getshape() { return this->shape; }
	void setshape(std::string var) { this->shape = var; }

	std::string getcustomWorldMap() { return this->customWorldMap; }
	void setcustomWorldMap(std::string var) { this->customWorldMap = var; }

	int getpackId() { return this->packId; }
	void setpackId(int var) { this->packId = var; }

	int getlevel() { return this->level; }
	void setlevel(int var) { this->level = var; }

	int getisConquestVillage() { return this->isConquestVillage; }
	void setisConquestVillage(int var) { this->isConquestVillage = var; }

	int getbasicAccountAllowed() { return this->basicAccountAllowed; }
	void setbasicAccountAllowed(int var) { this->basicAccountAllowed = var; }

	int getdisplayOnWorldMap() { return this->displayOnWorldMap; }
	void setdisplayOnWorldMap(int var) { this->displayOnWorldMap = var; }

	std::string getmonsters() { return this->monsters; }
	void setmonsters(std::string var) { this->monsters = var; }

	std::string getentranceMapIds() { return this->entranceMapIds; }
	void setentranceMapIds(std::string var) { this->entranceMapIds = var; }

	std::string getexitMapIds() { return this->exitMapIds; }
	void setexitMapIds(std::string var) { this->exitMapIds = var; }

	int getcapturable() { return this->capturable; }
	void setcapturable(int var) { this->capturable = var; }

	std::string getachievements() { return this->achievements; }
	void setachievements(std::string var) { this->achievements = var; }

	std::string getquests() { return this->quests; }
	void setquests(std::string var) { this->quests = var; }

	std::string getnpcs() { return this->npcs; }
	void setnpcs(std::string var) { this->npcs = var; }

	int getexploreAchievementId() { return this->exploreAchievementId; }
	void setexploreAchievementId(int var) { this->exploreAchievementId = var; }

	std::string getharvestables() { return this->harvestables; }
	void setharvestables(std::string var) { this->harvestables = var; }



private:
	int Id;
	int nameId;
	int areaId;
	std::string ambientSounds;
	std::string playlists;
	std::string mapIds;
	std::string bounds;
	std::string shape;
	std::string customWorldMap;
	int packId;
	int level;
	int isConquestVillage;
	int basicAccountAllowed;
	int displayOnWorldMap;
	std::string monsters;
	std::string entranceMapIds;
	std::string exitMapIds;
	int capturable;
	std::string achievements;
	std::string quests;
	std::string npcs;
	int exploreAchievementId;
	std::string harvestables;
};

CAMP_TYPE(MapsSubareasRecord)

#endif
