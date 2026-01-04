// lambda1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;


template<typename T>
void PrintVector(vector<T> v)
{
    for (T t : v)
    {
        cout << t << endl;
    }
}

template<typename T>
vector<T> CreateVector(int n, vector<T> v, void(*PrintVectorFP)(vector<T>))
{
    for (int i = 0; i < n; i++)
    {
        T t;
        cout << "Enter the element" << endl;
        cin >> t;
        v.push_back(t);
    }

    PrintVectorFP(v);
    return v;
}

template<typename T1, typename T2>
map<T1, T2> CreateMap(vector <T1> v1, vector<T2> v2, map<T1, T2> m)
{
    for (int i = 0; i < v1.size(); i++)
    {
        pair<T1, T2> p;
        p.first = v1[i];
        p.second = v2[i];
        m.insert(p);
    }
    return m;
}

template<typename T1, typename T2>
void PrintMap(map<T1, T2> m, vector<T1> v1, vector<T2> v2,map<T1,T2>(*CreateMapFP)(vector<T1>, vector<T2>, map<T1, T2>))
{
    m = CreateMapFP(v1, v2, m);
    for (pair<T1, T2> p : m)
    {
        cout << p.first << ", " << p.second << endl;
    }
}


int main()
{
    int n;
    cout << "Enter num of elements" << endl;
    cin >> n;

    vector<int> IntVector;
    vector<char> CharVector;
    map<int, char> m;
    void(*PrintVectorFP)(vector<int>) = PrintVector;
    vector<int>(*CreateVectorFP)(int, vector<int>, void(*PrintVectorFP)(vector<int>)) = CreateVector;
    vector<char>(*CreateVectorCharFP)(int, vector<char>, void(*PrintVectorFP)(vector<char>)) = CreateVector;
    auto lambda = [](vector<int >v)->void
        {
            for (int i : v)
            {
                cout << i << endl;
            }
        };

    auto lambda2 = [](vector<char> c)->void
        {
            for (char i : c)
            {
                cout << i << endl;
            }
        };

    auto lambda3 = [](vector<int> v1, vector<char> v2,map<int, char> m)->map<int, char>
        {
            for (int i = 0; i < v1.size(); i++)
            {
                pair<int, char> p;
                p.first = v1[i];
                p.second = v2[i];
                m.insert(p);
            }
            return m;
        };
    IntVector = CreateVectorFP(n, IntVector, lambda);
    CharVector = CreateVectorCharFP(n, CharVector, lambda2);
    void(*PrintMapFP)(map<int, char>, vector<int>, vector<char>, map<int, char>(*CreateMapFP)(vector<int>, vector<char>, map<int, char>)) = PrintMap;
    PrintMapFP(m, IntVector, CharVector, lambda3);
}


