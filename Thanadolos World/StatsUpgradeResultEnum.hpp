#pragma once

#ifndef STATSUPGRADERESULTENUM_HPP
#define STATSUPGRADERESULTENUM_HPP

class StatsUpgradeResultEnum
{
public:
	static const int NONE = -1;
	static const int SUCCESS = 0;
	static const int RESTRICTED = 1;
	static const int GUEST = 2;
	static const int IN_FIGHT = 3;
	static const int NOT_ENOUGH_POINT = 4;
};

#endif