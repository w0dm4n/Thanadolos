#pragma once
#ifndef BOOLEANBYTEWRAPPER_HPP
#define BOOLEANBYTEWRAPPER_HPP

#include <stdexcept>

class BooleanByteWrapper
{
public:
	static char setFlag(char flag, char offset, bool value);
	static char setFlag(int flag, char offset, bool value);
	static bool getFlag(char flag, char offset);
};

#endif
