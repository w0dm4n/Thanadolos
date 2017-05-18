#include "BooleanByteWrapper.hpp"

char BooleanByteWrapper::setFlag(char flag, char offset, bool value)
{
	if (offset >= 8)
		throw std::invalid_argument("offset must be lesser than 8");

	return value ? (char)(flag | (1 << offset)) : (char)(flag & 255 - (1 << offset));
}

char BooleanByteWrapper::setFlag(int flag, char offset, bool value)
{
	if (offset >= 8)
		throw std::invalid_argument("offset must be lesser than 8");

	return value ? (char)(flag | (1 << offset)) : (char)(flag & 255 - (1 << offset));
}

bool BooleanByteWrapper::getFlag(char flag, char offset)
{
	if (offset >= 8)
		throw std::invalid_argument("offset must be lesser than 8");

	return (flag & (char)(1 << offset)) != 0;
}