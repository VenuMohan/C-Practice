// FP2.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <vector>
using namespace std;

int GetMax(std::vector<int> intVal)
{
    int max = 0 ;
    for (int i : intVal)
    {
        if (i > max) 
        {
            max = i;
        }
    }
    return max;
}

int GetMin(vector<int> intVal)
{
    int min = 1;
    for (int i : intVal)
    {
        if (i < min)
        {
            min = i;
        }
    }
    return min;
}

void PrintInt(int r)
{
    cout << r << endl;
}

void PrintAvg(vector<int> intVal, void(*PrintFunc)(int))
{
    int n = intVal.size();
    int sum = 0;
    for (int i : intVal)
    {
        sum = sum + i;
    }
    int avg = sum / n;

    PrintFunc(avg);
}

void GetMedian(vector<int> intVal,int(*minFunc)(vector<int>), int(*maxFunc)(vector<int>), void(*PrintFunc)(int))
{
    int p = minFunc(intVal);
    int q = maxFunc(intVal);

    int r = (p + q)/2;
    PrintFunc(r);
}

int main()
{
    vector<int> IntVector = { 2, 7, 9, 3, 1 };
    int(*maxNum)(vector<int>) = GetMax;
    int(*minNum)(vector<int>) = GetMin;

    int a = maxNum(IntVector);
    int b = minNum(IntVector);

    void(*Print)(int) = PrintInt;

    Print(a);
    Print(b);

    void(*Avg)(vector<int>, void(*Print)(int)) = PrintAvg;
    Avg(IntVector, Print); 

    void(*Med)(vector<int>, int(*minFunc)(vector<int>), int(*maxFunc)(vector<int>), void(*PrintFunc)(int)) = GetMedian;
    Med(IntVector, maxNum, minNum, Print);
}


