#pragma once
#include <iostream>
#include <time.h>
#include <list>
#include <mutex>
#include "Client.hpp"
#include "Locker.hpp"
#include <chrono>

class Tickets
{
public:
	static ByteArray			  generateTicket(Client &client);
	static int					  getRand(int min, int max);
	static bool					  isTicketTaken(ByteArray &ticket);
	static void					  addTicket(ByteArray &ticket, Client &client);
	static std::list<ByteArray> getTickets();
	static Locker				 *getLocker();
};