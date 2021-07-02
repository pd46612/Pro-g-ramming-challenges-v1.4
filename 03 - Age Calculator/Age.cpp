#include "Age.h"
#include <iostream>
#include <ctype.h>
#include <ctime>

Age::Age(std::string& date)
{
	this->date = date;
	if (date.length() == 10 && date.at(2) == '-' && date.at(5) == '-')
	{
		if (!isdigit(date.at(0))) return;
		if (!isdigit(date.at(1))) return;
		if (!isdigit(date.at(3))) return;
		if (!isdigit(date.at(4))) return;
		if (!isdigit(date.at(6))) return;
		if (!isdigit(date.at(7))) return;
		if (!isdigit(date.at(8))) return;
		if (!isdigit(date.at(9))) return;
		countAge();
		printAgeInSeconds();
	}
	else
	{
		std::cout << "Wrong format! Closing...\n";
		return;
	}
}

void Age::countAge()
{
	time_t time = std::time(nullptr);
	tm now = {};
	localtime_s(&now, &time);
	tm birthTime = {};

	int day = stoi(date.substr(0, 2));
	int month = stoi(date.substr(3, 2));
	int year = stoi(date.substr(6, 4));
	int hour = 0;
	int minute = 0;
	int second = 0;

	birthTime.tm_year = year;
	birthTime.tm_mon = month;
	birthTime.tm_mday = day;
	birthTime.tm_hour = hour;
	birthTime.tm_min = minute;
	birthTime.tm_sec = second;

	time_t secs1 = mktime(&now), secs2 = mktime(&birthTime);
	ageInSeconds = static_cast<long int>(secs1 - secs2);
}

void Age::printAgeInSeconds()
{
	std::cout << "Your birthday is " << date << "\n";
	std::cout << "You have lived for " << ageInSeconds << " seconds!\n";
}