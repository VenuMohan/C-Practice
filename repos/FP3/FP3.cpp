// FP3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include<utility>
#include <map>
using namespace std;

vector<int> CreateVector(int a, vector<int> VInt)
{
    VInt.push_back(a);
    return VInt;
}

vector<char> CreateVector(char a, vector<char> VChar)
{
    VChar.push_back(a);
    return VChar;
}

void PrintVector(vector<int> VInt)
{
    cout << "The elements are" << endl;
    for (int a : VInt)
    {
        cout << a << endl;
    }
}

void PrintVector(vector<char> VChar)
{
    cout << "The elements are" << endl;
    for (char a : VChar)
    {
        cout << a << endl;
    }
}
vector<int> SetVector(vector<int> VInt, vector<int>(*FPIntVector)(int a, vector<int> IntVector), int n)
{
    for (int i = 0; i < n; i++)
    {
        int a;
        cout << "Enter the int" << endl; 
        cin >> a;
        VInt = FPIntVector(a, VInt);
    }

    return VInt;
}

vector<char> SetVector(vector<char> CInt, vector<char>(*FPCharVector)(char a, vector<char> CharVector), int n)
{
    for (int i = 0; i < n; i++)
    {
        char a;
        cout << "Enter the char" << endl;
        cin >> a;
        CInt = FPCharVector(a, CInt);
    }

    return CInt;
}

map<int, char> CreateMap(vector<int> VInt, vector<char> CInt, int n)
{
    map<int, char> m;
    for (size_t i = 0; i < VInt.size() && i < CInt.size(); i++)
    {
        m[VInt[i]] = CInt[i];
    }
    return m;
}

void PrintElementCount(int n)
{
    cout << "We have " << n << " elements" << endl;
}
void PrintMap(map<int, char> m)
{
    cout << "The map elements are" << endl;
    for (pair<int, char> p : m)
    {
        cout << p.first << " " << p.second << endl;
    }
}
int main()
{
    int n;
    cout << "Enter the num of elements" << endl;
    cin >> n;

    void(*PrintEC)(int) = PrintElementCount;
    PrintEC(n);

    vector<int> IntVector;
    vector<int>(*IntFP)(int, vector<int>) = CreateVector;
    vector<int>(*FPVectorSetup)(vector<int>, vector<int>(*FPCreateVector)(int, vector<int>), int) = SetVector;
    IntVector = SetVector(IntVector, IntFP, n);

    void(*PrintFP)(vector<int> VInt) = PrintVector;
    PrintFP(IntVector);

    vector<char> CharVector;
    vector<char>(*CharFP)(char, vector<char>) = CreateVector;
    vector<char>(*FPCharSetup)(vector<char>, vector<char>(*FPCharVector)(char, vector<char> ),int) = SetVector;
    CharVector = SetVector(CharVector, CharFP, n);

    void(*PrintCVector)(vector<char>) = PrintVector;
    PrintCVector(CharVector);

    map<int, char> map1;
    map<int, char>(*FPMap)(vector<int>, vector<char>, int) = CreateMap;
    map1 = FPMap(IntVector, CharVector, n);

    void(*PrintMapFP)(map<int, char>) = PrintMap;
    PrintMapFP(map1);
}

