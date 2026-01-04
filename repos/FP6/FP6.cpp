// FP6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

template<typename T>
vector<T> CreateVector(int n, vector<T> v, T GetMinValue(vector<T> v), T GetMaxValue(vector<T> v), T GetAvgValue(vector<T> v), void PrintVectorValues(vector<T> v))
{
    for (int i = 0; i < n; i++)
    {
        T a;
        cout << "Enter the element" << endl;
        cin >> a;
        v.push_back(a);
    }

    PrintVectorValues(v);

    T Min = GetMinValue(v);
    T Max = GetMaxValue(v);
    T avg = GetAvgValue(v);

    cout << "The min and max values are " << Min << "," << Max << endl;
    cout << "The avg is " << avg << endl;
    return v;


}

template<typename T>
void PrintVector(vector<T> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
}

template<typename T>
T GetMin(vector<T> v)
{
    T a = v[0];
    for (int i = 0; i < v.size(); i++)
    {
        if (a > v[i])
        {
            a = v[i];
        }
    }
    return a;
}

template<typename T>
T GetMax(vector<T> v)
{
    T a = v[0];
    for (int i = 0; i < v.size(); i++)
    {
        if (a < v[i])
        {
            a = v[i];
        }
    }
    return a;
}

template<typename T>
T GetSumAndAverage(vector <T> v)
{
    T sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        sum = sum + v[i];
    }
    cout << "The sum is " << sum << endl;
    T avg;
    avg = sum / v.size();
    return avg;
}
int main()
{
    int n;
    cout << "Enter the num of elements" << endl;
    cin >> n;
    vector <int> IntVector;
    void(*PrintVectorValues)(vector<int>) = PrintVector;
    int(*MinVectorValue)(vector<int>) = GetMin;
    int(*MaxVectorValue)(vector<int>) = GetMax;
    int(*AvgVectorValue)(vector<int>) = GetSumAndAverage;
    vector<int>(*CreateIntVector)(int, vector<int>, int(*MinVectorValue)(vector<int>), 
        int(*MaxVectorValue)(vector<int>), int(*AvgVectorValue)(vector<int>), void(*PrintVectorValues)(vector<int>)) = CreateVector;
    CreateIntVector(n, IntVector, MinVectorValue, MaxVectorValue, AvgVectorValue, PrintVectorValues);
}

