#pragma once

#ifndef CHATACTIVABLECHANNELSENUM_HPP
#define CHATACTIVABLECHANNELSENUM_HPP

class ChatActivableChannelsEnum
{
public:
	static const int CHANNEL_GLOBAL = 0;
	static const int 	CHANNEL_TEAM = 1;
	static const int 	CHANNEL_GUILD = 2;
	static const int 	CHANNEL_ALLIANCE = 3;
	static const int 	CHANNEL_PARTY = 4;
	static const int 	CHANNEL_SALES = 5;
	static const int 	CHANNEL_SEEK = 6;
	static const int 	CHANNEL_NOOB = 7;
	static const int 	CHANNEL_ADMIN = 8;
	static const int 	CHANNEL_ADS = 12;
	static const int 	CHANNEL_ARENA = 13;
	static const int 	PSEUDO_CHANNEL_PRIVATE = 9;
	static const int 	PSEUDO_CHANNEL_INFO = 10;
	static const int PSEUDO_CHANNEL_FIGHT_LOG = 11;
};

#endif