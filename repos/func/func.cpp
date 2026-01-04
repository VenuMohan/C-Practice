// func.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>


void PrintSomething()
{
    std::cout << "Hello World" << std::endl;
}

// const ref for string literals
// ref for vectors
// const indicates parameter is not changeable 
void PrintSomething(const std::string &str)
{
    std::cout << std::endl;
    std::cout << str << std::endl;
}

int GetSquare(int a)
{
    return a * a;
}

std::map<size_t, std::string> CreateMap(std::vector<size_t> &v1, std::vector<std::string> &v2)
{
    PrintSomething("Creating Map");
    std::map<size_t, std::string> m;
    for (int i = 0; i < v1.size(); i++)
    {
        std::pair<size_t, std::string> p;
        p.first = v1[i];

        // reverse order 
        p.second = v2[v1.size() - 1 - i];
        m.insert(p);
    }

    return m;
}

// alters the ref, doesnt alter the const ref
void PrintMap(std::map<size_t, std::string> &m, const std::string  &str)
{
    std::cout << str << std::endl;
    for (std::pair<size_t, std::string> p : m)
    {
        std::cout << p.first << ", " << p.second << std::endl;
    }
}

std::vector<int> GenerateRandomNumbers(int const&num)
{
    PrintSomething("RANDOM NUMBERS");
    std::vector<int> randomNumbers;

    // set time to start
    std::srand(std::time(nullptr));

    for (int i = 0; i < num; i++)
    {
        int randomNum = std::rand() % 10;
        randomNumbers.push_back(randomNum);
    }

    return randomNumbers;
}

// alters the parameter
std::vector<int> SortRandomNums(std::vector<int> &v)
{
    PrintSomething("SORTED");

    std::vector<int> sortedNums = v;
    
    std::sort(sortedNums.begin(), sortedNums.end());
    return sortedNums;
}

// & means taking argument as a ref
// doesnt alter the parameter
// const indicates not chanfeable
void PrintRandomNums(const std::vector<int> &v)
{
    for (int i : v)
    {
        std::cout << i << ", ";
    }
    std::cout << std::endl;
}



int main()
{
    std::string str = "Hello World";
    PrintSomething();
    PrintSomething(str);
    
    std::cout << GetSquare(5) << std::endl;

    // convert int to string
    PrintSomething(std::to_string(GetSquare(7)));

    std::vector<size_t> v1 = { 100, 102, 104, 108 };
    std::vector<std::string> v2 = { "Police", "Fire", "Child", "Hospital" };

    std::map<size_t, std::string> m = CreateMap(v1, v2);
    PrintMap(m, "The map is ");

    std::vector<int> randomNums = GenerateRandomNumbers(9);
    PrintRandomNums(randomNums);

    std::vector<int> sortedNums = SortRandomNums(randomNums);
    PrintRandomNums(sortedNums);

}
