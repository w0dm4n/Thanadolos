#ifndef SRV_INT64_H
#define SRV_INT64_H

#include "binary64.h"
#include <string>

class Int64 : public Binary64
{
public:
	Int64(uint _low = 0, uint _high = 0);

	static Int64 fromNumber(double value);
	static Int64 parseInt64(std::string str, uint radix = 0);

	void setHigh(uint high);
	uint getHigh();

	double toNumber();
	std::string toString(uint radix = 10);
};


#endif