# ifndef CHAT_HANDLER_HPP
# define CHAT_HANDLER_HPP
#include "WorldClient.hpp"
#include "World.hpp"
#include "IPC.hpp"
#include "Character.hpp"

#include "ChatClientMultiMessage.hpp"
#include "ChatActivableChannelsEnum.hpp"
#include "ChatServerMessage.hpp"
#include "ChatServerCopyMessage.hpp"
#include "ChatClientPrivateMessage.hpp"
#include "AccountRole.hpp"
#include "CommandsManager.hpp"

class ChatHandler
{
public:
	static void ChatClientPrivateMessageHandler(BinaryReader &reader, WorldClient &client);
	static void ChatClientMultiMessageHandler(BinaryReader &reader, WorldClient &client);
	static std::string escapeMessageHtml(std::string content);
};
#endif