#include "Globals.h"
#include "AdminHandler.hpp"

void AdminHandler::AdminQuietCommandMessageHandler(BinaryReader &reader, WorldClient &client)
{
	AdminCommandMessage message;
	message.deserialize(reader);

	if ((int) client.character->getAccountRecord().get("level") < AccountRole::ANIMATOR)
		return;
	Split command = Utils::split(message.content, ' ');
	if (command.size() > 0)
	{
		if (command[0] == "moveto")
			client.getWorld()->teleportClient(std::stoi(command[1]), client.character->getCharacterRecord().get("CellId"), client);
	}
}