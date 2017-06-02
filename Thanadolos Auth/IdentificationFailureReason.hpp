#pragma once

#ifndef IDENTIFICATIONFAILUREENUM_HPP
#define IDENTIFICATIONFAILUREENUM_HPP

class IdentificationFailureReasonEnum
{
public:
	static const int BAD_VERSION = 1;
	static const int WRONG_CREDENTIALS = 2;
	static const int BANNED = 3;
	static const int KICKED = 4;
	static const int IN_MAINTENANCE = 5;
	static const int TOO_MANY_ON_IP = 6;
	static const int TIME_OUT = 7;
	static const int BAD_IPRANGE = 8;
	static const int CREDENTIALS_RESET = 9;
	static const int EMAIL_UNVALIDATED = 10;
	static const int OTP_TIMEOUT = 11;
	static const int LOCKED = 12;
	static const int SERVICE_UNAVAILABLE = 53;
	static const int EXTERNAL_ACCOUNT_LINK_REFUSED = 61;
	static const int EXTERNAL_ACCOUNT_ALREADY_LINKED = 62;
	static const int UNKNOWN_AUTH_ERROR = 99;
	static const int SPARE = 100;
};

#endif