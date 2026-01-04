// templates5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;
template<typename T1, typename T2>
class MapVector
{
    vector<T1> v1;
    vector<T2> v2;

    map<T1, T2> m;
    int n = 0;

public:

    void SetElementCount()
    {
        cout << "Enter the num of elements" << endl;
        cin >> n;
    }

    vector<T1> CreateIntVector()
    {
        for (int i = 0; i < n; i++)
        {
            T1 t1;
            cout << "Enter the int" << endl;
            cin >> t1;
            v1.push_back(t1);
        }
        return v1;
    }

    vector<T2> CreateCharVector()
    {
        for (int i = 0; i < n; i++)
        {
            T2 t1;
            cout << "Enter the char" << endl;
            cin >> t1;
            v2.push_back(t1);
        }
        return v2;
    }

    void PrintIntVector(vector<T1> &v)
    {
        for (T1 t1 : v)
        {
            cout << t1 << ", ";
        }
        cout << endl;
    }

    void PrintCharVector(vector<T2> &v)
    {
        for (T2 t2 : v)
        {
            cout << t2 << ", ";
        }
        cout << endl;
    }

    map<T1, T2> CreateMap(vector<T1> &v1, vector<T2> &v2)
    {
        for (int i = 0; i < n; i++)
        {
            pair<T1, T2> p;
            p.first = v1[i];
            p.second = v2[i];
            m.insert(p);
        }

        return m;
    }

    void PrintMap(map<T1, T2> &m)
    {
        for (pair<T1, T2> p : m)
        {
            cout << p.first << ", " << p.second << endl;
        }
    }
};

int main()
{
    MapVector<int, char> obj1;
    obj1.SetElementCount();
    vector<int> VectorInt = obj1.CreateIntVector();
    vector<char> VectorChar = obj1.CreateCharVector();
    obj1.PrintIntVector(VectorInt);
    obj1.PrintCharVector(VectorChar);
    map<int, char> m = obj1.CreateMap(VectorInt, VectorChar);
    obj1.PrintMap(m);
}

