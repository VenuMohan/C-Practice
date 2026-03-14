// lrValues3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <vector>

template<typename T1, typename T2>
class Entity 
{
public:
    Entity(){}

    Entity(const T1& _t1, const T2& _t2) 
    {
        t1 = _t1;
        t2 = _t2;
    }

    const T1& GetT1() const { return t1; }
    const T2& GetT2() const { return t2; }

    void CreateMap(const T1& t1, const T2& t2 )
    {
        std::pair<T1, T2> p;
        v.push_back(t1);
        s.push_back(t2);
        p.first = t1;
        p.second = t2;
        m.insert(p);
    }


    void SetValues(T1&& _t1, T2&& _t2) 
    {
        std::cout << "r value set" << std::endl;
        t1 = _t1;
        t2 = _t2;

        CreateMap(t1, t2);
    }
    const std::map<T1, T2>& GetMap() const
    {
        for (const std::pair<T1, T2>& p : m)
        {
            std::cout << p.first << ", " << p.second << std::endl;
        }
        return m;
    }

    void SetStringVector(T2&& str)
    {
        s.push_back(str);
    }

    const std::vector<T1>& GetIntVector() const
    {
        for (const T1& _t1 : v)
        {
            std::cout << _t1 << std::endl;
        }

        return v;
    }

    const std::vector<T2>& GetStringVector() const 
    {
        for (const T2& _t2 : s)
        {
            std::cout << _t2 << std::endl;
        }

        return s;
    }
private:
    T1 t1; 
    T2 t2;

    std::map<T1, T2> m;
    std::vector<T1> v;
    std::vector<T2> s;
};

int main()
{
    Entity<int, std::string> entity;
    entity.SetValues(2, "Two");
    entity.SetValues(3, "Three");
    entity.GetIntVector();
    entity.SetStringVector("Venu");
    entity.SetStringVector("Himanshu");
    entity.GetStringVector();
    entity.GetMap();

}
