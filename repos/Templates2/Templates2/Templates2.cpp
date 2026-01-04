// Templates2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <utility>
#include <vector>
using namespace std;

template <typename T1, typename T2>
void MyFunc(T1 a, T2 b, pair<T1, T2> p)
{
    p.first = a;
    p.second = b;

    map<T1, T2> m1;
    m1.insert(p);
    cout << "The variables are " << p.first << " and " << p.second << endl;
}

template <typename T1, typename T2>
void CreateMap(vector<T1> ArrA, vector<T2> ArrB)
{
    map<T1, T2> m;
    for (int i = 0; i < ArrA.size() ; i++)
    {
        pair<T1, T2> p;
        p.first = ArrA[i];
        p.second = ArrB[i];

        m.insert(p);
    }

    cout << "The map values are " << endl;
    T1 sum = 0;
    for (pair<T1, T2> p1 : m)
    {
        cout << p1.first << ", " << p1.second << endl;
        sum += p1.first;
    }

    cout << "The sum of all integers is " << endl;
    cout << sum;

}

int main()
{
    int a;
    cout << "Enter an integer variable" << endl;
    cin >> a;

    char b;
    cout << "Enter a character variable" << endl;
    cin >> b;

    pair<int ,char> p1;

    MyFunc(a, b, p1);

    vector<int> v1;
    vector<char> v2;
    int n;

    cout << "Enter the num of elements " << endl;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int p;
        cout << "Enter the integer" << endl;
        cin >> p;

        v1.insert(v1.begin(), p);
    }

    for (int i = 0; i < n; i++)
    {
        char p;
        cout << "Enter the character" << endl;
        cin >> p;

        v2.insert(v2.begin(), p);
    }

    CreateMap(v1, v2);

}

