#include "Processor.hpp"
#include "BasicPingMessage.hpp"
#include "imessage.h"
#include "BinaryReader.hpp"
#include "IdentificationMessage.hpp"
#include "ServerSelectionMessage.hpp"
#include "AuthHandler.hpp"

bool Processor::processPacket(Packet &packet, Client &client)
{
	BinaryReader reader(packet.data());
	std::list<Handler*> handlers;

	handlers.push_back(new Handler(4, &AuthHandler::IdentificationMessageHandler, "IdentificationMessage"));
	handlers.push_back(new Handler(40, &AuthHandler::ServerSelectionMessageHandler, "ServerSelectionMessage"));

	std::list<Handler*>::iterator iter = handlers.begin();
	std::list<Handler*>::iterator end = handlers.end();
	
	bool packetHandled = false;
	while (iter != handlers.end())
	{
		Handler *handle =* iter;
		if (handle->packetId == packet.id())
		{
			try
			{
				packetHandled = true;
				Logger::NetworkRcv(packet, client, handle->name);
				handle->func(reader, client);
				break;
			}
			catch (std::exception &e)
			{
				Logger::Error("An error ocurred while trying to process a packet", 12, e.what());
				break;
			}
		}
		++iter;
	}
	if (packetHandled == false)
		Logger::NetworkRcv(packet, client);
	Processor::removeHandlers(handlers);
	return false;
}

void Processor::removeHandlers(std::list<Handler*> handlers)
{
	std::list<Handler*>::iterator iter = handlers.begin();
	std::list<Handler*>::iterator end = handlers.end();

	while (iter != handlers.end())
	{
		Handler *handle = *iter;
		delete handle;
		++iter;
	}
}