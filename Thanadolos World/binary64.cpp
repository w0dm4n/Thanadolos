#include "Globals.h"
#include "binary64.hpp"

Binary64::Binary64(uint _low, uint _high)
{
	low = _low;
	internalHigh = _high;
}

uint Binary64::div(uint n)
{
	uint modHigh = internalHigh % n;
	uint mod = ((low % n) + (modHigh * 6)) % n;
	internalHigh = internalHigh / n;
	double newLow = ((modHigh * 4294967296) + low) / n;
	internalHigh = internalHigh + static_cast<uint>(newLow / 4294967296);
	low = static_cast<uint>(newLow);
	return mod;
}

void Binary64::mul(uint n)
{
	double newLow = static_cast<double>(low * n);
	internalHigh = internalHigh * n;
	internalHigh = internalHigh + static_cast<uint>(newLow / 4294967296);
	low = low * n;
}

void Binary64::add(uint n)
{
	double newLow = static_cast<double>(low + n);
	internalHigh = internalHigh + static_cast<uint>(newLow / 4294967296);
	low = static_cast<uint>(newLow);
}

void Binary64::bitWiseNot()
{
	low = ~low;
	internalHigh = ~internalHigh;
}