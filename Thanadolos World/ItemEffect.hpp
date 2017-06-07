#pragma once

class ItemEffect
{
public:
	ItemEffect(std::string effect);
	void parseEffect(std::string effect);
private:
	int				effectId;
	std::string		effectType;
	int				firstValue;
	int				secondValue;
};