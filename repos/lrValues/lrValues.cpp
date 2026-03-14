// lrValues.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int GetVal()
{
    return 10;
}

int& GetLVal()
{
    // int& is an lvalue reference
    static int i = 11;
    return i;
}

void SetLValue(int& x)
{
    x = 12;
}

void SetValue(int x)
{
    x = 12;
}

const int& GetConstVal()
{
    static int g = 7;
    return g;
}

void SetConstVal(const int& z, int& w)
{
    w = z;
}

int main()
{
    // i is lval and 10 is rval
    // i has a mem address , 10 by itself has no mem address; is temperary
    int i = 10;

    // a and i are both lvalues
    int a = i;

    // b is lvalue while GetVal() is an r value
    int b = GetVal();

    // a,b and i are modifiable lvalues ie non const lvalues
    std::cout << a << ", " << b << ", " << i << std::endl;

    // returns lvalue ref (non const)
    int k = GetLVal();
    std::cout << k << std::endl;

    // sets lvalue with ref
    int x = 23;
    SetLValue(x);
    std::cout << x << std::endl;
    // lvalue ref can only be called via lvalue 

    // creates an lvalue ref with an rvalue
    SetValue(23);

    // lvalue ref can equal rvalue if its const
    const int& p = 16;

    const int& g = GetConstVal();
    std::cout << g << std::endl;

    // const can bind to anything lval and rvalue
    int w;
    SetConstVal(g, w);
    std::cout << w << std::endl;
}

