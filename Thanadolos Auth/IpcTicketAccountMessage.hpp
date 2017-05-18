#pragma once
#pragma once
#ifndef IPCTICKETACCOUNTMESSAGE_HPP
#define IPCTICKETACCOUNTMESSAGE_HPP

#include "IMessage.h"

class IpcTicketAccountMessage : public IMessage
{
public:
	IpcTicketAccountMessage(
		std::string ticket,
	int accountId,
	std::string account,
	std::string password,
	std::string secret_question,
	std::string secret_answer,
	int level,
	std::string nickname,
	bool banned);

	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	IpcTicketAccountMessage() { }

	static const int id = 666;

	/* VARIABLES */
	std::string ticket;
	int accountId;
	std::string account;
	std::string password;
	std::string secret_question;
	std::string secret_answer;
	int level;
	std::string nickname;
	bool banned;
};


#endif