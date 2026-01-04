// vectors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

int main()
{
    std::vector<int> IntVector = { 2, 3, 5, 7, 11 };

    // adds element to the back of vector
    IntVector.push_back(13);
    
    std::cout << "first element: " << IntVector.front() << std::endl;
    std::cout << "last element: " << IntVector.back() << std::endl;
    std::cout << "size : " << IntVector.size() << std::endl;
    std::cout << "capacity : " << IntVector.capacity() << std::endl;
    std::cout << "element at 4: " << IntVector.at(4) << std::endl;
    
    std::vector<float> FloatVector;
    std::vector<int> CastIntVector;
    int n = 0;
    std::cout << "Enter the num of float elements" << std::endl;
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        float f = 0;
        std::cout << "Enter the float element" << std::endl;
        std::cin >> f;

        FloatVector.push_back(f);
        CastIntVector.push_back(static_cast<int>(f));
    }

    // remove last element
    CastIntVector.pop_back();

    std::cout << "Int Vector is" << std::endl;
    for (int i : CastIntVector)
    {
        std::cout << i << ", ";
    }

    std::cout << std::endl;

    // insert at a position
    // inserting an element increases size of vector
    CastIntVector.insert(CastIntVector.begin(), 6);
    CastIntVector.insert(CastIntVector.begin() + 1, 8);
    CastIntVector.insert(CastIntVector.end(), 9);
    CastIntVector.insert(CastIntVector.end() - 1, 10);

    // erase removes an element at an index
    CastIntVector.erase(CastIntVector.begin() + 2);

    std::cout << "modded vector is " << std::endl;
    for (int i : CastIntVector)
    {
        std::cout << i << ", ";
    }


}

