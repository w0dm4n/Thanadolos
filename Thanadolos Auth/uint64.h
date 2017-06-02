#ifndef SRV_UINT64_H
#define SRV_UINT64_H

#include "binary64.h"
#include <string>

class UInt64 : public Binary64
{
public:
	UInt64(uint _low = 0, uint _high = 0);

	static UInt64 fromNumber(double value);
	static UInt64 parseUInt64(std::string str, uint radix = 0);

	void setHigh(uint high);
	uint getHigh();

	double toNumber();
	std::string toString(uint radix = 10);
};


#endif