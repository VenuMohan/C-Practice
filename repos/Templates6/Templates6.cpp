// Templates6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector> 

// variadic templates
// base case
template<typename T>
const T& Sum(const T& t)
{
    return t;
}

template<typename T, typename ... Others>
T Sum(T t, Others... others)
{
    return t + Sum(others...);
}

int main()
{
    int a = 15;
    a = Sum(a, 16, 17, 18);
    std::cout << a << std::endl;

    // sum of nums from one int to another int 
    int b = 20;
    for (short i = b + 1; i < 30; i++)
    {
        b = Sum(b, i);
    }
    std::cout << b << std::endl;

    std::vector<float> FloatVector;
    int c = 50;
    for (float i = 0; i < 10; i++)
    {
        float f = c + (i * 0.1f);
        FloatVector.push_back(f);
    }

    for (int i = 0; i < FloatVector.size(); i++)
    {
        c = Sum(c, FloatVector[i]);
    }

    std::cout << c << std::endl;







}
