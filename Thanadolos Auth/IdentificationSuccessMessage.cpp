#include "IdentificationSuccessMessage.hpp"
#include "BooleanByteWrapper.hpp"

IdentificationSuccessMessage::IdentificationSuccessMessage(
	std::string _login,
	std::string _nickname,
	uint _accountId,
	uint _communityId,
	bool _hasRights,
	std::string _secretQuestion,
	double _accountCreation,
	double _subscriptionElapsedDuration,
	double _subscriptionEndDate,
	bool _wasAlreadyConnected,
	uint _havenbagAvailableRoom
)
{
	login = _login;
	nickname = _nickname;
	accountId = _accountId;
	communityId = _communityId;
	hasRights = _hasRights;
	secretQuestion = _secretQuestion;
	accountCreation = _accountCreation;
	subscriptionElapsedDuration = _subscriptionElapsedDuration;
	subscriptionEndDate = _subscriptionEndDate;
	wasAlreadyConnected = _wasAlreadyConnected;
	havenbagAvailableRoom = _havenbagAvailableRoom;
}

ushort IdentificationSuccessMessage::getId()
{
	return id;
}

std::string IdentificationSuccessMessage::getName()
{
	return "IdentificationSuccessMessage";
}

void IdentificationSuccessMessage::serialize(BinaryWriter& writer)
{
	char box0 = 0;
	box0 = BooleanByteWrapper::setFlag(box0, 0, hasRights);
	box0 = BooleanByteWrapper::setFlag(box0, 1, wasAlreadyConnected);
	writer.writeByte(box0);
	writer.writeUTF(login);
	writer.writeUTF(nickname);
	writer.writeInt(accountId);
	writer.writeByte(static_cast<char>(communityId));
	writer.writeUTF(secretQuestion);
	writer.writeDouble(accountCreation);
	writer.writeDouble(subscriptionElapsedDuration);
	writer.writeDouble(subscriptionEndDate);
	writer.writeByte(static_cast<char>(havenbagAvailableRoom));
}

void IdentificationSuccessMessage::deserialize(BinaryReader& reader)
{

}