#pragma once
#ifndef IPC_HPP
# define IPC_HPP
#include <WinSock2.h>
#include <exception>
#include <iostream>
#include "Logger.hpp"
#include "Auth.hpp"
#include "IPCClient.hpp"

# define IPC_NEW_CHARACTER 667
# define IPC_DELETED_CHARACTER 668

class IPC
{
public:
	std::list<IPCClient*> Clients;
	IPC(u_short port, Auth *auth);
	DWORD         IPCThread(Auth &auth);
	Auth *getAuth();
	static DWORD WINAPI initializeIPC(void *p)
	{
		Auth *Obj = reinterpret_cast<Auth*>(p);
		return Obj->getIPCFunc();
	}
	static DWORD WINAPI initializeIPCClient(void *p)
	{
		IPCClient *Obj = reinterpret_cast<IPCClient*>(p);
		return Obj->getThreadFunc();
	}
	IPCClient *getIPCByServerId(int serverId);
	void newIPCClient(IPCClient &ipcClient);
	void printStarted();
	void addClient(IPCClient &client);
	DWORD clientThread(IPCClient &ipcClient);
	void removeClient(IPCClient &client);
	void Process(Packet &packet, IPCClient &ipcClient);

	struct IPCServerNotInitialized : public std::exception {
		virtual const char* what() const throw() {
			return "The IPC server was not initialized properly";
		}
	};

	struct IPCServerInvalidSocket : public std::exception {
		IPCServerInvalidSocket(LPSTR error) { std::cerr << error; }
		virtual const char* what() const throw() {
			return "The IPC server socket was invalid";
		}
	};

	struct IPCServerBindError : public std::exception {
		IPCServerBindError(LPSTR error) { std::cerr << error; }
		virtual const char* what() const throw() {
			return "The IPC server can't bind socket";
		}
	};

	struct IPCServerCantSetReUseAddr : public std::exception {
		IPCServerCantSetReUseAddr(LPSTR error) { std::cerr << error; }
		virtual const char* what() const throw() {
			return "The IPC server can't set SO_REUSEADDR on the socket";
		}
	};

	struct IPCServerListenError : public std::exception {
		IPCServerListenError(LPSTR error) { std::cerr << error; }
		virtual const char* what() const throw() {
			return "The IPC server can't listen on socket";
		}
	};
private:
	WSADATA	        wsData;
	SOCKADDR_IN		Addr;
	SOCKET Listener;
	Auth *auth;
	u_short port;
	std::mutex m;
};

#endif