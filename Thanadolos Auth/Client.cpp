#include "Client.hpp"
#include "Auth.hpp"
#include <mutex>
#include "ProtocolRequired.hpp"
#include <WinSock2.h>
#include <fstream>
#include "RawDataMessage.hpp"
#include "Tickets.hpp"
#include "IpcTicketAccountMessage.hpp"
#include "IPC.hpp"
#include "IPCClient.hpp"

Client::Client(Auth *auth, SOCKET Socket, SOCKADDR_IN ClientAddr)
{
	this->Socket = Socket;
	this->Addr = ClientAddr;
	this->auth = auth;

	std::string msg = "New client (";
	msg += inet_ntoa(this->getAddr().sin_addr);
	msg += ":";
	char buffer[20];
	itoa(ntohs(this->getAddr().sin_port), buffer, 10);
	msg += buffer;
	msg += ") connected on auth server.";
	Logger::Infos(msg, 14);
	camp::UserObject Account;
	this->Account = Account;
}

SOCKADDR_IN Client::getAddr()
{
	return (this->Addr);
}

char *Client::getRealAddr()
{
	return inet_ntoa(this->getAddr().sin_addr);
}

u_short Client::getRealPort()
{
	return ntohs(this->getAddr().sin_port);
}

Auth *Client::getAuth()
{
	return (this->auth);
}

SOCKET Client::getSocket()
{
	return (this->Socket);
}

DWORD WINAPI Client::getThreadFunc()
{
	return (this->auth->clientThread(*this));
}

bool Client::operator==(const Client& other) const
{
	return true;
}

void Client::sendMessage(IMessage &message)
{
	try
	{
		ByteArray buffer;
		Packet packet;

		packet.serialize(message, buffer);
		send(this->getSocket(), buffer.data(), buffer.size(), 0);
		Logger::NetworkSnd(&message, packet, *this);
	}
	catch (std::exception &e)
	{
		Logger::Error("Can't serialize or send a packet", 12, e.what());
	}
}

void Client::sendRawPatch()
{
	ByteArray authPatch;
	std::string path = this->auth->getConfig()->getData("SWF_PATH");
	path += "/AuthPatch.swf";
	std::ifstream authPatchFile(path, std::ios::binary);
	std::copy(std::istreambuf_iterator<char>(authPatchFile), std::istreambuf_iterator<char>(), std::back_inserter(authPatch));

	RawDataMessage raw(authPatch);
	this->sendMessage(raw);
}

void Client::disconnect()
{
	closesocket(this->Socket);
}

Client::~Client()
{
	std::string msg = "Client (";
	msg += inet_ntoa(this->getAddr().sin_addr);
	msg += ":";
	char buffer[20];
	itoa(ntohs(this->getAddr().sin_port), buffer, 10);
	msg += buffer;
	msg += ") disconnected from auth server.";
	Logger::Infos(msg, 13);
}

void Client::setAccount(camp::UserObject object)
{
	this->Account = object;
}

camp::UserObject Client::getCharactersOnServer(int serverId)
{
	std::list <camp::UserObject> lists = this->getWorldsCharacters();

	std::list<camp::UserObject>::iterator iter = lists.begin();
	std::list<camp::UserObject>::iterator end = lists.end();
	while (iter != lists.end())
	{
		camp::UserObject worldsCharacters = *iter;
		int server = worldsCharacters.get("server");
		if (server == serverId)
			return (worldsCharacters);
		++iter;
	}
	camp::UserObject empty;
	return empty;
}

std::string Client::getTicket()
{
	return (this->ticket);
}

void Client::setTicket(std::string ticket)
{
	std::string msg = "New ticket generated for client : ";
	msg += ticket;
	Logger::Infos(msg);
	this->ticket = ticket;
}

ByteArray Client::getAES()
{
	return this->aes;
}

void Client::setAES(ByteArray aes)
{
	this->aes = aes;
}

void Client::sendTicket(camp::UserObject serverObject)
{
	IPCClient *server = this->getAuth()->getIPC()->getIPCByServerId(serverObject.get("id"));
	if (server != NULL)
	{
		SOCKET sock = server->getSocket();
		ByteArray buffer;
		Packet packet;
		IpcTicketAccountMessage ticketMessage(this->ticket, this->Account.get("id"), this->Account.get("account"), this->Account.get("password"),
			this->Account.get("question"), this->Account.get("answer"), this->Account.get("level"), this->Account.get("nickname"), this->Account.get("banned"));
		packet.serialize(ticketMessage, buffer);
		send(sock, buffer.data(), buffer.size(), 0);
	}
}