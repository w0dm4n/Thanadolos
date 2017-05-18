#include "IPCClient.hpp"
#include "IPC.hpp"
#include "ServerStatus.hpp"

IPCClient::IPCClient(IPC *ipc, SOCKET Socket, SOCKADDR_IN ClientAddr)
{
	this->Socket = Socket;
	this->Addr = ClientAddr;
	this->ipc = ipc;

	std::string msg = "New IPC client (";
	msg += inet_ntoa(this->getAddr().sin_addr);
	msg += ":";
	char buffer[20];
	itoa(ntohs(this->getAddr().sin_port), buffer, 10);
	msg += buffer;
	msg += ") linked to the auth server.";
	Logger::Infos(msg, 14);
}

IPCClient::~IPCClient()
{
	std::string msg = "IPC Client (";
	msg += inet_ntoa(this->getAddr().sin_addr);
	msg += ":";
	char buffer[20];
	itoa(ntohs(this->getAddr().sin_port), buffer, 10);
	msg += buffer;
	msg += ") unlinked from auth server.";
	Logger::Infos(msg, 14);
	if (this->serverId > 0)
		this->ipc->getAuth()->sendAllServerStatus(this->serverId, ServerStatusEnum::OFFLINE);
}

SOCKADDR_IN IPCClient::getAddr()
{
	return (this->Addr);
}

char *IPCClient::getRealAddr()
{
	return inet_ntoa(this->getAddr().sin_addr);
}

u_short IPCClient::getRealPort()
{
	return ntohs(this->getAddr().sin_port);
}

SOCKET IPCClient::getSocket()
{
	return (this->Socket);
}

DWORD WINAPI IPCClient::getThreadFunc()
{
	return (this->ipc->clientThread(*this));
}

void IPCClient::disconnect()
{
	closesocket(this->Socket);
}

int IPCClient::getServerId()
{
	return this->serverId;
}

void IPCClient::setServerId(int id)
{
	this->serverId = id;
}