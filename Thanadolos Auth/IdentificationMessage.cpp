#include "IdentificationMessage.hpp"

IdentificationMessage::IdentificationMessage(VersionExtended version, std::string lang, ByteArray credentials, int serverId, bool autoconnect, bool useCertificate, bool useLoginToken, int sessionOptionalSalt, std::vector<uint> failedAttempts)
{
	this->version = version;
	this->lang = lang;
	this->credentials = credentials;
	this->serverId = serverId;
	this->autoconnect = autoconnect;
	this->useCertificate = useCertificate;
	this->useLoginToken = useLoginToken;
	this->sessionOptionalSalt = sessionOptionalSalt;
	this->failedAttempts = failedAttempts;

}

IdentificationMessage::IdentificationMessage()
{

}

ushort IdentificationMessage::getId()
{
	return id;
}

std::string IdentificationMessage::getName()
{
	return "IdentificationMessage";
}

void IdentificationMessage::serialize(BinaryWriter& writer)
{
	int _loc2_ = 0;
	_loc2_ = BooleanByteWrapper::setFlag(_loc2_, 0, this->autoconnect);	_loc2_ = BooleanByteWrapper::setFlag(_loc2_, 1, this->useCertificate);	_loc2_ = BooleanByteWrapper::setFlag(_loc2_, 2, this->useLoginToken);	writer.writeByte(_loc2_);	this->version.serialize(writer);
	writer.writeUTF(this->lang);	writer.writeShort(this->serverId);	writer.writeVarLong(this->sessionOptionalSalt);	writer.writeShort(this->failedAttempts.size());	int _loc4_ = 0;
	while (_loc4_ < this->failedAttempts.size())	{		writer.writeVarShort(this->failedAttempts[_loc4_]);		_loc4_++;	}
}

void IdentificationMessage::deserialize(BinaryReader& reader)
{
	{		int _loc7_ = 0;
		int _loc8_ = 0;
		int _loc2_ = reader.readByte();		this->autoconnect = BooleanByteWrapper::getFlag(_loc2_, 0);		this->useCertificate = BooleanByteWrapper::getFlag(_loc2_, 1);		this->useLoginToken = BooleanByteWrapper::getFlag(_loc2_, 2);		this->version.deserialize(reader);		this->lang = reader.readUTF();		int _loc3_ = reader.readVarInt();		int _loc4_ = 0;
		while (_loc4_ < _loc3_)		{			_loc7_ = reader.readByte();			this->credentials.push_back(_loc7_);			_loc4_++;		}		this->serverId = reader.readShort();		this->sessionOptionalSalt = reader.readVarLong();		int _loc5_ = reader.readUShort();		int _loc6_ = 0;
		while (_loc6_ < _loc5_)		{			_loc8_ = reader.readVarUhShort();			this->failedAttempts.push_back(_loc8_);			_loc6_++;		}	}
}