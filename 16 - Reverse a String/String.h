#pragma once
#include <string>

class String
{
private:
	std::string string;
	std::string reversed;
	std::string randomized;

public:
	String(std::string s);
	~String() {}
	
	void reverse();
	void randomize();
	void print(std::string printMethod);
};

