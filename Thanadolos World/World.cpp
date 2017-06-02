#include "Globals.h"
#include "World.hpp"
#include "IPC.hpp"
#include "Character.hpp"
#include "Globals.h"

World::World()
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
	this->config = new Config("world_config.th");
}

void World::initializeData()
{
	if (WSAStartup(MAKEWORD(2, 2), &this->wsData) != 0)
	{
		std::cerr << "Can't initialize the library for socket." << std::endl;
		return;
	}

	this->id = atoi(this->config->getData("SERVER_ID").c_str());
	this->host = this->config->getData("WORLD_HOST");
	this->port = atoi(this->config->getData("WORLD_PORT").c_str());
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
		this->saveCycle = new Save(this->db, this, std::stoi(this->config->getData("SAVE_TIMER")));
		this->startedAt = Utils::getUnixTimestamp();
	}
}

LPSTR World::getLastWSError()
{
	int errCode = WSAGetLastError();
	LPSTR errString = NULL;

	int size = FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER |
		FORMAT_MESSAGE_FROM_SYSTEM, 0, errCode, 0, (LPSTR)&errString, 0, 0);
	return errString;
}

void World::printStarted()
{
	std::string msg = "World server started on port ";
	msg += std::to_string(this->port);
	msg += ", waiting for connections..";
	Logger::Infos(msg, 3);
}

void World::addClient(WorldClient &client)
{
	this->Clients.push_back(&client);
}

void World::newClient(WorldClient &client)
{
	HANDLE       			hProcessThread;
	this->addClient(client);
	hProcessThread = CreateThread(NULL, 0, this->initializeThread, &client, 0, NULL);
}

void World::startListening()
{
	if (initialized)
	{
		SOCKET newClient = 0;
		int opt = 1;
		SOCKADDR_IN ClientAddr;
		int ClientLen = sizeof(ClientAddr);

		if ((this->Listener = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, WSA_FLAG_OVERLAPPED)) == INVALID_SOCKET)
			throw WorldServerInvalidSocket(this->getLastWSError());
		if ((setsockopt(this->Listener, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, NULL)) == SOCKET_ERROR)
			throw WorldServerCantSetReUseAddr(this->getLastWSError());
		if (bind(this->Listener, (SOCKADDR *)&this->Addr, sizeof(this->Addr)) == SOCKET_ERROR)
			throw WorldServerBindError(this->getLastWSError());
		if (listen(this->Listener, 5) == SOCKET_ERROR)
			throw WorldServerListenError(this->getLastWSError());

		this->ipc = new IPC(this->ipc_port, this->config->getData("IPC_HOST"), this, atoi(this->config->getData("IPC_TIMER").c_str()));
		this->printStarted();
		while (initialized)
		{
			if ((newClient = accept(this->Listener, (SOCKADDR *)&ClientAddr, &ClientLen)) == INVALID_SOCKET)
			{
				Logger::Error("An error occured while trying to accept a client");
				continue;
			}
			// Need an anti-flood
			WorldClient *client = new WorldClient(this, newClient, ClientAddr);
			this->newClient(*client);
		}
	}
	else throw WorldServerNotInitialized();
	while (1);
}

World::~World()
{
	delete this->config;
}

DWORD World::clientThread(WorldClient &client)
{
	char tmpBuffer[DATA_BUFSIZE];
	fd_set read_set;
	struct timeval timeout;
	std::mutex current_mutex;

	timeout.tv_sec = 600; // 10 mins without any activities = disconnection
	timeout.tv_usec = 0;
	int res = 0;
	SOCKET sock = client.getSocket();
	client.sendMessage(ProtocolRequired(1758, 1759)); // 2.40
	client.sendMessage(HelloGameMessage());
	while (true)
	{
		FD_ZERO(&read_set);
		FD_SET(sock, &read_set);

		int r = select(sock + 1, &read_set, NULL, NULL, &timeout);
		if (r <= 0)
		{
			this->removeClient(client);
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
					{
						current_mutex.lock(); // to make sure that the client handle one packet by one
						Processor::processPacket(packet, client);
						current_mutex.unlock();
					}
					ft_bzero(tmpBuffer, DATA_BUFSIZE);
					res = 0;
				}
				catch (std::exception &e)
				{
					Logger::Error("An error occured while handling a packet for one client", 12, e.what());
					current_mutex.unlock();
				}
			}
			else if (res <= 0)
			{
				this->removeClient(client);
				ExitThread(0);
			}
		}
	}
	return 0;
}

