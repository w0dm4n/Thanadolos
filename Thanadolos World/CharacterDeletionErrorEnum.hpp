#pragma once

#ifndef CHARACTERDELETIONERRORENUM_HPP
#define CHARACTERDELETIONERRORENUM_HPP

class CharacterDeletionErrorEnum
{
public:
	static const int DEL_ERR_NO_REASON = 1;
	static const int DEL_ERR_TOO_MANY_CHAR_DELETION = 2;
	static const int DEL_ERR_BAD_SECRET_ANSWER = 3;
	static const int DEL_ERR_RESTRICED_ZONE = 4;
};

#endif