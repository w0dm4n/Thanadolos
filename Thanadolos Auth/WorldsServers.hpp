#pragma once

#ifndef WORLDSSERVERS_HPP
# define WORLDSSERVERS_HPP

#pragma comment(lib, "campd.lib")
#include <camp/camptype.hpp>
#include <camp/class.hpp>
#include <SQLAPI.h>

#include <iostream>
class WorldsServersRecord
{
public:
	static void declareRecord()
	{
		camp::Class::declare<WorldsServersRecord>("WorldsServersRecord")
			.constructor0()
			.property("id", &WorldsServersRecord::getId, &WorldsServersRecord::setId)
			.property("name", &WorldsServersRecord::getName, &WorldsServersRecord::setName)
			.property("address", &WorldsServersRecord::getAddress, &WorldsServersRecord::setAddress)
			.property("port", &WorldsServersRecord::getPort, &WorldsServersRecord::setPort)
			.property("capacity", &WorldsServersRecord::getMaxCapacity, &WorldsServersRecord::setMaxCapacity)
			.property("status", &WorldsServersRecord::getServerStatus, &WorldsServersRecord::setServerStatus)
			.property("role", &WorldsServersRecord::getRequiredRole, &WorldsServersRecord::setRequiredRole);
	}
	WorldsServersRecord() { }

	int getId() const { return this->Id; }
	void setId(int id) { this->Id = id; }

	std::string getName() const { return this->Name; }
	void setName(std::string name) { this->Name = name; }

	std::string getAddress() const { return this->Address; }
	void setAddress(std::string address) { this->Address = address; }

	int getPort() const { return this->Port; }
	void setPort(int port) { this->Port = port; }

	int getMaxCapacity() const { return this->MaxCapacity; }
	void setMaxCapacity(int capacity) { this->MaxCapacity = capacity; }

	int getServerStatus() const { return this->ServerStatus; }
	void setServerStatus(int status) { this->ServerStatus = status; }

	int getRequiredRole() const { return this->RequiredRole; }
	void setRequiredRole(int role) { this->RequiredRole = role; }

private:
	int Id;
	std::string Name;
	std::string Address;
	int Port;
	int MaxCapacity;
	int ServerStatus;
	int RequiredRole;
};

CAMP_TYPE(WorldsServersRecord)

#endif
