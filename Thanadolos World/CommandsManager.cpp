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
	commands.push_back(Commands("teleport", &CommandsManager::teleportCommand, AccountRole::ANIMATOR, "Téléporte sur une nouvelle carte"));
	commands.push_back(Commands("teleportTo", &CommandsManager::teleportToCommand, AccountRole::ANIMATOR, "Téléporte sur un joueur"));
	commands.push_back(Commands("teleportName", &CommandsManager::teleportNameCommand, AccountRole::ANIMATOR, "Téléporte un joueur sur votre position"));
	commands.push_back(Commands("kick", &CommandsManager::kickCommand, AccountRole::ANIMATOR, "Kick un joueur"));
	commands.push_back(Commands("who", &CommandsManager::whoCommand, AccountRole::MODERATOR, "Liste les joueurs en ligne"));
	commands.push_back(Commands("experience", &CommandsManager::experienceCommand, AccountRole::MODERATOR, "Permet de rajouter de l'expérience a un joueur"));

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
	client.character->replyText("Thanadolos version <b>" + std::to_string(client.getWorld()->VERSION_MAJOR) + "."
		+ std::to_string(client.getWorld()->VERSION_MINOR) + "." + std::to_string(client.getWorld()->TYPE) + "</b>" +
	"<br/>" + std::to_string(client.getWorld()->countAllOnlineClients()) + " joueurs actuellement en ligne." +
	"<br/>Uptime : " + client.getWorld()->getUptime());
}

void CommandsManager::announceCommand(Split command, WorldClient &client)
{
	std::vector<std::string> params;
	if (command.size() >= 2)
	{
		std::string message = "<font color=\"#6495ED\"><b>[" + client.character->getCharacterName() + "]</b>: ";
		int i = 1;
		while (i < command.size())
			message += command[i++] + " ";
		message += "</font>";
		params.push_back(message);

		client.getWorld()->sendToAllOnlineClients(TextInformationMessage(0, 0, params));
	}
	else
		client.character->replyError("Erreur de syntaxe (.announce message)");
}

void CommandsManager::startCommand(Split command, WorldClient &client)
{
	// check if busy
	client.getWorld()->teleportClient(std::stoi(client.getWorld()->getConfig()->getData("START_MAP")),
		std::stoi(client.getWorld()->getConfig()->getData("START_CELL")), client);
	client.character->replyText("Vous avez été téléporté à la zone de départ.");
}

void CommandsManager::teleportCommand(Split command, WorldClient &client)
{
	if (command.size() == 3)
	{
		// check if busy
		client.getWorld()->teleportClient(std::stoi(command[1]),
			std::stoi(command[2]), client);
	}
	else
		client.character->replyError("Erreur de syntaxe (.teleport mapId cellId)");
}


void CommandsManager::teleportToCommand(Split command, WorldClient &client)
{
	if (command.size() == 2)
	{
		WorldClient *target = client.getWorld()->getClient(command[1]);
		if (target != NULL)
		{
			// check if busy
			client.getWorld()->teleportClient(target->character->getMap()->getMapRecord().get("id"),
				target->character->getCharacterRecord().get("CellId"), client);
		}
		else
			client.character->replyText("Impossible de trouver ce joueur !");
	}
	else
		client.character->replyError("Erreur de syntaxe (.teleportTo playerName)");
}

void CommandsManager::teleportNameCommand(Split command, WorldClient &client)
{
	if (command.size() == 2)
	{
		WorldClient *target = client.getWorld()->getClient(command[1]);
		if (target != NULL)
		{
			// check if busy
			target->getWorld()->teleportClient(client.character->getMap()->getMapRecord().get("id"),
				client.character->getCharacterRecord().get("CellId"), *target);
		}
		else
			client.character->replyText("Impossible de trouver ce joueur !");
	}
	else
		client.character->replyError("Erreur de syntaxe (.teleportName playerName)");
}

void CommandsManager::experienceCommand(Split command, WorldClient &client)
{
	if (command.size() == 3)
	{
		WorldClient *target = client.getWorld()->getClient(command[1]);
		if (target != NULL)
		{
			target->character->addExperience(std::stoll(command[2]));
			client.character->replyText("Expérience ajoutée avec succès sur le personnage <b>" + target->character->getCharacterName() + "</b>");
		}
		else
			client.character->replyText("Impossible de trouver ce joueur !");
	}
	else
		client.character->replyError("Erreur de syntaxe (.experience playerName number)");
}

void CommandsManager::kickCommand(Split command, WorldClient &client)
{
	if (command.size() == 2)
	{
		WorldClient *target = client.getWorld()->getClient(command[1]);
		if (target != NULL)
		{
			if ((int)target->getAccount().get("level") <= (int)client.getAccount().get("level"))
				target->disconnect();
			else
				client.character->replyError("Impossible sur cette cible.");
		}
		else
			client.character->replyText("Impossible de trouver ce joueur !");
	}
	else
		client.character->replyError("Erreur de syntaxe (.kick playerName)");
}

void CommandsManager::whoCommand(Split command, WorldClient &client)
{
	std::vector<WorldClient*> clients = client.getWorld()->getAllOnlineClients();
	for (int i = 0; i < clients.size(); i++)
		client.character->replyText("- <b>" + clients[i]->character->getCharacterName() + "</b>");
}