#pragma once
#ifndef GAMEROLEPLAYSHOWACTORMESSAGE_THANADOLOS_HPP
#define GAMEROLEPLAYSHOWACTORMESSAGE_THANADOLOS_HPP

#include "imessage.h"
#include "GameRolePlayActorInformations.hpp" 


class GameRolePlayShowActorMessage : public IMessage
{
public:
	GameRolePlayShowActorMessage(GameRolePlayActorInformations* informations);
	GameRolePlayShowActorMessage();
	~GameRolePlayShowActorMessage();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 5632;

	/*VARS*/
	GameRolePlayActorInformations *informations;
};


#endif