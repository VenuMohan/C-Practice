// FP5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;


template<typename T>
vector<T> CreateVector(int n, vector<T> v)
{
    for (int i = 0; i < n; i++)
    {
        T a;
        cout << "Enter the input" << endl;
        cin >> a;
        v.push_back(a);
    }
    return v;
}

template<typename T>
void PrintVector(vector<T> v)
{
    for (T a : v)
    {
        cout << a << endl;
    }
}

template<typename T1, typename T2>
void PrintMap(map<T1, T2> m)
{
    for (pair<T1, T2> p : m)
    {
        cout << p.first << ", " << p.second << endl;
    }
} 

template<typename T1, typename T2>
map<T1, T2> CreateMap(int n, vector <T1> v1, vector<T2> v2, map<T1, T2> m)
{
    for (int i = 0; i < n; i++)
    {
        pair<T1, T2> p;
        p.first = v1[i];
        p.second = v2[i];
        m.insert(p);
    }
    return m;
}

int main()
{
    int n;
    cout << "Num of elements in vector" << endl;
    cin >> n;

    vector<int> IntVector;
    vector<int>(*CreateIntVector)(int, vector<int>) = CreateVector;
    IntVector = CreateIntVector(n, IntVector);
    void(*PrintIntVector)(vector<int>) = PrintVector;
    PrintIntVector(IntVector);

    vector<char> CharVector;
    vector<char>(*CreateCharVector)(int, vector<char>) = CreateVector;
    CharVector = CreateCharVector(n,CharVector);
    void(*PrintCharVector)(vector<char>) = PrintVector;
    PrintCharVector(CharVector);

    map<int, char> m;
    map<int, char>(*CreateIntCharMap)(int, vector<int>, vector<char>, map<int, char>) = CreateMap;
    m = CreateIntCharMap(n, IntVector, CharVector, m);
    void(*PrintIntCharMap)(map<int, char>) = PrintMap;
    PrintIntCharMap(m);
}


