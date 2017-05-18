#include "uint64.h"
#include <stdexcept>
#include <cmath>

UInt64::UInt64(uint _low, uint _high) :
	Binary64(_low, _high)
{
}

UInt64 UInt64::fromNumber(double value)
{
	return UInt64(static_cast<uint>(value), static_cast<uint>(std::floor(value / 4294967296)));
}

UInt64 UInt64::parseUInt64(std::string str, uint radix)
{
	throw std::logic_error("function not implemented");
	return UInt64();
}

void UInt64::setHigh(uint high)
{
	internalHigh = high;
}

uint UInt64::getHigh()
{
	return internalHigh;
}

double UInt64::toNumber()
{
	return (getHigh() * 4294967296) + low;
}

std::string UInt64::toString(uint radix)
{
	throw std::logic_error("function not implemented");
	return "";
}