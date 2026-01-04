// lambda4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

template<typename T>
vector<T> CreateVector(int n, vector<T> v)
{
    for (int i = 0; i < n; i++)
    {
        T t;
        cout << "Enter the element" << endl;
        cin >> t;
        v.push_back(t);
    }
    return v;
}

int main()
{
    int n;
    cout << "Enter the num of elements" << endl;
    cin >> n;

    vector<int> v;
    vector<int>(*CreateVectorFP)(int, vector<int>) = CreateVector;
    v = CreateVectorFP(n, v);

    auto i = std::find_if(v.begin(), v.end(), [n](int val)
        {
            return val > n;
        });

    cout << *i << endl;
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
