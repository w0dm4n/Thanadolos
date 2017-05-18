#pragma once
#ifndef PROCESSOR_HPP
# define PROCESSOR_HPP

#include "Packet.hpp"
#include "Client.hpp"

typedef struct Handler
{
	Handler(int id, void(*foo)(BinaryReader&, Client &client), std::string name) {
		this->packetId = id; this->func = foo; this->name = name;
	}
	int packetId;
	void(*func)(BinaryReader&, Client &client);
	std::string name;
};


class Processor
{
public:
	static bool processPacket(Packet &packet, Client &client);
	static void removeHandlers(std::list<Handler*> lists);
};
#endif
