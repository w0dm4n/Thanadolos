#pragma once
#ifndef IDENTIFICATIONMESSAGE_THANADOLOS_HPP
#define IDENTIFICATIONMESSAGE_THANADOLOS_HPP

#include "imessage.h"
#include "VersionExtended.hpp" 


class IdentificationMessage : public IMessage
{
public:
	IdentificationMessage(VersionExtended version, std::string lang, ByteArray credentials, int serverId, bool autoconnect, bool useCertificate, bool useLoginToken, int sessionOptionalSalt, std::vector<uint> failedAttempts);
	IdentificationMessage::IdentificationMessage();
	ushort getId();
	std::string getName();
	void serialize(BinaryWriter& writer);
	void deserialize(BinaryReader& reader);

	static const int id = 4;

	/*VARS*/
	VersionExtended version;
	std::string lang;
	ByteArray credentials;
	int serverId;
	bool autoconnect;
	bool useCertificate;
	bool useLoginToken;
	int sessionOptionalSalt;
	std::vector<uint> failedAttempts;
};


#endif