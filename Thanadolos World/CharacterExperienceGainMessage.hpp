#pragma once
#ifndef CHARACTEREXPERIENCEGAINMESSAGE_THANADOLOS_HPP
#define CHARACTEREXPERIENCEGAINMESSAGE_THANADOLOS_HPP

#include "imessage.h"


class CharacterExperienceGainMessage : public IMessage
{
public:
	CharacterExperienceGainMessage(int experienceCharacter, int experienceMount, int experienceGuild, int experienceIncarnation);
	CharacterExperienceGainMessage();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 6321;

	/*VARS*/
	int experienceCharacter;
	int experienceMount;
	int experienceGuild;
	int experienceIncarnation;
};


#endif