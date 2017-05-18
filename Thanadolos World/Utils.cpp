#include "Globals.h"
#include "Utils.hpp"

int			Utils::getRand(int min, int max)
{
	int value = (rand() + time(NULL)) % max;
	value = (value < min) ? min : value;
	return (value);
}

const int Utils::getIntValueFromString(const std::string str)
{
	int i = 0, ascii = 0;

	while (i < str.length())
		ascii += (int) str.c_str()[i++];
	return ascii;
}

template<typename Out>
void Utils::split(const std::string &s, char delim, Out result) {
	std::stringstream ss;
	ss.str(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		*(result++) = item;
	}
}

std::vector<std::string> Utils::split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	Utils::split(s, delim, std::back_inserter(elems));
	return elems;
}

std::string		Utils::strToLower(std::string value)
{
	std::string newValue;
	int i = 0;
	while (i < value.length())
	{
		if (value[i] >= 65 && value[i] <= 90)
			newValue += (value[i] + 32);
		else
			newValue += value[i];
		i++;
	}
	return (newValue);
}

long int Utils::getUnixTimestamp()
{
	time_t t = std::time(0);
	long int now = static_cast<long int> (t);
	return now;
}