#include "AuthHandler.hpp"
#include "IdentificationSuccessMessage.hpp"
#include "IdentificationFailedMessage.hpp"
#include "GameServerInformations.hpp"
#include "IdentificationFailureReason.hpp"
#include "ServerSelectionMessage.hpp"
#include "SelectedServerDataMessage.hpp"
#include "Utils.h"
#include "Auth.hpp"
#include "Database.hpp"
#include "Tickets.hpp"
#pragma comment(lib, "ws2_32.lib")

ServerListMessage AuthHandler::getServersList(Client &client)
{
	std::vector<GameServerInformations> serversList;
	std::list<camp::UserObject> servers = client.getAuth()->getDatabase()->getWorldsServers();
	std::list<camp::UserObject>::iterator iter = servers.begin();
	std::list<camp::UserObject>::iterator end = servers.end();

	while (iter != servers.end())
	{
		camp::UserObject server = *iter;
		camp::UserObject characters = client.getCharactersOnServer(server.get("id"));
		if (characters.pointer() != NULL)
		{
			serversList.push_back(GameServerInformations((uint)server.get("id"), 1, (uint)server.get("status"), 0, true, characters.get("count"), 5, 0.0));
		}
		else
		{
			serversList.push_back(GameServerInformations((uint)server.get("id"), 1, (uint)server.get("status"), 0, true, 0, 5, 0.0));
		}
		++iter;
	}
	return ServerListMessage(serversList, 0, true);
}

void AuthHandler::IdentificationMessageHandler(BinaryReader &reader, Client &client)
{
	IdentificationMessage message;
	message.deserialize(reader);

	BinaryReader Reader(message.credentials);
	std::string account = Reader.readUTF();
	std::string password = Reader.readUTF();
	client.setAES(Reader.readBytes(32)); // 32 = ticket len
	if (!account.empty() && !password.empty())
	{
		camp::UserObject Account = client.getAuth()->getDatabase()->getAccount(account, password);
		if (Account.pointer() != NULL)
		{
			Client *connected = client.getAuth()->getClientByAccountId(Account.get("id"));
			if (connected != NULL)
				connected->disconnect();
			bool banned = Account.get("banned");
			if (banned)
			{
				client.sendMessage(IdentificationFailedMessage(IdentificationFailureReasonEnum::BANNED));
				client.disconnect();
			}
			else
			{
				int level = Account.get("level");
				client.setAccount(Account);

				if (level == 0)
				{
					__int64 now = 1492667581000;
					__int64 end = 3077744000000;
					// 24/03/2020 - 20:00
					client.sendMessage(IdentificationSuccessMessage(Account.get("account"),
						Account.get("nickname"), Account.get("id"), 0, false, Account.get("question"), 0, 0, (end - now), end, 0));
				}
				else
				{
					client.sendMessage(IdentificationSuccessMessage(Account.get("account"),
						Account.get("nickname"), Account.get("id"), 0, true, Account.get("question"), 0, 0, 0, 0, 0));
				}
				std::list<camp::UserObject> lists = client.getAuth()->getDatabase()->getWorldsCharactersByAccountId(Account.get("id"));
				client.setWorldsCharacters(&lists);
				client.sendMessage(AuthHandler::getServersList(client));
			}
		}
		else
		{
			client.sendMessage(IdentificationFailedMessage(IdentificationFailureReasonEnum::WRONG_CREDENTIALS));
			client.disconnect();
		}
	}
}

void AuthHandler::ServerSelectionMessageHandler(BinaryReader &reader, Client &client)
{
	ServerSelectionMessage message;
	message.deserialize(reader);

	camp::UserObject server = client.getAuth()->getDatabase()->getWorldServer(message.serverId);
	if (server.pointer() != NULL)
	{
		try
		{
			ByteArray ticket = Tickets::generateTicket(client);
			std::string ticketString(ticket.begin(), ticket.end());

			client.setTicket(ticketString);
			client.sendTicket(server);

			SelectedServerDataMessage message(server.get("id"), server.get("address"), server.get("port"), true, ticketString);
			client.sendMessage(message);
			client.disconnect();
		}
		catch (std::exception &e)
		{
			Logger::Error("One client disconnected on selecting a server !", 12, e.what());
			client.disconnect();
		}
	}
}