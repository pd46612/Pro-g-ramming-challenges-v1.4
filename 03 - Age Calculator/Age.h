#pragma once
#include <string>
class Age
{
private:
	std::string date;
	long int ageInSeconds = 0;

	void countAge();
	void printAgeInSeconds();

public:
	Age(std::string&);
	~Age() {}
};

