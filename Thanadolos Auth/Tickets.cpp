#include "Tickets.hpp"

Locker *Tickets::getLocker()
{
	static Locker *locker;
	if (locker != NULL)
	{
		return (locker);
	}
	else
	{
		locker = new Locker();
		return (locker);
	}
	return (locker);
}

std::list<ByteArray> Tickets::getTickets()
{
	static std::list<ByteArray> *tickets;
	if (tickets != NULL)
	{
		return (*tickets);
	}
	else
	{
		tickets = new std::list<ByteArray>();
		return (*tickets);
	}
	return (*tickets);
}

void		Tickets::addTicket(ByteArray &ticket, Client &client)
{
	Locker *locker = Tickets::getLocker();
	locker->lock();
	std::list<ByteArray> tickets = Tickets::getTickets();
	tickets.push_back(ticket);
	locker->unlock();
}

int			Tickets::getRand(int min, int max)
{
	__int64 now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

	int value = (rand() + now) % max;
	value = (value < min) ? min : value;
	return (value);
}

bool		Tickets::isTicketTaken(ByteArray &ticket)
{
	Locker *locker = Tickets::getLocker();
	locker->lock();
	std::list<ByteArray> tickets = Tickets::getTickets();
	std::list<ByteArray>::iterator iter = tickets.begin();
	std::list<ByteArray>::iterator end = tickets.end();

	while (iter != tickets.end())
	{
		ByteArray tmp = *iter;
		if (tmp == ticket)
		{
			locker->unlock();
			return true;
		}
	}
	locker->unlock();
	return false;
}

ByteArray Tickets::generateTicket(Client &client)
{
	const char *keys = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int ticket_len = 32;
	int i = 0;

	int keysLen = strlen(keys) - 1;
	while (true)
	{
		ByteArray ticket;

		while (i < ticket_len)
		{
			ticket.push_back(keys[Tickets::getRand(0, keysLen)]);
			i++;
		}
		if (!Tickets::isTicketTaken(ticket))
		{
			Tickets::addTicket(ticket, client);
			return ticket;
		}
		else
		{
			ticket.clear();
		}
	}
}