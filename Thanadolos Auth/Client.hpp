#pragma once
#include <WinSock2.h>
#include "Logger.hpp"
#include <iostream>
#include <list>
#ifdef _DEBUG
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif
#include "Database.hpp"

class Auth;

class Client
{
public:
	Client(Auth *auth, SOCKET Socket, SOCKADDR_IN ClientAddr);
	~Client();
	void disconnect();
	SOCKET getSocket();
	SOCKADDR_IN getAddr();
	char *getRealAddr();
	u_short getRealPort();
	Auth *getAuth();
	DWORD WINAPI getThreadFunc();
	void sendRawPatch();
	void sendMessage(IMessage &message);
	bool operator==(const Client & other) const;
	void setAccount(camp::UserObject);
	camp::UserObject getAccount() { return this->Account; }
	void setWorldsCharacters(std::list<camp::UserObject> *lists) { this->WorldsCharacters = *lists; }
	std::list<camp::UserObject> getWorldsCharacters() { return (this->WorldsCharacters); }
	camp::UserObject getCharactersOnServer(int serverId);
	void	setTicket(std::string ticket);
	std::string getTicket();
	ByteArray getAES();
	void setAES(ByteArray);
	void sendTicket(camp::UserObject);
private:
	std::string ticket;
	SOCKET Socket;
	SOCKADDR_IN Addr;
	Auth *auth;
	camp::UserObject Account;
	std::list<camp::UserObject> WorldsCharacters;
	ByteArray aes;
};

