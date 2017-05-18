#include "Packet.hpp"

Packet::Packet()
{
}

Packet::~Packet()
{
}

ushort Packet::id()
{
	return _id;
}

uint Packet::length()
{
	return _length;
}

ByteArray Packet::data()
{
	return _data;
}

void Packet::serialize(IMessage& message, ByteArray& buffer)
{
	BinaryWriter writer(buffer);
	BinaryWriter messageWriter(_data);
	message.serialize(messageWriter);

	_id = message.getId();
	_length = static_cast<uint>(_data.size());
	_lengthType = computeLengthType(_length);
	_header = computeHeader(_id, _lengthType);

	if (_header == 0)
	{
		//throw std::logic_error("header must be non null");
	}

	writer.writeShort(_header);

	switch (_lengthType)
	{
	case 1:
		writer.writeByte(static_cast<char>(_length));
		break;
	case 2:
		writer.writeUShort(static_cast<ushort>(_length));
		break;
	case 3:
		// TODO: Write for 3 bytes length
		break;
	default:
		break;
	}

	writer.writeBytes(_data, false);
}

bool Packet::deserialize(ByteArray& buffer)
{
	_header = 0;
	_id = 0;
	_lengthType = 0;
	_length = 0;
	_data.clear();

	BinaryReader reader(buffer);
	uint countReadedBytes = 0;

	if (reader.bytesAvailable() < sizeof(_header))
	{
		return false;
	}

	_header = reader.readUShort();
	_id = getMessageId(_header);
	_lengthType = getMessageLengthType(_header);
	countReadedBytes += sizeof(_header);

	if (reader.bytesAvailable() < _lengthType)
	{
		return false;
	}

	_length = getMessageLength(_lengthType, reader);
	countReadedBytes += _lengthType;

	if (reader.bytesAvailable() < _length)
	{
		return false;
	}

	_data = reader.readBytes(_length);
	countReadedBytes += _length;

	buffer.erase(buffer.begin(), buffer.begin() + countReadedBytes);

	return true;
}

ushort Packet::getMessageId(ushort header)
{
	return header >> 2;
}

ushort Packet::getMessageLengthType(ushort header)
{
	return static_cast<ushort>(header & 3);
}

uint Packet::getMessageLength(ushort lengthType, BinaryReader& reader)
{
	uint length = 0;

	switch (lengthType)
	{
	case 1:
		length = static_cast<uint>(reader.readByte());
		break;
	case 2:
		length = reader.readUShort();
		break;
	case 3:
		length = static_cast<uint>(
			((reader.readByte() & 255) << 16) +
			((reader.readByte() & 255) << 8) +
			(reader.readByte() & 255));
		break;
	default:
		break;
	}

	return length;
}

ushort Packet::computeLengthType(uint length)
{
	if (length > 65535)
		return 3;
	if (length > 255)
		return 2;
	if (length > 0)
		return 1;

	return 0;
}

ushort Packet::computeHeader(ushort id, ushort lengthType)
{
	return id << 2 | lengthType;
}