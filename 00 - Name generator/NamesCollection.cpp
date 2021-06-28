#include "NamesCollection.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <random>

void NamesCollection::printFirstNames()
{
	for (auto& s : firstNamesCollection)
	{
		std::cout << s.name << " " << s.gender << "\n";
	}
}

void NamesCollection::printMiddleNames()
{
	for (auto& s : middleNamesCollection)
	{
		std::cout << s.name << "\n";
	}
}

void NamesCollection::printLastNames()
{
	for (auto& s : lastNamesCollection)
	{
		std::cout << s.name << "\n";
	}
}

NamesCollection::NamesCollection()
{
	initialize();
}

std::vector<std::string> NamesCollection::splitTextLine(std::string& line)
{
	std::stringstream ss(line);
	std::string s;
	std::vector<std::string> out;

	while (std::getline(ss, s, ' '))
	{
		out.push_back(s);
	}
	return out;
}

bool NamesCollection::initialize()
{
	short fileStructurePart = 0;
	std::ifstream file("names.txt");
	std::string line;
	if (file.is_open())
	{
		while (std::getline(file, line))
		{
			if (line == "[first names]") fileStructurePart = 1;
			else if (line == "[middle names]") fileStructurePart = 2;
			else if (line == "[last names]") fileStructurePart = 3;
			else
			{
				switch (fileStructurePart)
				{
				case 1:
				{
					std::vector<std::string> names = splitTextLine(line);
					firstNamesCollection.push_back(FirstName::FirstName(names));
					break;
				}
				case 2:
				{
					middleNamesCollection.push_back(MiddleName::MiddleName(line));
					break;
				}
				case 3:
				{
					lastNamesCollection.push_back(LastName::LastName(line));
					break;
				}
				default:
				{
					std::cout << "Choose correct option!\n";
				}
				}
			}
		}
	}
	else
	{
		std::cout << "Unable to open file!" << "\n";
		return false;
	}
	return true;
}

void NamesCollection::printNames(const std::string& namePart)
{
	if (namePart == "firstNames") printFirstNames();
	else if (namePart == "middleNames") printMiddleNames();
	else if (namePart == "lastNames") printLastNames();
}

void NamesCollection::generate(const short amountToGenerate, const bool ifMiddle)
{
	std::default_random_engine generator;
	std::uniform_int_distribution<int> firstNameDistribution(0, firstNamesCollection.size() - 1);
	std::uniform_int_distribution<int> middleNameDistribution(0, middleNamesCollection.size() - 1);
	std::uniform_int_distribution<int> lastNameDistribution(0, lastNamesCollection.size() - 1);
	if (ifMiddle)
	{
		for (size_t i = 0; i < amountToGenerate; i++)
		{
			std::cout << firstNamesCollection[firstNameDistribution(generator)].name << " " << middleNamesCollection[middleNameDistribution(generator)].name <<
				" " << lastNamesCollection[lastNameDistribution(generator)].name << "\n";
		}
	}
	else
	{
		for (size_t i = 0; i < amountToGenerate; i++)
		{
			std::cout << firstNamesCollection[firstNameDistribution(generator)].name << " " << lastNamesCollection[lastNameDistribution(generator)].name << "\n";
		}
	}
}
