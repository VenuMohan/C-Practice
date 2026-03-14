// templateClass2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

template<typename T>
class Entity 
{
private:
    T t;
    std::vector<T> V;
public:
    Entity(const T& t1) 
    {
        t = t1;
        V.push_back(t1);
    }

    const T& GetEntity() { return t; }

    const std::vector<T>& GetEntityVector() { return V; }

    void SetEntityArray(std::vector<std::string>& VStr)
    {
        std::string str = VStr[0];
        for (char c : str)
        {
            VStr.emplace_back(1, c);
        }
    }

    void PrintVectorArray(const std::vector<T>& v)
    {
        for (const std::string& _s : v)
        {
            std::cout << _s << std::endl;
        }
    }

    void GetReverse(std::vector<std::string>& VStr)
    {
        std::cout << "Full String Vector" << std::endl;

        if (VStr.empty())
        {
            return;
        }
        std::string s = VStr[0];
        for (int i = s.length() - 1; i >= 0; i--)
        {
            char c = s[i];
            VStr.emplace_back(1, s[i]);
        }
    }

};


int main()
{
    Entity<std::string> entity("Venu");
    std::cout << entity.GetEntity() << std::endl;
    std::vector<std::string> VStr = entity.GetEntityVector();
    entity.SetEntityArray(VStr);
    entity.PrintVectorArray(VStr);
    entity.GetReverse(VStr);
    entity.PrintVectorArray(VStr);
    entity.PrintVectorArray(std::vector<std::string> {"Chinnu", "406", "Hyd"});
}