void World::removeClient(WorldClient &client)
{
	try
	{
		std::lock_guard<std::mutex> locker(this->m);
		std::list<WorldClient*>::iterator iter = this->Clients.begin();
		std::list<WorldClient*>::iterator end = this->Clients.end();

		closesocket(client.getSocket());
		while (iter != this->Clients.end())
		{
			WorldClient *toDelete = *iter;
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

DWORD WINAPI World::getIPCFunc()
{
	return (this->ipc->IPCThread(*this));
}

IPC *World::getIPC()
{
	return this->ipc;
}

GameServerInformations World::getOnlineGameServerInformations()
{
	return GameServerInformations(this->id, 1, 3, 0, true, 0, 5, 0.0);
}

Database *World::getDatabase()
{
	return this->db;
}

Config *World::getConfig()
{
	return this->config;
}

uint World::getId()
{
	return this->id;
}

WorldClient *World::getWorldClientByAccountId(int id)
{
	std::lock_guard<std::mutex> locker(this->m);
	std::list<WorldClient*>::iterator iter = this->Clients.begin();
	std::list<WorldClient*>::iterator end = this->Clients.end();

	while (iter != this->Clients.end())
	{
		WorldClient *client = *iter;
		camp::UserObject account = client->getAccount();
		if (account.pointer() != NULL && (int)account.get("id") == id)
			return client;
		++iter;
	}
	return (NULL);
}

Map	*World::getMapInstance(int mapId)
{
	std::lock_guard<std::mutex> locker(this->m);
	int i = 0;
	while (i < this->Maps.size())
	{
		if ((int)this->Maps[i]->getMapRecord().get("id") == mapId)
			return this->Maps[i];
		i++;
	}
	Map *mapInstance = new Map(mapId, this->getDatabase());
	this->Maps.push_back(mapInstance);
	return mapInstance;
}

void World::teleportClient(int mapId, int cellId, WorldClient &client)
{
	if (client.character->getMap() != NULL)
		client.character->getMap()->leaveMap(client);
	Map *mapInstance = this->getMapInstance(mapId);
	if (mapInstance != NULL)
	{
		client.character->updatePosition(mapId, cellId);
		mapInstance->enterMap(client);
	}
	else
	{
		Logger::Error("An error occured while trying to teleport a client");
		client.disconnect();
	}
}

Save *World::getSave()
{
	return this->saveCycle;
}

WorldClient *World::getClient(std::string name)
{
	std::lock_guard<std::mutex> locker(this->m);
	std::list<WorldClient*>::iterator iter = this->Clients.begin();
	std::list<WorldClient*>::iterator end = this->Clients.end();

	while (iter != this->Clients.end())
	{
		WorldClient *client = *iter;
		if (client->character != NULL)
		{
			std::string currentName = client->character->getCharacterRecord().get("Name");
			if (currentName == name)
				return (client);
		}
		++iter;
	}
	return (NULL);
}

void World::sendToAllOnlineClients(IMessage &message)
{
	std::lock_guard<std::mutex> locker(this->m);
	std::list<WorldClient*>::iterator iter = this->Clients.begin();
	std::list<WorldClient*>::iterator end = this->Clients.end();

	while (iter != this->Clients.end())
	{
		WorldClient *client = *iter;
		if (client->character != NULL)
			client->sendMessage(message);
		++iter;
	}
}


int			World::countAllOnlineClients()
{
	std::lock_guard<std::mutex> locker(this->m);
	int players = 0;
	std::list<WorldClient*>::iterator iter = this->Clients.begin();
	std::list<WorldClient*>::iterator end = this->Clients.end();

	while (iter != this->Clients.end())
	{
		WorldClient *client = *iter;
		if (client->character != NULL)
			players++;
		++iter;
	}
	return players;
}

std::string World::getUptime()
{
	long int dateNow = Utils::getUnixTimestamp();
	int secs = (dateNow - this->startedAt);
	int days = std::floor(secs / (3600 * 24));
	int hours = std::floor((secs - (days * (3600 * 24))) / 3600);
	int minutes = std::floor((secs - (days * (3600 * 24)) - (hours * 3600)) / 60);
	int seconds = std::floor(secs - (days * (3600 * 24)) - (hours * 3600) - (minutes * 60));

	return std::to_string(hours) + " heures, " + std::to_string(minutes) + " minutes" + ", " + std::to_string(seconds) + " secondes.";
}

std::vector<WorldClient*> World::getAllOnlineClients()
{
	std::lock_guard<std::mutex> locker(this->m);
	std::vector<WorldClient*> clients;
	std::list<WorldClient*>::iterator iter = this->Clients.begin();
	std::list<WorldClient*>::iterator end = this->Clients.end();

	while (iter != this->Clients.end())
	{
		WorldClient *client = *iter;
		if (client->character != NULL)
			clients.push_back(client);
		++iter;
	}
	return clients;
}