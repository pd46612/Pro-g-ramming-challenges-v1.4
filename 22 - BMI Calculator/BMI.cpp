#include "BMI.h"
#include <iostream>

BMI::BMI(int age, float height, float weight)
{
	this->age = age;
	this->height = height / 100;
	this->weight = weight;
	calculate();
	interpret();
	print();
}

void BMI::calculate()
{
	bmi = weight / (height * height);
}

void BMI::interpret()
{
	
}

void BMI::print()
{
	std::cout << "Your BMI is: " << bmi << "\n";
}


