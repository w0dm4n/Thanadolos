#pragma once
#include <WinSock2.h>
#include "Logger.hpp"
#include <iostream>

class IPC;

class IPCClient
{
public:
	IPCClient(IPC *ipc, SOCKET Socket, SOCKADDR_IN ClientAddr);
	~IPCClient();
	SOCKET getSocket();
	SOCKADDR_IN getAddr();
	char *getRealAddr();
	u_short getRealPort();
	DWORD WINAPI getThreadFunc();
	void disconnect();
	int getServerId();
	void setServerId(int id);
private:
	int serverId;
	SOCKET Socket;
	SOCKADDR_IN Addr;
	IPC *ipc;
};