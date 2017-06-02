#include "Auth.hpp"
#include "Client.hpp"
#include <mutex>
#include <chrono>
#include <thread>
#include <string.h>
#include "Packet.hpp"
#include <exception>
#include "Processor.hpp"
#include "ProtocolRequired.hpp"
#include "HelloConnectMessage.hpp"
#include "IPC.hpp"
#include "ServerStatusUpdateMessage.hpp"

Auth::Auth()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "  ::::::::::: :::    :::     :::     ::::    :::     :::     :::::::::   ::::::::  :::        ::::::::   :::::::: " << std::endl;
	std::cout << "     :+:     :+:    :+:   :+: :+:   :+:+:   :+:   :+: :+:   :+:    :+: :+:    :+: :+:       :+:    :+: :+:    :+: " << std::endl;
	std::cout << "    +:+     +:+    +:+  +:+   +:+  :+:+:+  +:+  +:+   +:+  +:+    +:+ +:+    +:+ +:+       +:+    +:+ +:+         " << std::endl;
	std::cout << "   +#+     +#++:++#++ +#++:++#++: +#+ +:+ +#+ +#++:++#++: +#+    +:+ +#+    +:+ +#+       +#+    +:+ +#++:++#++   " << std::endl;
	std::cout << "  +#+     +#+    +#+ +#+     +#+ +#+  +#+#+# +#+     +#+ +#+    +#+ +#+    +#+ +#+       +#+    +#+        +#+    " << std::endl;
	std::cout << " #+#     #+#    #+# #+#     #+# #+#   #+#+# #+#     #+# #+#    #+# #+#    #+# #+#       #+#    #+# #+#    #+#     " << std::endl;
	std::cout << "###     ###    ### ###     ### ###    #### ###     ### #########   ########  ########## ########   ########       " << std::endl \
	<< std::endl;

	this->initialized = false;
	this->config = new Config("auth_config.th");
}

void Auth::initializeData()
{
	if (WSAStartup(MAKEWORD(2, 2), &this->wsData) != 0)
	{
		std::cerr << "Can't initialize the library for socket." << std::endl;
		return;
	}

	this->host = this->config->getData("AUTH_HOST");
	this->port = atoi(this->config->getData("AUTH_PORT").c_str());
	this->ipc_port = atoi(this->config->getData("IPC_PORT").c_str());

	this->Addr.sin_family = AF_INET;
	this->Addr.sin_port = htons(this->port);
	this->Addr.sin_addr.s_addr = inet_addr(this->host.c_str());

	Database *db = new Database(this->config->getData("DATABASE_HOST"), this->config->getData("DATABASE_NAME"),
		this->config->getData("DATABASE_USER"), this->config->getData("DATABASE_PASSWORD"));
	if (db->initializeDatabase())
	{
		this->db = db;
		this->initialized = true;		
	}
}

LPSTR Auth::getLastWSError()
{
	int errCode = WSAGetLastError();
	LPSTR errString = NULL;

	int size = FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER |
		FORMAT_MESSAGE_FROM_SYSTEM, 0, errCode, 0, (LPSTR)&errString, 0, 0);         
	return errString;
}

void Auth::printStarted()
{
	std::string msg = "Auth server started on port ";
	char buffer[20];
	itoa(this->port, buffer, 10);
	msg += buffer;
	msg += ", waiting for connections..";
	Logger::Infos(msg, 3);
}

void Auth::addClient(Client &client)
{
	this->Clients.push_back(&client);
}

void Auth::newClient(Client &client)
{
	HANDLE       			hProcessThread;
	this->addClient(client);
	hProcessThread = CreateThread(NULL, 0, this->initializeThread, &client, 0, NULL);
}

DWORD WINAPI Auth::getIPCFunc()
{
	return (this->ipc->IPCThread(*this));
}

void Auth::startListening()
{
	if (initialized)
	{
		SOCKET newClient = 0;
		int opt = 1;
		SOCKADDR_IN ClientAddr;
		int ClientLen = sizeof(ClientAddr);

		if ((this->Listener = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, WSA_FLAG_OVERLAPPED)) == INVALID_SOCKET)
			throw AuthServerInvalidSocket(this->getLastWSError());
		if ((setsockopt(this->Listener, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, NULL)) == SOCKET_ERROR)
			throw AuthServerCantSetReUseAddr(this->getLastWSError());
		if (bind(this->Listener, (SOCKADDR *)&this->Addr, sizeof(this->Addr)) == SOCKET_ERROR)
			throw AuthServerBindError(this->getLastWSError());
		if (listen(this->Listener, 5) == SOCKET_ERROR)
			throw AuthServerListenError(this->getLastWSError());
		
		this->ipc = new IPC(this->ipc_port, this);
		this->printStarted();
		while (initialized)
		{
			if ((newClient = accept(this->Listener, (SOCKADDR *)&ClientAddr, &ClientLen)) == INVALID_SOCKET)
			{
				Logger::Error("An error occured while trying to accept a client");
				continue;
			}
			// Need an anti-flood
			Client *client = new Client(this, newClient, ClientAddr);
			this->newClient(*client);
		}
	}
	else throw AuthServerNotInitialized();
	while (1);
}

