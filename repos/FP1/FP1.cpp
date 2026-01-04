// FP1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void HelloWorld()
{
    cout<< "Hello World !!" << endl;
}

int GetInt()
{
    return 5;
}

int GetSum(int a, int b)
{
    return a + b;
}

void PrintInt(int s)
{
    cout << s << endl;
}
int main()
{
    HelloWorld();

    // assign function pointer to a function
    // get the address of the function as a function pointer 
    auto fp1 = HelloWorld;
    fp1();

    void(*fp2)() = HelloWorld;
    fp2();

    auto fp3 = GetInt;
    int p = fp3();
    void(*fp_1)(int) = PrintInt;
    fp_1(p);

    int(*fp4)() = GetInt;
    int q = fp4();
    void(*fp_2)(int) = PrintInt;
    fp_2(q);

    int(*fp5)(int, int) = GetSum;
    int r = fp5(p, q);
    void(*fp_3)(int) = PrintInt;
    fp_3(r);

}
