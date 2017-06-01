#ifndef ADMIN_HANDLER_HPP
# define ADMIN_HANDLER_HPP
#include "WorldClient.hpp"
#include "World.hpp"
#include "IPC.hpp"

#include "Character.hpp"
#include "CharactersManager.hpp"
#include "Map.hpp"
#include "AdminCommandMessage.hpp"
#include "AccountRole.hpp"

class AdminHandler
{
public:
	static void AdminQuietCommandMessageHandler(BinaryReader &reader, WorldClient &client);
};


#endif