#pragma once
#include <iostream>
#include "World.hpp"
#include "ServerStatusUpdateMessage.hpp"
#include "IpcTicketAccountMessage.hpp"
#define IPC_TICKET_ACCOUNT_ID 666
#pragma comment(lib, "ws2_32.lib")
class IPC
{
public:
	IPC(u_short port, std::string host, World *world, int loopTime);
	DWORD IPCThread(World &world);
	void Synchronize(World &world);
	void sendToAuth(IMessage &message);
	void setSynchronized();
	void Process(Packet &packet);
	bool isSynchronized();
	std::vector<IpcTicketAccountMessage> getTicketsAccounts();
	IpcTicketAccountMessage getTicketsAccountsByTicket(std::string ticket);
	static DWORD WINAPI initializeIPC(void *p)
	{
		World *Obj = reinterpret_cast<World*>(p);
		return Obj->getIPCFunc();
	}
	struct WorldIPCServerInvalidSocket : public std::exception {
		WorldIPCServerInvalidSocket(LPSTR error) { std::cerr << error; }
		virtual const char* what() const throw() {
			return "The IPC socket was invalid";
		}
	};
	struct WorldIPCConnectInvalidSocket : public std::exception {
		WorldIPCConnectInvalidSocket(LPSTR error) { std::cerr << error; }
		virtual const char* what() const throw() {
			return "The IPC connection was invalid";
		}
	};
private:
	WSADATA	        wsData;
	SOCKADDR_IN		Addr;
	SOCKET Socket;
	World *world;
	u_short port;
	std::string host;
	int timer;
	bool synchronized;
	std::vector<IpcTicketAccountMessage> ticketsAccounts;
	std::mutex m;
};