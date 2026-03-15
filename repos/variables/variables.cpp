// variables.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>

int main()
{
    int i;
    char a;
    std::string s;
    float f = 3.14162817;
    double d = 3.14162817;
    uint16_t j;
    uint32_t k;
    long l;
    bool b = -2;

    std::cout <<"int size " << sizeof(i) << std::endl;
    std::cout <<"char size " << sizeof(a) << std::endl;
    std::cout <<"string size " << sizeof(s) << std::endl;
    std::cout <<"double size " << sizeof(d) << std::endl;
    std::cout << std::setprecision(15) << "double is " << d << std::endl;
    std::cout << "float size "<<sizeof(f) << std::endl;
    std::cout << std::setprecision(15) << "float is" << f << std::endl;
    std::cout << "uint16 size " << sizeof(j) << std::endl;
    std::cout << "uint32 size " <<sizeof(k) << std::endl;
    std::cout <<"long size " << sizeof(l) << std::endl;
    std::cout <<"bool size " << sizeof(b) << std::endl;
}
