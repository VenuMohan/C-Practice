// macros.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

#define WAIT std::cin.get()
#define SQUARE(x) ((x)* (x))
#define CUBE(x) ((x)* (x) *(x))
#define PRINT(val) (std::cout<<  "Value: " << (val) << "\n")
#define PRINT_SQUARE(x) (PRINT(SQUARE(x)))
#define PRINT_CUBE(x)(PRINT(CUBE(x)))

int main()
{
    PRINT(SQUARE(5));
    int a = SQUARE(5);
    PRINT(a);
    PRINT_SQUARE(5);
    PRINT_CUBE(5);
    WAIT;
}


