#pragma once
#ifndef BOOLEANBYTEWRAPPER_HPP
#define BOOLEANBYTEWRAPPER_HPP

#include <stdexcept>
#include "types.h"

class BooleanByteWrapper
{
public:
	static uint setFlag(uint flag, uint offset, bool value);
	static bool getFlag(uint flag, uint offset);
};

#endif
