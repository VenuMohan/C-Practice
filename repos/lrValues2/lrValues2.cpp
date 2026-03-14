// lrValues2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string> 

void PrintValue(std::string& str)
{
    std::cout << "l value ref " << str << std::endl;
}

void PrintVal(std::string&& str)
{
    // rvalue ref
    std::cout <<"rvalue ref " << str << std::endl;
}

void PrintVal(const std::string& str)
{
    std::cout << "const ref " << str << std::endl;
}

int main()
{
    std::string fN = "Venu";
    std::string lN = "Mohan";

    std::string FN = fN + " " + lN;
    // everything on left is lvalue and right is rvalue

    PrintValue(FN);
    //PrintValue(fn + ln); cant be used as rvalue cannot be lvalue ref
    // l value non const ref

    // const can print both r and r values
    PrintVal(fN + " " + lN);
    PrintVal(FN);

    // pure r value ref
    PrintVal(fN + lN);

    // rvalue ref overrides const but const overrides lvalue ref
    // rvalues are temp, so can be used in mem optimisation 
}

