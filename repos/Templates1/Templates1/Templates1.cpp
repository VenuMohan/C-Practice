// Templates1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

template<typename T> void SwapArgs(T &a, T &b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

template <typename T> T Max(std::vector<T> tempVector, int num)
{
    T a = tempVector[0];
    for (int i = 0; i < num; i++)
    {
        if (a < tempVector[i])
        {
            a = tempVector[i];
        }
    }

    return a;
}

template <typename T> T Min(std::vector<T> tempVector, int num)
{
    T a = tempVector[0];
    for (int i = 0; i < num; i++)
    {
        if (a > tempVector[i])
        {
            a = tempVector[i];
        }
    }

    return a;
}

int main()
{
    int i = 10, j = 20;
    char a = 'A', b = 'B';
    float f = 45.67f, c = 67.897f;

    cout << "Init values of i and j are " << i << " and " << j << endl;
    cout << "Init Values of a and b are " << a << " and " << b << endl;
    cout << "Init values of f and c are " << f << " and " << c << endl;

    SwapArgs(i, j);
    SwapArgs(a, b);
    SwapArgs(f, c);

    cout << "Final values of i and j are " << i << " and " << j << endl;
    cout << "Final Values of a and b are " << a << " and " << b << endl;
    cout << "Final values of f and c are " << f << " and " << c << endl;

    int n;
    cout << "Give the num of integers in the array" << endl;
    cin >> n;
    std::vector<int> IntArray(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Give the integer in the array" << endl;
        cin >> IntArray[i];
    }
    
    int maxInt = Max(IntArray, n);
    int minInt = Min(IntArray, n);
    cout << "Max int in the array is " << maxInt << endl;
    cout << "Min int in the array is " << minInt << endl;

    int m;
    cout << "Give the num of floats in the array" << endl;
    cin >> m;
    std::vector<float> FloatArray(m);
    for (int i = 0; i < m; i++)
    {
        cout << "Give the float in the array" << endl;
        cin >> FloatArray[i];
    }

    float MaxFloat = Max(FloatArray, m);
    float MinFloat = Min(FloatArray, m);
    cout << "Max float is " << MaxFloat << endl;
    cout << "Min float is " << MinFloat << endl;
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
