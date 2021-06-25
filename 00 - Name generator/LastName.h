#pragma once
#include <string>
class LastName
{
private:
	friend class NamesCollection;
	std::string name;
public:
	LastName(std::string& name);
};