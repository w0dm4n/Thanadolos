#include "Globals.h"
#include "CharacterDeletionRequestMessage.hpp"

CharacterDeletionRequestMessage::CharacterDeletionRequestMessage(int characterId, std::string secretAnswerHash)
{
	this->characterId = characterId;
	this->secretAnswerHash = secretAnswerHash;
}

CharacterDeletionRequestMessage::CharacterDeletionRequestMessage()
{

}

ushort CharacterDeletionRequestMessage::getId()
{
	return id;
}

std::string CharacterDeletionRequestMessage::getName()
{
	return "CharacterDeletionRequestMessage";
}

void CharacterDeletionRequestMessage::serialize(BinaryWriter& writer)
{
	writer.writeVarLong(this->characterId);
	writer.writeUTF(this->secretAnswerHash);
}

void CharacterDeletionRequestMessage::deserialize(BinaryReader& reader)
{
	this->characterId = reader.readVarUhLong();
	this->secretAnswerHash = reader.readUTF();
}