#pragma once

#ifndef COMMANDS_MANAGER_HPP
# define COMMANDS_MANAGER_HPP

#include "WorldClient.hpp"
#include "Character.hpp"
#include "AccountRole.hpp"
#include "Config.hpp"

typedef struct Commands
{
	Commands(std::string command, void(*foo)(Split, WorldClient &client), int role, std::string description) {
		this->command = command; this->func = foo; this->role = role; this->description = description;
	}
	void(*func)(Split, WorldClient &client);
	std::string command;
	int			role;
	std::string description;
};

class CommandsManager
{
public:
	static void manageCommand(std::string content, WorldClient &client);


	/* Commands */
	static void infosCommand(Split command, WorldClient &client);
	static void announceCommand(Split command, WorldClient &client);
	static void startCommand(Split command, WorldClient &client);
};

#endif