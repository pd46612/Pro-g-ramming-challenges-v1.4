#include <iostream>
#include "Age.h"

int main()
{
    std::string birthday;
    std::cout << "Enter your birthday date in DD-MM-YYYY form: \n";
    std::cin >> birthday;
    Age age(birthday);
    return 0;
}