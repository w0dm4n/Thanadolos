#include "ByteOrder.hpp"

ushort ByteOrder::swap(ushort value)
{
	return static_cast<ushort>(((value >> 8) & 0x00FF) | ((value << 8) & 0xFF00));
}

short ByteOrder::swap(short value)
{
	return static_cast<short>(swap(static_cast<ushort>(value)));
}

uint ByteOrder::swap(uint value)
{
	return ((value >> 24) & 0x000000FF) | ((value >> 8) & 0x0000FF00)
		| ((value << 8) & 0x00FF0000) | ((value << 24) & 0xFF000000);
}

int ByteOrder::swap(int value)
{
	return static_cast<int>(swap(static_cast<uint>(value)));
}

ulong ByteOrder::swap(ulong value)
{
	return   (value >> 56) | ((value << 40) & 0x00FF000000000000)
		| ((value << 24) & 0x0000FF0000000000) | ((value << 8) & 0x000000FF00000000)
		| ((value >> 8) & 0x00000000FF000000) | ((value >> 24) & 0x0000000000FF0000)
		| ((value >> 40) & 0x000000000000FF00) | (value << 56);
}

long ByteOrder::swap(long value)
{
	return static_cast<long>(swap(static_cast<ulong>(value)));
}