Database *Auth::getDatabase()
{
	return (this->db);
}

DWORD Auth::clientThread(Client &client) {
	char tmpBuffer[DATA_BUFSIZE];
	fd_set read_set;
	struct timeval timeout;

	timeout.tv_sec = 180;
	timeout.tv_usec = 0;
	int res = 0;
	SOCKET sock = client.getSocket();
	ProtocolRequired protocol(1758, 1759); // 2.40
	client.sendMessage(protocol);
	client.sendRawPatch();

	while (true)
	{
		FD_ZERO(&read_set);
		FD_SET(sock, &read_set);

		int r = select(sock + 1, &read_set, NULL, NULL, &timeout);
		if (r <= 0)
		{
			client.getAuth()->removeClient(client);
			ExitThread(0);
		}
		if (FD_ISSET(sock, &read_set))
		{
			res = recv(sock, tmpBuffer, DATA_BUFSIZE, 0);
			if (res > 0)
			{
				try
				{
					Packet packet;
					std::vector<char> buffer(tmpBuffer, tmpBuffer + res);

					while (packet.deserialize(buffer))
						Processor::processPacket(packet, client);
					ft_bzero(tmpBuffer, DATA_BUFSIZE);
					res = 0;
				}
				catch (std::exception &e)
				{
					Logger::Error("An error occured while handling a packet for one client", 12, e.what());
				}
			}
			else if (res <= 0)
			{
				client.getAuth()->removeClient(client);
				ExitThread(0);
			}
		}
	}
	return 0;
}

void Auth::removeClient(Client &client)
{
	try
	{
		std::lock_guard<std::mutex> locker(this->m);
		std::list<Client*>::iterator iter = this->Clients.begin();
		std::list<Client*>::iterator end = this->Clients.end();

		closesocket(client.getSocket());
		while (iter != this->Clients.end())
		{
			Client *toDelete = *iter;
			if (toDelete == &client)
			{
				iter = this->Clients.erase(iter);
				delete toDelete;
				break;
			}
			++iter;
		}
	}
	catch (std::exception &e)
	{
		Logger::Error("An error occured while trying to remove a client from the list", 12, e.what());
	}
	
}

Auth::~Auth()
{
	delete this->db;
	delete this->config;
}

Client *Auth::getClientByAccountId(int id)
{
	std::lock_guard<std::mutex> locker(this->m);
	std::list<Client*>::iterator iter = this->Clients.begin();
	std::list<Client*>::iterator end = this->Clients.end();

	while (iter != this->Clients.end())
	{
		Client *client = *iter;
		camp::UserObject account = client->getAccount();
		if (account.pointer() != NULL && (int)account.get("id") == id)
			return client;
		++iter;
	}
	return (NULL);
}

Config *Auth::getConfig()
{
	return (this->config);
}

void Auth::sendAllServerStatus(int serverId, int status)
{
	std::lock_guard<std::mutex> locker(this->m);
	this->db->updateWorldStatus(serverId, status);
	std::list<Client*>::iterator iter = this->Clients.begin();
	std::list<Client*>::iterator end = this->Clients.end();

	while (iter != this->Clients.end())
	{
		try
		{
			Client *client = *iter;
			if (client->getAccount().pointer() != NULL)
			{
				camp::UserObject worldsCharacters = client->getCharactersOnServer(serverId);
				int characters = 0;
				if (worldsCharacters.pointer() != NULL)
					characters = worldsCharacters.get("count");
				GameServerInformations infos(serverId, 1, status, 0, true, characters, 1, 0.0);
				ServerStatusUpdateMessage message(GameServerInformations(serverId, 1, status, 0, true, characters, 1, 0.0));
				client->sendMessage(message);
			}
		}
		catch (std::exception &e)
		{
			Logger::Error("Can't send server status to a client", 12, e.what());
		}
		++iter;
	}
}

void Auth::sendAll(IMessage &message)
{
	std::lock_guard<std::mutex> locker(this->m);
	std::list<Client*>::iterator iter = this->Clients.begin();
	std::list<Client*>::iterator end = this->Clients.end();

	while (iter != this->Clients.end())
	{
		Client *client = *iter;
		if (client->getAccount().pointer() != NULL)
			client->sendMessage(message);
		++iter;
	}
}

IPC *Auth::getIPC()
{
	return (this->ipc);
}