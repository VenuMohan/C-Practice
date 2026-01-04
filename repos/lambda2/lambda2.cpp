// lambda2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

template<typename T>
vector<T> CreateVector(int n, vector<T> v, void(*PrintVectorFP)(vector<T>), T(*GetAvgFP)(vector<T>))
{
    for (int i = 0; i < n; i++)
    {
        T t;
        cout << "Enter the element" << endl;
        cin >> t;
        v.push_back(t);
    }

    PrintVectorFP(v);
    T avg = GetAvgFP(v);
    return v;
}

template<typename T>
void PrintVector(vector<T> v)
{
    for (T t : v)
    {
        cout << t << endl;
    }
}

template<typename T> 
T GetAverage(vector<T> v)
{
    T sum;
    for (T t : v)
    {
        sum += t;
    }

    T avg = sum / v.size();
    return avg;
}

int main()
{
    int n;
    vector<int> v;
    cout << "Enter the num of elements" << endl;
    cin >> n;

    vector<int>(*CreateVectorFP)(int, vector<int>, void(*PrintFP)(vector<int>), int(*GetAvgFP)(vector<int>)) = CreateVector;
    auto lambda = [](vector<int> v)->void
        {
            for (int i : v)
            {
                cout << i << endl;
            }
        };

    auto lambda2 = [](vector<int> v)->int
        {
            int sum = 0;
            for (int i : v)
            {
                sum += i;
            }
            int avg = sum / v.size();
            return avg;
        };

    v = CreateVectorFP(n, v, lambda, lambda2);
    int avg = lambda2(v);
    cout << "The avg is " << avg << endl;
}

