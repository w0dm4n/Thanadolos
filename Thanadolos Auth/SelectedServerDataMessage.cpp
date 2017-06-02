#include "SelectedServerDataMessage.hpp"
#include "Logger.hpp"

SelectedServerDataMessage::SelectedServerDataMessage(
	short _serverid,
	std::string _address,
	short _port,
	bool _canCreateNewCharacter,
	std::string _ticket
)
{
	serverId = _serverid;
	address = _address;
	port = _port;
	canCreateNewCharacter = _canCreateNewCharacter;
	ticket = _ticket;
}

ushort SelectedServerDataMessage::getId()
{
	return id;
}

std::string SelectedServerDataMessage::getName()
{
	return "SelectedServerDataMessage";
}

void SelectedServerDataMessage::serialize(BinaryWriter& writer)
{
	writer.writeVarShort(this->serverId);
	writer.writeUTF(this->address);
	writer.writeShort(this->port);
	writer.writeBool(this->canCreateNewCharacter);
	writer.writeUTF(this->ticket);
}

void SelectedServerDataMessage::deserialize(BinaryReader& reader)
{
	// idc
}