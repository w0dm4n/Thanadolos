#include "Logger.hpp"
#include "Client.hpp"

Locker *Logger::getLocker()
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

void Logger::Infos(std::string const &msg, int color)
{
	Locker *lock = Logger::getLocker();
	lock->lock();
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);

	std::cout << "[INFOS]: " << msg.c_str() << std::endl;
	lock->unlock();
}

void Logger::Error(std::string const &msg, int color, std::string const &error)
{
	Locker *lock = Logger::getLocker();
	lock->lock();
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);

	if (error.empty())
		std::cout << "[ERROR]: " << msg.c_str() << std::endl;
	else
		std::cout << "[ERROR]: " << msg.c_str() << " (" << error.c_str() << ")" << std::endl;
	lock->unlock();
}

void Logger::NetworkRcv(Packet &packet, Client &client, std::string name, int color)
{
	Locker *lock = Logger::getLocker();
	lock->lock();
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
	std::cout << "[NETWORK] (" << client.getRealAddr() << ":" << client.getRealPort() << "): Received packet id: " << packet.id() \
		<< " of length: " << packet.length() << " bytes - ";
	if (!name.empty())
		std::cout << name << ": [HANDLED]";
	else
	{
		SetConsoleTextAttribute(hConsole, 12);
		std::cout << "[NO HANDLER]";
	}
	std::cout << std::endl;
	lock->unlock();
}

void Logger::NetworkSnd(IMessage *message, Packet &packet, Client &client, int color)
{
	Locker *lock = Logger::getLocker();
	lock->lock();
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
	std::cout << "[NETWORK] (" << client.getRealAddr() << ":" << client.getRealPort() << "): packet sent : " << message->getName() \
		<< ", length: " << packet.length() << " bytes." << std::endl;
	lock->unlock();
}
