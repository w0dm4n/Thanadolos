#ifndef CAWOTTESRV_BINARYWRITER_H
#define CAWOTTESRV_BINARYWRITER_H

#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include "types.h"
#include "ByteOrder.hpp"

class BinaryWriter
{
public:
	BinaryWriter(ByteArray& buffer);

	unsigned int index();
	void setIndex(uint index);

	void writeByte(char data);
	void writeBytes(ByteArray data, bool writeSize = true);
	void writeShort(short data);
	void writeUShort(ushort data);
	void writeInt(int data);
	void writeUInt(uint data);
	void writeLong(long data);
	void writeULong(ulong data);
	void writeDouble(double data);
	void writeUTF(const char *data);
	void writeUTF(std::string data);
	void writeUTFBytes(const char *data, size_t length);
	void writeBool(bool data);
	void writeVarInt(int data);
	void writeVarShort(short data);
	void writeVarLong(double data);
	void writeInt32(uint data);


private:
	ByteArray& _buffer;
	uint _index;

	template<class T>
	void write(const T& data);

	template<class T>
	void write(const std::vector<T>& data, bool writeSize = true);

	const int INT_SIZE = 32;
	const int SHORT_SIZE = 16;
	const int SHORT_MIN_VALUE = -32768;
	const int SHORT_MAX_VALUE = 32767;
	const int UNGISNED_SHORT_MAX_VALUE = 65536;
	const int CHUNK_BIT_SIZE = 7;
	const int MAX_ENCODING_LENGTH = std::ceil(INT_SIZE / CHUNK_BIT_SIZE);
	const uchar MASK_10000000 = 128;
	const uchar MASK_01111111 = 127;
};

#endif#pragma once
