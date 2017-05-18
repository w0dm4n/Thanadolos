#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include "Logger.hpp"
#include <list>
#include <mutex>
#include <exception>
class Config
{
public:
	Config(std::string filename);
	std::string getData(std::string key);
	std::string getCorrectValue(std::string value);
	struct WrongConfigFile : public std::exception {
		WrongConfigFile() {  }
		virtual const char* what() const throw() {
			return "The auth server can't load the config file";
		}
	};
private:
	std::list<std::pair<std::string, std::string>> datas;
	std::mutex m;
};