#include "IdentificationFailedMessage.hpp"
#include "BooleanByteWrapper.hpp"

IdentificationFailedMessage::IdentificationFailedMessage(
	uint _reason
)
{
	reason = _reason;
}

ushort IdentificationFailedMessage::getId()
{
	return id;
}

std::string IdentificationFailedMessage::getName()
{
	return "IdentificationFailedMessage";
}

void IdentificationFailedMessage::serialize(BinaryWriter& writer)
{
	writer.writeByte(static_cast<char>(reason));
}

void IdentificationFailedMessage::deserialize(BinaryReader& reader)
{

}