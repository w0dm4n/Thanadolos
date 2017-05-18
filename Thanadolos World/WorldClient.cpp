#include "Globals.h"
#include "WorldClient.hpp"
#include "World.hpp"
#include "IPC.hpp"
#include "Character.hpp"

WorldClient::WorldClient(World *world, SOCKET Socket, SOCKADDR_IN WorldClientAddr)
{
	this->Socket = Socket;
	this->Addr = WorldClientAddr;
	this->world = world;
	this->character = NULL;

	std::string msg = "New client (";
	msg += inet_ntoa(this->getAddr().sin_addr);
	msg += ":";
	char buffer[20];
	itoa(ntohs(this->getAddr().sin_port), buffer, 10);
	msg += buffer;
	msg += ") connected on World server.";
	Logger::Infos(msg, 14);
}

SOCKADDR_IN WorldClient::getAddr()
{
	return (this->Addr);
}

char *WorldClient::getRealAddr()
{
	return inet_ntoa(this->getAddr().sin_addr);
}

u_short WorldClient::getRealPort()
{
	return ntohs(this->getAddr().sin_port);
}

World *WorldClient::getWorld()
{
	return (this->world);
}

SOCKET WorldClient::getSocket()
{
	return (this->Socket);
}

DWORD WINAPI WorldClient::getThreadFunc()
{
	return (this->world->clientThread(*this));
}

bool WorldClient::operator==(const WorldClient& other) const
{
	return true;
}

void WorldClient::sendMessage(IMessage &message)
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

void WorldClient::disconnect()
{
	closesocket(this->Socket);
}

WorldClient::~WorldClient()
{
	if (this->character)
		delete character;
	// CLEAR TICKETACCOUNT FROM WORLD

	std::string msg = "Client (";
	msg += inet_ntoa(this->getAddr().sin_addr);
	msg += ":";
	char buffer[20];
	itoa(ntohs(this->getAddr().sin_port), buffer, 10);
	msg += buffer;
	msg += ") disconnected from World server.";
	Logger::Infos(msg, 13);
}

void WorldClient::setAccount(camp::UserObject account)
{
	this->Account = account;
}

camp::UserObject WorldClient::getAccount()
{
	return this->Account;
}

std::vector<camp::UserObject> WorldClient::getCharacters()
{
	return this->Characters;
}

void WorldClient::addCharacter(camp::UserObject &characterRecord)
{
	this->Characters.push_back(characterRecord);
}

void WorldClient::sendNewCharacterToAuth()
{
	if (this->Account.pointer() != NULL)
	{
		IpcNewCharacterMessage message((int) this->Account.get("id"), this->world->getId());
		this->world->getIPC()->sendToAuth(message);
	}
}

void WorldClient::sendDeletedCharacterToAuth()
{
	if (this->Account.pointer() != NULL)
	{
		IpcDeletedCharacterMessage message((int) this->Account.get("id"), this->world->getId());
		this->world->getIPC()->sendToAuth(message);
	}
}

void WorldClient::updateCharactersRecord(std::vector<camp::UserObject> characters)
{
	this->Characters = characters;
}

void WorldClient::buildCharacter(int characterId)
{
	int i = 0;
	while (i < this->Characters.size())
	{
		camp::UserObject character = this->Characters[i];
		if ((int)character.get("Id") == characterId)
			this->character = new Character(character, this->Account, *this);
		i++;
	}
}