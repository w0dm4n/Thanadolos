#include "Config.hpp"

std::string Config::getCorrectValue(std::string value)
{
	std::string newValue;
	char *str = (char*) value.c_str();
	int len = strlen(str) - 1;
	int i = 1;

	while (i < (len - 1))
		newValue += str[i++];
	return newValue;
}

Config::Config(std::string file_name)
{
	std::ifstream t(file_name);
	std::stringstream buffer;

	if (t)
	{
		buffer << t.rdbuf();
		std::istringstream is_file(buffer.str());

		std::string line;
		while (std::getline(is_file, line))
		{
			std::istringstream is_line(line);
			std::string key;
			if (std::getline(is_line, key, '('))
			{
				std::string value;
				if (std::getline(is_line, value))
				{
					value = this->getCorrectValue(value);
					if (!key.empty() && !value.empty())
					{
						std::pair<std::string, std::string> data;
						data.first = key;
						data.second = value;
						this->datas.push_back(data);
					}
				}
			}
		}
		Logger::Infos("Configuration file successfully loaded !", 11);
	}
	else
		throw WrongConfigFile();
}

std::string Config::getData(std::string key)
{
	std::lock_guard<std::mutex> locker(this->m);
	std::list<std::pair<std::string, std::string>>::iterator iter = this->datas.begin();
	std::list<std::pair<std::string, std::string>>::iterator end = this->datas.end();
	while (iter != this->datas.end())
	{
		std::pair<std::string, std::string> data = *iter;
		if (data.first == key)
			return data.second;
		++iter;
	}
	return "";
}