#pragma once
#include "Logger.hpp"
#ifdef _DEBUG
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif
#include "Database.hpp"
#include "IpcNewCharacterMessage.hpp"
#include "IpcDeletedCharacterMessage.hpp"

class World;
class Character;

class WorldClient
{
public:
	WorldClient(World *world, SOCKET Socket, SOCKADDR_IN WorldClientAddr);
	~WorldClient();
	void disconnect();
	SOCKADDR_IN getAddr();
	char *getRealAddr();
	u_short getRealPort();
	World *getWorld();
	SOCKET getSocket();
	DWORD WINAPI getThreadFunc();
	void sendMessage(IMessage &message);
	bool operator==(const WorldClient & other) const;
	void setAccount(camp::UserObject);
	camp::UserObject getAccount();
	std::vector<camp::UserObject> getCharacters();
	void addCharacter(camp::UserObject&);
	void updateCharactersRecord(std::vector<camp::UserObject>);
	void sendNewCharacterToAuth();
	void sendDeletedCharacterToAuth();
	void buildCharacter(int characterId);
	Character *character;
private:
	SOCKET Socket;
	SOCKADDR_IN Addr;
	World *world;
	camp::UserObject Account;
	std::vector <camp::UserObject> Characters;
};

