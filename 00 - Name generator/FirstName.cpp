#include "FirstName.h"

FirstName::FirstName(std::vector<std::string>& names)
{
	this->name = names[0];
	this->gender = names[1][0];
}
