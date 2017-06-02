#include "Version.hpp"

void Version::initVersion(char _major, char _minor, char _release, int _revision, char _patch, char _buildType)
{
	major = _major;
	minor = _minor;
	release = _release;
	revision = _revision;
	patch = _patch;
	buildType = _buildType;
}

ushort Version::getId()
{
	return id;
}

std::string Version::getName()
{
	return "Version";
}
void Version::serialize(BinaryWriter& writer)
{
	writer.writeByte(major);
	writer.writeByte(minor);
	writer.writeByte(release);
	writer.writeInt(revision);
	writer.writeByte(patch);
	writer.writeByte(buildType);
}

void Version::deserialize(BinaryReader& reader)
{
	major = reader.readByte();
	minor = reader.readByte();
	release = reader.readByte();
	revision = reader.readInt();
	patch = reader.readByte();
	buildType = reader.readByte();
}