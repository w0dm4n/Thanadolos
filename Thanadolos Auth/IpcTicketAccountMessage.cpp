#include "IpcTicketAccountMessage.hpp"
#include "Logger.hpp"

IpcTicketAccountMessage::IpcTicketAccountMessage(
	std::string ticket,
	int accountId,
	std::string account,
	std::string password,
	std::string secret_question,
	std::string secret_answer,
	int level,
	std::string nickname,
	bool banned)
{
	this->ticket = ticket;
	this->accountId = accountId;
	this->account = account;
	this->password = password;
	this->secret_question = secret_question;
	this->secret_answer = secret_answer;
	this->level = level;
	this->nickname = nickname;
	this->banned = banned;
}

ushort IpcTicketAccountMessage::getId()
{
	return id;
}

std::string IpcTicketAccountMessage::getName()
{
	return "IpcTicketAccountMessage";
}

void IpcTicketAccountMessage::serialize(BinaryWriter& writer)
{
	writer.writeUTF(this->ticket);
	writer.writeInt(this->accountId);
	writer.writeUTF(this->account);
	writer.writeUTF(this->password);
	writer.writeUTF(this->secret_question);
	writer.writeUTF(this->secret_answer);
	writer.writeInt(this->level);
	writer.writeUTF(this->nickname);
	writer.writeBool(this->banned);
}

void IpcTicketAccountMessage::deserialize(BinaryReader& reader)
{
	this->ticket = reader.readUTF();
	this->accountId = reader.readInt();
	this->account = reader.readUTF();
	this->password = reader.readUTF();
	this->secret_question = reader.readUTF();
	this->secret_answer = reader.readUTF();
	this->level = reader.readInt();
	this->nickname = reader.readUTF();
	this->banned = reader.readBool();
}