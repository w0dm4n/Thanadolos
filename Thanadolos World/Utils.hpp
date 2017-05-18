#pragma once
#ifndef UTILS_HPP
# define UTILS_HPP
#include <time.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>

#define Split std::vector<std::string>

class Utils
{
public:
	static int getRand(int min, int max);
	static const int getIntValueFromString(const std::string);
	static std::vector<std::string> split(const std::string &s, char delim);

	template<typename Out>
	static void split(const std::string &s, char delim, Out result);
	static std::string	strToLower(std::string value);
	static long int getUnixTimestamp();
};

#endif