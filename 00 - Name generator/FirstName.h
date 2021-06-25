#pragma once
#include <vector>
#include <string>
class FirstName
{
private:
	friend class NamesCollection;
	std::string name;
	char gender;
public:
	FirstName(std::vector<std::string>& names);
};

