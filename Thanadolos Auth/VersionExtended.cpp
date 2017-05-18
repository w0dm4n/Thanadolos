#include "VersionExtended.hpp"

void VersionExtended::initVersionExtended(char _install, char _technology)
{
	install = _install;
	technology = _technology;
}

ushort VersionExtended::getId()
{
	return id;
}

std::string VersionExtended::getName()
{
	return "VersionExtended";
}
void VersionExtended::serialize(BinaryWriter& writer)
{
	Version::serialize(writer);

	writer.writeByte(install);
	writer.writeByte(technology);
}

void VersionExtended::deserialize(BinaryReader& reader)
{
	Version::deserialize(reader);

	install = reader.readByte();
	technology = reader.readByte();
}