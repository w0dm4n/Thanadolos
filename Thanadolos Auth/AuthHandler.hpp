#ifndef AUTH_HANDLER_HPP
# define AUTH_HANDLER_HPP
#include "IdentificationMessage.hpp"
#include "ServerListMessage.hpp"
#include "Client.hpp"
class AuthHandler
{
public:
	static void IdentificationMessageHandler(BinaryReader &reader, Client &client);
	static void ServerSelectionMessageHandler(BinaryReader &reader, Client &client);
	static ServerListMessage getServersList(Client &client);
};


#endif