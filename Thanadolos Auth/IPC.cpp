#include "IPC.hpp"
#include "IPCClient.hpp"
#include "ServerStatusUpdateMessage.hpp"
#include "ServerStatus.hpp"
#include "IpcNewCharacterMessage.hpp"
#include "IpcDeletedCharacterMessage.hpp"
IPC::IPC(u_short listenPort, Auth *auth) : port(listenPort), auth(auth)
{
	try
	{
		this->Addr.sin_family = AF_INET;
		this->Addr.sin_port = htons(listenPort);
		this->Addr.sin_addr.s_addr = INADDR_ANY;
		HANDLE       			hProcessThread;

		hProcessThread = CreateThread(NULL, 0, this->initializeIPC, auth, 0, NULL);
	}
	catch (std::exception &e)
	{
		Logger::Error("Can't start thread to listen IPC communication", 12, e.what());
	}
}

void IPC::printStarted()
{
	std::string msg = "IPC server started on port ";
	char buffer[20];
	itoa(this->port, buffer, 10);
	msg += buffer;
	msg += ", ready to receive servers connections..";
	Logger::Infos(msg, 13);
}

DWORD IPC::IPCThread(Auth &auth)
{
	SOCKET newIPC = 0;
	int opt = 1;
	SOCKADDR_IN ClientAddr;
	int ClientLen = sizeof(ClientAddr);

	if ((this->Listener = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, WSA_FLAG_OVERLAPPED)) == INVALID_SOCKET)
		throw IPCServerInvalidSocket(auth.getLastWSError());
	if ((setsockopt(this->Listener, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, NULL)) == SOCKET_ERROR)
		throw IPCServerCantSetReUseAddr(auth.getLastWSError());
	if (bind(this->Listener, (SOCKADDR *)&this->Addr, sizeof(this->Addr)) == SOCKET_ERROR)
		throw IPCServerBindError(auth.getLastWSError());
	if (listen(this->Listener, 5) == SOCKET_ERROR)
		throw IPCServerListenError(auth.getLastWSError());
	this->printStarted();
	while (true)
	{
		if ((newIPC = accept(this->Listener, (SOCKADDR *)&ClientAddr, &ClientLen)) == INVALID_SOCKET)
		{
			Logger::Error("An error occured while trying to accept an IPC communication");
			continue;
		}
		IPCClient *ipcClient = new IPCClient(this, newIPC, ClientAddr);
		this->newIPCClient(*ipcClient);
	}
	return 0;
}

void IPC::addClient(IPCClient &client)
{
	this->Clients.push_back(&client);
}

void IPC::newIPCClient(IPCClient &ipcClient)
{
	HANDLE       			hProcessThread;
	this->addClient(ipcClient);
	hProcessThread = CreateThread(NULL, 0, this->initializeIPCClient, &ipcClient, 0, NULL);
}

void IPC::Process(Packet &packet, IPCClient &ipcClient)
{
	BinaryReader reader(packet.data());
	int id = packet.id();
	if (id == 50) // ServerStatusUpdateMessage
	{
		ServerStatusUpdateMessage message;
		message.deserialize(reader);
		GameServerInformations infos = message.informations;
		ipcClient.setServerId(infos.id);
		this->auth->sendAllServerStatus(ipcClient.getServerId(), ServerStatusEnum::ONLINE);
	}
	else if (id == IPC_NEW_CHARACTER) // A new character coming from a world server
	{
		IpcNewCharacterMessage message;
		message.deserialize(reader);
		this->auth->getDatabase()->increaseCharactersCount(message.serverId, message.accountId);
	}
	else if (id == IPC_DELETED_CHARACTER) // A character was deleted from a world server
	{
		IpcDeletedCharacterMessage message;
		message.deserialize(reader);
		this->auth->getDatabase()->decreaseCharactersCount(message.serverId, message.accountId);
	}
}

DWORD IPC::clientThread(IPCClient &ipcClient)
{
	std::string addr = ipcClient.getRealAddr();
	if (addr != "127.0.0.1")
	{
		Logger::Error("IPC disconnected cause was not coming from localhost");
		ipcClient.disconnect();
		this->removeClient(ipcClient);
		ExitThread(0);
	}
	
	char tmpBuffer[DATA_BUFSIZE];
	fd_set read_set;
	int res = 0;
	SOCKET sock = ipcClient.getSocket();

	while (true)
	{
		FD_ZERO(&read_set);
		FD_SET(sock, &read_set);

		int r = select(sock + 1, &read_set, NULL, NULL, NULL);
		if (r <= 0)
		{
			this->removeClient(ipcClient);
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
						this->Process(packet, ipcClient);
					ft_bzero(tmpBuffer, DATA_BUFSIZE);
					res = 0;
				}
				catch (std::exception &e)
				{
					Logger::Error("An error occured while handling a packet for one IPCclient", 12, e.what());
				}
			}
			else if (res <= 0)
			{
				this->removeClient(ipcClient);
				ExitThread(0);
			}
		}
	}
	return 0;
}

void IPC::removeClient(IPCClient &client)
{
	try
	{
		std::lock_guard<std::mutex> locker(this->m);
		std::list<IPCClient*>::iterator iter = this->Clients.begin();
		std::list<IPCClient*>::iterator end = this->Clients.end();

		closesocket(client.getSocket());
		while (iter != this->Clients.end())
		{
			IPCClient *toDelete = *iter;
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
		Logger::Error("An error occured while trying to remove a IPCclient from the list", 12, e.what());
	}
}

Auth *IPC::getAuth()
{
	return this->auth;
}

IPCClient *IPC::getIPCByServerId(int serverId)
{
	try
	{
		std::lock_guard<std::mutex> locker(this->m);
		std::list<IPCClient*>::iterator iter = this->Clients.begin();
		std::list<IPCClient*>::iterator end = this->Clients.end();

		while (iter != this->Clients.end())
		{
			IPCClient *client = *iter;
			if (client->getServerId() == serverId)
				return (client);
			++iter;
		}
		return (NULL);
	}
	catch (std::exception &e)
	{
		Logger::Error("An error occured while trying to get a IPCclient from the list", 12, e.what());
		return (NULL);
	}
}