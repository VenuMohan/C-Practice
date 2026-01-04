// lambda3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cout << "Enter the num of elements" << endl;
    cin >> n;
    auto addNum = [](int a, int b)->int
        {
            return a + b;
        };

    auto printNum = [](int a)
        {
            cout << a << endl;
        };

    auto CreateVector = [n](vector<int> v)->vector<int>
        {
            for (int i = 0; i < n; i++)
            {
                int p;
                cout << "Enter the int" << endl;
                cin >> p;
                v.push_back(p);
            }
            return v;
        };

    auto PrintVector = [n](vector<int> v)
        {
            for (int p : v)
            {
                cout << p << endl;
            }
        };

    auto AvgVal = [n](vector<int> v)->int
        {
            int sum = 0;
            for (int i : v)
            {
                sum += i;
            }

            return sum / n;
        };

    int p, q;
    cout << "Enter the values of p and q" << endl;
    cin >> p; cin >> q;

    int r = addNum(p, q);
    printNum(r);

    vector<int> v = CreateVector(v);
    PrintVector(v);

    int avgVal = AvgVal(v);
    cout << "Avg is " << avgVal << endl;
}
