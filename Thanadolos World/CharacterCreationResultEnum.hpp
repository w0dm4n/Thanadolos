#pragma once

#ifndef CHARACTERCREATIONRESULT_HPP
#define CHARACTERCREATIONRESULT_HPP

class CharacterCreationResultEnum
{
public:
	static const int OK = 0;
	static const int 	ERR_NO_REASON = 1;
	static const int 	ERR_INVALID_NAME = 2;
	static const int 	ERR_NAME_ALREADY_EXISTS = 3;
	static const int 	ERR_TOO_MANY_CHARACTERS = 4;
	static const int 	ERR_NOT_ALLOWED = 5;
	static const int 	ERR_NEW_PLAYER_NOT_ALLOWED = 6;
	static const int 	ERR_RESTRICED_ZONE = 7;
};

#endif