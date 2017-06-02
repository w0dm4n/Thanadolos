#pragma once

#ifndef SERVERSTATUS_HPP
#define SERVERSTATUS_HPP

class ServerStatusEnum
{
public:
	static const int STATUS_UNKNOWN = 0;
	static const int OFFLINE = 1;
	static const int STARTING = 2;
	static const int ONLINE = 3;
	static const int NO_JOIN = 4;
	static const int SAVING = 5;
	static const int STOPING = 6;
	static const int FULL = 7;
};

#endif