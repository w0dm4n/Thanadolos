#include "Globals.h"
#include "TextInformationMessage.hpp"

TextInformationMessage::TextInformationMessage(int msgType, int msgId, std::vector<std::string> parameters)
{
	this->msgType = msgType;
	this->msgId = msgId;
	this->parameters = parameters;

}

TextInformationMessage::TextInformationMessage()
{

}

ushort TextInformationMessage::getId()
{
	return id;
}

std::string TextInformationMessage::getName()
{
	return "TextInformationMessage";
}

void TextInformationMessage::serialize(BinaryWriter& writer)
{
	writer.writeByte(this->msgType);	writer.writeVarShort(this->msgId);	writer.writeShort(this->parameters.size());	int _loc2_ = 0;
	while (_loc2_ < this->parameters.size())	{		writer.writeUTF(this->parameters[_loc2_]);		_loc2_++;	}
}

void TextInformationMessage::deserialize(BinaryReader& reader)
{
	{		std::string _loc4_;
		this->msgType = reader.readByte();		this->msgId = reader.readVarUhShort();		int _loc2_ = reader.readUnsignedShort();		int _loc3_ = 0;
		while (_loc3_ < _loc2_)		{			_loc4_ = reader.readUTF();			this->parameters.push_back(_loc4_);			_loc3_++;		}	}
}