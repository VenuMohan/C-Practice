// FP4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
struct IntChar
{
    int i;
    char c;
};

int GetChar(IntChar ic)
{
    return ic.i;
}

IntChar CreateStruct()
{
    int i;
    cout << "Enter the int" << endl;
    cin >> i;

    char c;
    cout << "Enter the char" << endl;
    cin >> c;

    IntChar ic;
    ic.i = i;
    ic.c = c;
    return ic;
}

void PrintCharVector(vector<char>c)
{
    cout << "Char vector is" << endl;
    for (char i : c)
    {
        cout << i << ",";
    }
}

void PrintIntVector(vector<int>v)
{
    cout << "Int vector is" << endl;
    for (int i : v)
    {
        cout << i << ",";
    }
}
vector<IntChar>CreateVector(int n)
{
    vector<IntChar> v;
    vector<int> IntVector;
    vector<char> CharVector;
    for (int j = 0; j < n; j++)
    {
        int a;
        char b;
        IntChar ic;

        cout << "Enter the int" << endl;
        cin >> a;

        cout << "Enter the char" << endl;
        cin >> b;

        ic.i = a;
        ic.c = b;
        v.push_back(ic);
        IntVector.push_back(a);
        CharVector.push_back(b);
    }

    void(*PrintInt)(vector<int>) = PrintIntVector;
    void(*PrintChar)(vector<char>) = PrintCharVector;
    PrintInt(IntVector);
    PrintChar(CharVector);
    return v;
}


void PrintVector(vector<IntChar>CreateVectorStruct(int), int n)
{
    vector<IntChar> v = CreateVectorStruct(n);
    for (int i = 0; i < n; i++)
    {
        cout << v[i].i << "," << v[i].c << endl;
    }
}

void PrintInt(int i)
{
    cout << "The int is " << i << endl;
}


int main()
{
    IntChar s;
    int a;
    IntChar(*StructFP)() = CreateStruct;
    int(*GetCharFromStruct)(IntChar) = GetChar;
    void(*PrintIntFromStruct)(int) = PrintInt;
    s = StructFP();
    a = GetCharFromStruct(s);
    PrintIntFromStruct(a);

    int n;
    cout << "Enter the num of structs" << endl;
    cin >> n;
    
    vector<IntChar> v;
    vector<IntChar>(*CreateStructVector)(int) = CreateVector;
    void(*PrintStructVector)(vector<IntChar>CreateVectorStruct(int), int) = PrintVector;
    PrintStructVector(CreateStructVector, n);
}

