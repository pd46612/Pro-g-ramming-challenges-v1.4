#include "BMI.h"
#include <iostream>
#include <iomanip>

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
	if (bmi < 16) result = "Underweight (Severe thinness)";
	else if (bmi >= 16 && bmi < 17) result = "Underweight (Moderate thinness)";
	else if (bmi >= 17 && bmi < 18.5f) result = "Underweight (Mild thinness)";
	else if (bmi >= 18.5 && bmi < 25) result = "Normal range";
	else if (bmi >= 25 && bmi < 30) result = "Overweight (Pre-obese)";
	else if (bmi >= 30 && bmi < 35) result = "Overweight (Class I)";
	else if (bmi >= 35 && bmi < 40) result = "Overweight (Class II)";
	else if (bmi >= 40) result = "Overweight (Class III)";
}

void BMI::print()
{
	std::cout << "Your BMI is: " << std::fixed << std::setprecision(2) << bmi << " kg/m^2\n";
	std::cout << "You're in '" << result << "' category\n";
}


