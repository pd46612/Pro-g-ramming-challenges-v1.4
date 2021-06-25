#pragma once
#include "FirstName.h"
#include "MiddleName.h"
#include "LastName.h"
#include <vector>
#include <string>

class NamesCollection
{
private:
	std::vector<FirstName> firstNamesCollection;
	std::vector<MiddleName> middleNamesCollection;
	std::vector<LastName> lastNamesCollection;

	void printFirstNames();
	void printMiddleNames();
	void printLastNames();
	bool initialize();

	std::vector<std::string> splitTextLine(std::string& line);

public:	
	NamesCollection();
	~NamesCollection() {}
	
	void printNames(const std::string& namePart);
};

