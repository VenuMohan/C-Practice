// array2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>

int main()
{
    // std::array is c style array
    std::array<float, 5> floatArray = { 1.4, 3.5, 5.8, 9.3, 7.7 };

    std::cout << floatArray.at(3) << std::endl;
    std::cout << "last element : " << floatArray.back() << std::endl;
    std::cout << "first element : " << floatArray.front() << std::endl;
    std::cout << "max size : " << floatArray.max_size() << std::endl;
    std::cout << "size of array is " << sizeof(floatArray) << std::endl;

    float sum = 0;
    int sum1 = 0, sum2 = 0;

    for (int i = 0; i < 5; i++)
    {
        sum += floatArray[i];

        sum1 += static_cast<int>(floatArray[i]);
    }

    sum2 = static_cast<int>(sum);

    std::cout << "The sum of floats is " << sum << std::endl;
    std::cout << "The sum of floats converted to int " << sum1 << std::endl;
    std::cout << "The sum converted to int is " << sum2 << std::endl;
   

}

