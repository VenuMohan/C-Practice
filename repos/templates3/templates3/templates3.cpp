// templates3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <utility>
#include <map>
using namespace std;

int GetMin(int, int);
int GetMax(int, int);

template<typename T> 
void PrintArray(vector<T> tempVector, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << tempVector[i] << endl;
    }
}

template<typename T1, typename T2>
void CreateMap(vector<T1> Arr1, vector<T2> Arr2)
{
    map<T1, T2> m;
    pair<T1, T2> p;
    for (int i = 0; i < Arr1.size(); i++)
    {
        for (int j = 0; j < Arr2.size(); j++)
        {
            pair<T1, T2> p;
            p.first = Arr1[i];
            p.second = Arr2[i];
            m.insert(p);
        }
    }

    for (pair <T1, T2> p1 : m)
    {
        cout << p1.first << " , " << p1.second << endl;
    }
}

int main()
{
    int n;
    cout << "Enter the num of integers" << endl;
    cin >> n;

    vector<int> intArray(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the integer" << endl;
        cin >> intArray[i];
    }

    PrintArray(intArray, n);    

    int m;
    cout << "Enter the num of strings" << endl;
    cin >> m;

    vector<string> strArray(m);
    for (int i = 0; i < m; i++)
    {
        string temp;
        cout << "Enter the string" << endl;
        cin >> temp;

        strArray.insert(strArray.begin(), temp);
    }

    PrintArray(strArray, m);

    int MinNum = GetMin(n, m);
    int MaxNum = GetMax(n, m);

    if (n == m)
    {
        CreateMap(intArray, strArray);
    }
    
    
}

int GetMin(int p, int q)
{
    if (p <= q)
    {
        return p;
    }
    else {
        return q;
    }
}

int GetMax(int p, int q)
{
    if (p > q)
    {
        return p;
    }
    else 
    {
        return q;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
