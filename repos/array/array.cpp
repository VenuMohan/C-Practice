// array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    std::string employees[] = { "Shaurya", "Bhuvana" , "Anand" };

    // get element of array based on index
    std::cout << employees[0] << std::endl;

    // get len of array
    std::cout << employees->length() << std::endl;

    // append the first element
    std::cout << employees->append("Manik") << std::endl;
    std::cout << employees->length() << std::endl;

    // inserts at the nth byte
    employees->insert(5, "Abhishikt");
    for (std::string str : employees)
    {
        std::cout << str << std::endl;
    }
    std::cout << employees->length() << std::endl;

    employees->erase(2);
    for (int i = 0; i < employees->length(); i++)
    {
        std::cout << employees[i] << std::endl;
    }

    // change array element
    employees[2] = "Mouli";
    std::cout << employees[2] << std::endl;

    // get size of array
    std::cout << "The array is" << std::endl;
    for (std::string str : employees)
    {
        std::cout << str << std::endl;
    }
    std::cout << "size of array : " << sizeof(employees) << std::endl;
}