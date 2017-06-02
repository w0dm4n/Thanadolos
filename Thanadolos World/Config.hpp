#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <list>
#include <mutex>
#include <exception>
#include "Logger.hpp"
class Config
{
public:
	Config(std::string filename);
	std::string getData(std::string key);
	std::string getCorrectValue(std::string value);
	struct WrongConfigFile : public std::exception {
		WrongConfigFile() {  }
		virtual const char* what() const throw() {
			return "The world server can't load the config file";
		}
	};
private:
	std::list<std::pair<std::string, std::string>> datas;
	std::mutex m;
};