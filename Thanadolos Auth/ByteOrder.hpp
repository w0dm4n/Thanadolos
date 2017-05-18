#pragma once
#ifndef BYTEORDER_HPP
#define BYTEORDER_HPP

#include "types.h"

class ByteOrder
{
public:
	static ushort swap(ushort value);
	static short  swap(short value);
	static uint   swap(uint value);
	static int    swap(int value);
	static ulong  swap(ulong value);
	static long   swap(long value);
};


#endif