#pragma once
#include <string>

class BMI
{
private:
	int age;
	float height;
	float weight;
	float bmi;
	std::string result;

	void calculate();
	void interpret();
	void print();

public:
	BMI(int age, float height, float weight);
};

