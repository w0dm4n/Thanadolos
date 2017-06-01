#include "Globals.h"
#include "IPC.hpp"

IPC::IPC(u_short port, std::string host, World *world, int loopTime) : port(port), host(host), world(world)
{
	try
	{
		Sleep(1000);
		this->synchronized = false;
		this->timer = (loopTime * 1000);
		this->Addr.sin_family = AF_INET;
		this->Addr.sin_port = htons(this->port);
		this->Addr.sin_addr.s_addr = inet_addr(this->host.c_str());
		HANDLE       			hProcessThread;

		hProcessThread = CreateThread(NULL, 0, this->initializeIPC, world, 0, NULL);
	}
	catch (std::exception &e)
	{
		Logger::Error("Can't start thread to listen IPC communication", 12, e.what());
	}
}

void IPC::sendToAuth(IMessage &message)
{
	try
	{
		ByteArray buffer;
		Packet packet;

		packet.serialize(message, buffer);
		send(this->Socket, buffer.data(), buffer.size(), 0);
		Logger::NetworkIPC(&message, packet, 14);
	}
	catch (std::exception &e)
	{
		Logger::Error("Can't serialize or send a packet to auth server", 12, e.what());
	}
}

void IPC::setSynchronized()
{
	std::string msg = "IPC synchronized with auth server on port " + std::to_string(this->port);
	Logger::Infos(msg, 13);
	this->synchronized = true;
}

void IPC::Process(Packet &packet)
{
	BinaryReader reader(packet.data());
	int id = packet.id();
	if (id == IPC_TICKET_ACCOUNT_ID) // Ticket with account filled in
	{
		IpcTicketAccountMessage message;
		message.deserialize(reader);
		this->ticketsAccounts.push_back(message);
	}
}

void IPC::Synchronize(World &world)
{
	if (WSAStartup(MAKEWORD(2, 2), &this->wsData) != 0)
	{
		Logger::Error("Can't initialize the library for socket.");
		return;
	}
	SOCKET sock = this->Socket;

	if ((sock = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, WSA_FLAG_OVERLAPPED)) == INVALID_SOCKET)
	{
		Logger::Error("The IPC socket was invalid", 12, world.getLastWSError());
		return;
	}
	if ((connect(sock, (SOCKADDR *)&this->Addr, sizeof(this->Addr))) == INVALID_SOCKET)
	{
		Logger::Error("Can't link world to auth server... (will try again in " + std::to_string((this->timer / 1000)) + " seconds)");
		return;
	}
	
	this->Socket = sock;
	this->setSynchronized();
	ServerStatusUpdateMessage toSend(world.getOnlineGameServerInformations());
	this->sendToAuth(toSend);

	int res = 0;
	char tmpBuffer[DATA_BUFSIZE];
	while (true)
	{
		res = recv(sock, tmpBuffer, DATA_BUFSIZE, 0);
		if (res > 0)
		{
			try
			{
				Packet packet;
				std::vector<char> buffer(tmpBuffer, tmpBuffer + res);
				while (packet.deserialize(buffer))
					this->Process(packet);
				ft_bzero(tmpBuffer, DATA_BUFSIZE);
				res = 0;
			}
			catch (std::exception &e)
			{
				Logger::Error("An error occured while handling a packet received from auth", 12, e.what());
			}
		}
		else if (res <= 0)
		{
			Logger::Error("IPC auth server desynchronized !");
			this->synchronized = false;
			break;
		}
	}
}

DWORD IPC::IPCThread(World &world)
{
	while (true)
	{
		if (this->synchronized == false)
			this->Synchronize(world);
		Sleep(this->timer);
	}
	return 0;
}

std::vector<IpcTicketAccountMessage> IPC::getTicketsAccounts()
{
	return this->ticketsAccounts;
}

IpcTicketAccountMessage IPC::getTicketsAccountsByTicket(std::string ticket)
{
	std::lock_guard<std::mutex> locker(this->m);
	std::vector<IpcTicketAccountMessage> ticketsAccounts = this->getTicketsAccounts();
	int i = 0;
	while (i < ticketsAccounts.size())
	{
		if (ticketsAccounts[i].ticket == ticket)
			return (ticketsAccounts[i]);
		i++;
	}
	IpcTicketAccountMessage empty;
	return (empty);
}

bool IPC::isSynchronized()
{
	return this->synchronized;
}