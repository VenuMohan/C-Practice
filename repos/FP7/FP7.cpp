// FP7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

template<typename T1, typename T2>
struct str
{
    T1 a;
    T2 b;
};


template<typename T1, typename T2>
vector<str<T1, T2>> CreateVector(int n, vector<str<T1, T2>> v)
{
    for (int i = 0; i < n; i++)
    {
        str<T1, T2> s;
        T1 a;
        T2 b;
        cout << "Enter the element" << endl;
        cin >> a;
        cout << "Enter the element" << endl;
        cin >> b;
        s.a = a;
        s.b = b;
        v.push_back(s);
    }
    return v;
}

template<typename T1, typename T2>
void PrintVector(vector<str<T1, T2>> v)
{
    cout << "The elements are" << endl;
    for (str<T1, T2> s : v)
    {
        cout << s.a << "," << s.b << endl;
    }
}


int main()
{
    int n;
    cout << "Enter the num of structs" << endl;
    cin >> n;

    vector<str<int, char>> v;
    vector<str<int, char>>(*CreateVectorStruct)(int, vector<str<int, char>>) = CreateVector;
    v = CreateVectorStruct(n, v);
    void(*PrintVectorStruct)(vector<str<int, char>>) = PrintVector;
    PrintVectorStruct(v);
}

