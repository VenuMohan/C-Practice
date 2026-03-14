// func2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

void PrintString(const std::string& str)
{
    std::cout << str << std::endl;
}

template<typename T>
void CreateVector(std::vector<T>& v, const int& n)
{
    PrintString("CREATING VECTOR");
    for (int i = 0; i < n; i++)
    {
        T t;
        std::cout << "enter the value" << std::endl;
        std::cin >> t;
        v.push_back(t);
    }
    PrintString("CREATED VECTOR");
}

template<typename T>
void PrintVector(const std::vector<T>& v)
{
    for (const T &t : v)
    {
        std::cout << t << std::endl;
    }
}


template<typename T1, typename T2>
void CreateMap(const std::vector<T1> &V1, const std::vector<T2> &V2, std::map<T1, T2> &m)
{
    for (int i = 0; i < V1.size(); i++)
    {
        std::pair<T1, T2> p;
        p.first = V1[i];
        p.second = V2[i];
        m.insert(p);
    }
}

template<typename T1, typename T2>
void PrintMap(const std::map<T1, T2>& m)
{
    for (const std::pair<T1, T2> &p : m)
    {
        std::cout << p.first << ", " << p.second << std::endl;
    }
}

void SortVector(std::vector<size_t> V)
{
    std::sort(V.begin(), V.end());
}

int main()
{
    std::vector<size_t> V1;
    std::vector<std::string> V2;
    std::map<size_t, std::string> m;
    CreateVector(V1, 5);
    SortVector(V1);
    CreateVector(V2, 5);
    CreateMap(V1, V2, m);
    PrintVector(V1);
    PrintVector(V2);
    PrintMap(m);
}

