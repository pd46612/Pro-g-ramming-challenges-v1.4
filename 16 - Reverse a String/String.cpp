#include "String.h"
#include <iostream>
#include <list>
#include <random>

String::String(std::string s)
{
	this->string = s;
	reverse();
	randomize();
}

void String::reverse()
{
	std::string temp(string);
	std::reverse(temp.begin(), temp.end());
	reversed = temp;
}

void String::randomize()
{
	randomized = string;
	std::random_device r;
	std::default_random_engine generator(r());
	std::shuffle(std::begin(randomized), std::end(randomized), generator);
}

void String::print(std::string printMethod)
{
	if (printMethod == "string") std::cout << string;
	else if (printMethod == "reversed") std::cout << reversed;
	else if (printMethod == "randomized") std::cout << randomized;
	else std::cout << "Wrong print method";
}
