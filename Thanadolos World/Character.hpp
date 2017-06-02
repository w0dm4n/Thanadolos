#pragma once
#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "Database.hpp"
#include "Logger.hpp"

#define _WINSOCK2API_
#include "Database.hpp"
#include "CharacterBaseInformations.hpp"
#include "EntityLook.hpp"
#include "SubEntity.hpp"
#include "GameRolePlayCharacterInformations.hpp"
#include "CharacterCharacteristicsInformations.hpp"
#include "ActorExtendedAlignmentInformations.hpp"
#include "CharacterSpellModification.hpp"
#include "LifePointsRegenBeginMessage.hpp"
#include "LifePointsRegenEndMessage.hpp"
#include "TextInformationMessage.hpp"

#define _WS2IPDEF_
#define _WS2TCPIP_H_
#include "World.hpp"
#include "Map.hpp"

#include "CharactersManager.hpp"
#include "Stats.hpp"
#include "CharactersManager.hpp"
#include "CharacterStatsListMessage.hpp"
#include "GameHandler.hpp"
#include "Spell.hpp"
#include "SpellListMessage.hpp"
#include "Shortcut.hpp"
#include "ShortcutBarContentMessage.hpp"
#include "ShortcutBarRemovedMessage.hpp"

#include "CharacterExperienceGainMessage.hpp"
#include "CharacterLevelUpMessage.hpp"
#include "UpdateLifePointsMessage.hpp"

class Character
{
public:
	Character(camp::UserObject characterRecord, camp::UserObject accountRecord, WorldClient &client, bool isIngame);
	~Character();
	CharacterBaseInformations								getCharacterBaseInformations();
	GameRolePlayCharacterInformations						*getGameRolePlayCharacterInformations();
	ActorRestrictionsInformations							getRestrictions();
	HumanInformations										getHumanInformations();
	std::vector<HumanOption>								getHumanOptions();
	ActorAlignmentInformations								getActorAlignmentInformations();
	CharacterCharacteristicsInformations					getCharacterCharacteristicsInformations();
	std::vector<CharacterSpellModification>					getCharacterSpellModification();
	ActorExtendedAlignmentInformations						getActorExtendedAlignmentInformations();
	EntityLook	getEntityLook();
	void		loadDatas(bool isIngame);
	void		loadSpells();
	void		loadShortcuts();

	std::vector<uint>		getSkins();
	std::vector<int>		getColors();
	std::vector<SubEntity>	getSubEntities();
	std::vector<int>		getScales();
	void					refreshEntityLook();
	int						getBonesId();
	void					getSkinsBase();
	camp::UserObject		getAccountRecord();
	std::string				getCharacterName();
	int						getCharacterLevel();
	camp::UserObject		getCharacterRecord();
	void					updateLevel(int value);
	bool					isFirstContext();
	void					setFirstContext(bool context);
	void					onConnected();
	void					onDisconnect();
	Map						*getMap();
	void					setMap(Map *map);
	void					updatePosition(int mapId, int cellId);
	void					updateDirection(int direction);
	int						getDirection();
	WorldClient				&getClient();
	Stats					&getStats();
	void					sendStats();
	void					sendSpells();
	bool					hasSpellId(int spellId);
	Spell					*getSpellById(int spellId);
	bool					removeShortcut(int slotId, int typeId);
	bool					addShortcut(ShortcutSpell *spell);
	bool					addShortcut(ShortcutObjectItem *item);
	camp::UserObject		&getShortcut(int slotId, int typeId);
	std::vector<Shortcut*>	getSpellsShortcut();
	std::vector<Shortcut*>	getItemsShortcut();
	void					sendShortcuts();
	void					generateShortcuts();
	void					swapShortcuts(int type, int first, int second);
	void					removeShortcut(int id);
	int						getAvailableShortcutSlot();
	void					addExperience(long long int experience);
	void					checkLevelUp();

	void					startRegenLife(bool sendMessage = true);
	void					stopRegenLife(bool sendMessage);

	void					replyLangsMessage(int typeId, int id, std::vector<std::string>);
	void					replyText(std::string message);
	void					replyError(std::string message);

private:
	camp::UserObject characterRecord;
	camp::UserObject accountRecord;

	std::vector<Spell>				spells;
	std::vector<camp::UserObject>	shortcuts;
	WorldClient						&client;
	std::vector<uint>				skins;
	Map								*map;
	Stats							stats;

	uint defaultLook;
	uint headLook;
	uint scaleLook;
	bool firstContext;
	int direction;
	long int regenTimestamp;
};

#endif