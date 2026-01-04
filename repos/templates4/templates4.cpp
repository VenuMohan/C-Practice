// templates4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;


template<typename T>
class TempClass 
{
    int n;
    vector<T> v;
    T sum;
    T avg;

public:

    void SetNumOfElements()
    {
        cout << "Enter the num of elements" << endl;
        cin >> n;
    }

    void CreateVector()
    {
        for (int i = 0; i < n; i++)
        {
            T t;
            cout << "Enter the element" << endl;
            cin >> t;
            v.push_back(t);
        }
    }

    void GetAvg()
    {
        sum = 0;
        for (T t : v)
        {
            sum += t;
        }

        avg = sum / n;
        cout << "Average is " << avg << endl;
    }

    void PrintVector()
    {
        for (T t : v)
        {
            cout << t << ", ";
        }
        cout << endl;
    }

};
int main()
{
    TempClass<int> t;
    t.SetNumOfElements();
    t.CreateVector();
    t.PrintVector();
    t.GetAvg();
}


