#include "ServerListMessage.hpp"

ServerListMessage::ServerListMessage(
	std::vector<GameServerInformations> _servers,
	uint _alreadyConnectedToServerId,
	bool _canCreateNewCharacter
)
{
	servers = _servers;
	alreadyConnectedToServerId = _alreadyConnectedToServerId;
	canCreateNewCharacter = _canCreateNewCharacter;
}

ushort ServerListMessage::getId()
{
	return id;
}

std::string ServerListMessage::getName()
{
	return "ServerListMessage";
}

void ServerListMessage::serialize(BinaryWriter& writer)
{
	writer.writeShort(static_cast<short>(servers.size()));
	for (int i = 0; i < servers.size(); i++)
	{
		servers[i].serialize(writer);
	}
	writer.writeVarShort(static_cast<short>(alreadyConnectedToServerId));
	writer.writeBool(canCreateNewCharacter);
}

void ServerListMessage::deserialize(BinaryReader& reader)
{

}