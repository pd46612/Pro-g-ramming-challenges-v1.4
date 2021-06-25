#pragma once
#include <string>
class MiddleName
{
private:
	friend class NamesCollection;
	std::string name;
public:
	MiddleName(std::string& name);
};