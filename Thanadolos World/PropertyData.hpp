#pragma once
class PropertyData
{
public:
	PropertyData(std::string name, int type);
	std::string name();
	int			type();
private:
	std::string name_property;
	int type_property;
};