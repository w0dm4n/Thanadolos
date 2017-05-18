#ifndef BINARY64_H
#define BINARY64_H

#include "types.h"

class Binary64
{
public:
	Binary64(uint _low = 0, uint _high = 0);

	uint div(uint n);
	void mul(uint n);
	void add(uint n);
	void bitWiseNot();

	uint low;

protected:
	uint internalHigh;

	static const char CHAR_CODE_0 = '0';
	static const char CHAR_CODE_9 = '9';
	static const char CHAR_CODE_A = 'A';
	static const char CHAR_CODE_Z = 'Z';
};


#endif 