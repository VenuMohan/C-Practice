// templateClass.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>


template<typename T>
class Entity 
{
public:
    Entity(const T& t1) { t = t1; }
    const T& GetEntity() { return t; }
    void SetReverseEntity(const T& _t) { t1 = _t; }
    std::string GetReverse(const std::string& str) 
    {
        std::string s;
        for (size_t i = str.length(); i > 0; i--)
        {
            char c = str[i-1];
            s.push_back(c);
        }
        return s;
    }


    const T& GetReverseEntity() { return t1; }
private:
    T t;
    T t1;
};


int main()
{
    Entity<std::string> entity("Venu");
    std::cout << "Entity name is " << entity.GetEntity() << std::endl;

    Entity<std::string> entity1("Chinnu");
    std::string s =  entity.GetReverse(entity1.GetEntity());
    entity.SetReverseEntity(s);
    std::cout << "Reversed Entity: " << entity.GetReverseEntity() << std::endl;
}
