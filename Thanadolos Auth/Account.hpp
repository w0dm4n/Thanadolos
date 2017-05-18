#pragma once

#ifndef ACCOUNT_HPP
# define ACCOUNT_HPP

#pragma comment(lib, "campd.lib")
#include <camp/camptype.hpp>
#include <camp/class.hpp>
#include <SQLAPI.h>

#include <iostream>
class AccountRecord
{
public:
	static void declareRecord()
	{
		camp::Class::declare<AccountRecord>("AccountRecord")
			.constructor0()
			.property("id", &AccountRecord::getId, &AccountRecord::setId)
			.property("account", &AccountRecord::getAccount, &AccountRecord::setAccount)
			.property("password", &AccountRecord::getPassword, &AccountRecord::setPassword)
			.property("level", &AccountRecord::getLevel, &AccountRecord::setLevel)
			.property("nickname", &AccountRecord::getNickname, &AccountRecord::setNickname)
			.property("banned", &AccountRecord::isBanned, &AccountRecord::setBanned)
			.property("question", &AccountRecord::getSecretQuestion, &AccountRecord::setSecretAnswer)
			.property("answer", &AccountRecord::getSecretAnswer, &AccountRecord::setSecretQuestion);
	}
	AccountRecord() { }

	int getId() const { return this->Id; }
	void setId(int id) { this->Id = id; }

	std::string getAccount() const { return this->AccountRow; }
	void setAccount(std::string account) { this->AccountRow = account; }


	std::string getPassword() const { return this->Password; }
	void setPassword(std::string password) { this->Password = password; }

	std::string getSecretQuestion() const { return this->SecretQuestion; }
	void setSecretQuestion(std::string secretQuestion) { this->SecretQuestion = secretQuestion; }

	std::string getSecretAnswer() const { return this->SecretAnswer; }
	void setSecretAnswer(std::string secretAnswer) { this->SecretAnswer = secretAnswer; }

	int getLevel() const { return this->Level; }
	void setLevel(int level) { this->Level = level; }

	std::string getNickname() const { return this->Nickname; };
	void setNickname(std::string nickname) { this->Nickname = nickname; }

	int isBanned() const { return this->Banned; }
	void setBanned(bool banned) { this->Banned = banned; }

private:
	int Id;
	std::string AccountRow;
	std::string Password;
	std::string SecretQuestion;
	std::string SecretAnswer;
	int Level;
	std::string Nickname;
	bool Banned;
};

CAMP_TYPE(AccountRecord)

#endif
