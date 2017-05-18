#pragma once
#pragma comment(lib, "ws2_32.lib")
#include <iostream>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include "Logger.hpp"
#include <list>
#include "Client.hpp"
#include "Utils.h"
#include "Processor.hpp"
#include "Database.hpp"
#include "Config.hpp"
#ifdef _DEBUG
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

class IPC;

class Auth
{
public:
	std::list<Client*> Clients;
	void addClient(Client &client);
	Auth();
	~Auth();
	void initializeData();
	void startListening();
	void printStarted();
	void newClient(Client &client);
	void removeClient(Client &client);
	Database *getDatabase();
	DWORD clientThread(Client &client);
	LPSTR getLastWSError();
	Client *getClientByAccountId(int id);
	DWORD WINAPI getIPCFunc();
	Config *getConfig();
	IPC *getIPC();
	void sendAll(IMessage &message);
	void sendAllServerStatus(int serverId, int status);
	struct AuthServerNotInitialized : public std::exception {
		virtual const char* what() const throw() {
			return "The auth server was not initialized properly";
		}
	};

	struct AuthServerInvalidSocket : public std::exception {
		AuthServerInvalidSocket(LPSTR error) { std::cerr << error; }
		virtual const char* what() const throw() {
			return "The auth server socket was invalid";
		}
	};

	struct AuthServerBindError : public std::exception {
		AuthServerBindError(LPSTR error) { std::cerr << error; }
		virtual const char* what() const throw() {
			return "The auth server can't bind socket";
		}
	};

	struct AuthServerCantSetReUseAddr : public std::exception {
		AuthServerCantSetReUseAddr(LPSTR error) { std::cerr << error; }
		virtual const char* what() const throw() {
			return "The auth server can't set SO_REUSEADDR on the socket";
		}
	};

	struct AuthServerListenError : public std::exception {
		AuthServerListenError(LPSTR error) { std::cerr << error; }
		virtual const char* what() const throw() {
			return "The auth server can't listen on socket";
		}
	};

	static DWORD WINAPI initializeThread(void *p)
	{
		Client *Obj = reinterpret_cast<Client*>(p);
		return Obj->getThreadFunc();
	}

private:
	WSADATA	        wsData;
	SOCKADDR_IN		Addr;
	SOCKET Listener;
	std::string host;
	u_short port;
	u_short ipc_port;
	bool initialized;
	Database *db;
	std::mutex m;
	IPC *ipc;
	Config *config;
};

#define DATA_BUFSIZE 4096
