#pragma once
#include "Config.hpp"
#include "WorldClient.hpp"
#include "Processor.hpp"
#include "Database.hpp"
#include "GameServerInformations.hpp"
#include "ProtocolRequired.hpp"
#include "HelloGameMessage.hpp"
#include "Save.hpp"
#ifdef _DEBUG
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

class   IPC;
class   Map;
void	ft_bzero(void *s, size_t n);

class World
{
public:
	static const int VERSION_MAJOR = 1;
	static const int VERSION_MINOR = 0;
	static const int TYPE = 0;

	std::list<WorldClient*> Clients;
	std::vector<Map*> Maps;
	World();
	~World();
	void initializeData();
	void startListening();
	void printStarted();
	LPSTR getLastWSError();
	DWORD clientThread(WorldClient &client);
	void newClient(WorldClient &client);
	void addClient(WorldClient &client);
	void removeClient(WorldClient &client);
	IPC *getIPC();
	Database *getDatabase();
	DWORD WINAPI getIPCFunc();
	Config *getConfig();
	Save *getSave();
	uint getId();
	GameServerInformations		getOnlineGameServerInformations();
	Map							*getMapInstance(int mapId);
	WorldClient					*getWorldClientByAccountId(int id);
	WorldClient					*getClient(std::string name);
	void						sendToAllOnlineClients(IMessage &message);
	int							countAllOnlineClients();
	std::vector<WorldClient*>	getAllOnlineClients();
	std::string getUptime();

	void teleportClient(int mapId, int cellId, WorldClient &client);

	struct WorldServerNotInitialized : public std::exception {
		virtual const char* what() const throw() {
			return "The World server was not initialized properly";
		}
	};

	struct WorldServerInvalidSocket : public std::exception {
		WorldServerInvalidSocket(LPSTR error) { std::cerr << error; }
		virtual const char* what() const throw() {
			return "The World server socket was invalid";
		}
	};

	struct WorldServerBindError : public std::exception {
		WorldServerBindError(LPSTR error) { std::cerr << error; }
		virtual const char* what() const throw() {
			return "The World server can't bind socket";
		}
	};

	struct WorldServerCantSetReUseAddr : public std::exception {
		WorldServerCantSetReUseAddr(LPSTR error) { std::cerr << error; }
		virtual const char* what() const throw() {
			return "The World server can't set SO_REUSEADDR on the socket";
		}
	};

	struct WorldServerListenError : public std::exception {
		WorldServerListenError(LPSTR error) { std::cerr << error; }
		virtual const char* what() const throw() {
			return "The World server can't listen on socket";
		}
	};

	static DWORD WINAPI initializeThread(void *p)
	{
		WorldClient *Obj = reinterpret_cast<WorldClient*>(p);
		return Obj->getThreadFunc();
	}

private:
	WSADATA				wsData;
	SOCKADDR_IN			Addr;
	SOCKET				Listener;
	std::string			host;
	u_short				port;
	u_short				ipc_port;
	bool				initialized;
	Database			*db;
	std::mutex			m;
	IPC					*ipc;
	Config				*config;
	uint				id;
	Save				*saveCycle;
	long int			startedAt;

};

#define DATA_BUFSIZE 8096