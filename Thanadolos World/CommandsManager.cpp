#include "Globals.h"
#include "CommandsManager.hpp"

void CommandsManager::manageCommand(std::string content, WorldClient &client)
{
	char					*command = (char*) content.c_str();
	std::vector<Commands>	commands;
	Split					datas;
	bool					handled = false;

	command++;
	commands.push_back(Commands("infos", &CommandsManager::infosCommand, AccountRole::ANIMATOR, "Donne des informations sur le serveur et le nombre de joueurs en ligne"));
	commands.push_back(Commands("announce", &CommandsManager::announceCommand, AccountRole::ANIMATOR, "Envoi une annonce a tout les joueurs actuellement connectées"));
	commands.push_back(Commands("help", &CommandsManager::announceCommand, AccountRole::PLAYER, "Liste les commandes disponibles"));
	commands.push_back(Commands("start", &CommandsManager::startCommand, AccountRole::PLAYER, "Téléporte a la map de départ"));

	if (!strcmp(command, "help"))
	{
		client.character->replyText("Commandes disponibles : <br/>");
		for (int i = 0; i < commands.size(); i++)
		{
			if ((int)client.getAccount().get("level") >= commands[i].role)
				client.character->replyText("<b>." + commands[i].command + "</b>: " + commands[i].description + "<br/>");
		}
		return;
	}

	datas = Utils::split(command, ' ');
	for (int i = 0; i < commands.size(); i++)
	{
		if (datas[0] == commands[i].command)
		{
			if ((int) client.getAccount().get("level") >= commands[i].role)
				commands[i].func(datas, client);
			else
				client.character->replyError("Vous n'êtes pas autorisé à utiliser cette commande.");
			handled = true;
			break;
		}
	}
	if (!handled)
		client.character->replyText("Cette commande n'existe pas. Pour avoir une liste des commandes disponible: <b>.help</b>");
}

void CommandsManager::infosCommand(Split command, WorldClient &client)
{
	client.character->replyText("Salut !");
}

void CommandsManager::announceCommand(Split command, WorldClient &client)
{
	
}

void CommandsManager::startCommand(Split command, WorldClient &client)
{
	client.getWorld()->teleportClient(std::stoi(client.getWorld()->getConfig()->getData("START_MAP")),
		std::stoi(client.getWorld()->getConfig()->getData("START_CELL")), client);
	client.character->replyText("Vous avez été téléporté à la zone de départ.");
}