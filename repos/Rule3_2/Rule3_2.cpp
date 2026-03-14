// Rule3_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "string"
#include <utility>

template <typename T1, typename T2>
class Entity 
{
public:
    Entity(const T1& _t1, const T2& _t2) 
    {
        // init values in constructor 
        t1 = new T1(_t1);
        t2 = new T2(_t2);
    }

    // deep copy
    Entity(const Entity& other)
    {
        t1 = new T1(*other.t1);
        t2 = new T2(*other.t2);
    }

    // copy assignment op
    Entity& operator = (const Entity& other)
    {
        if (this != &other)
        {
            delete t1;
            delete t2;

            t1 = new T1(*other.t1);
            t2 = new T2(*other.t2);
        }

        return *this;
    }

    const T1& GetInt() const { return *t1; }
    const T2& GetString() const { return *t2; }

    // rvalue ref
    void SetInt(T1&& _t1)
    {
        *t1 = _t1;
    }

    void SetString(const T2& _t2)
    {
        *t2 = _t2;
    }

    ~Entity()
    {
        delete t1;
        delete t2;
    }

private:
    T1* t1;
    T2* t2;
};


int main()
{
    Entity<int, std::string> entity(3, "Three");

    // stack deep copy
    Entity<int, std::string> e1 = entity;
    e1.SetInt(6);

    std::cout << e1.GetInt() << std::endl;
    std::cout << entity.GetInt() << std::endl;

    // heap shallow copy
    Entity<int, std::string>* e2 = new Entity<int, std::string>(5, "Five");
    Entity<int, std::string>* e3 = e2;

    e3->SetString("Four");
    std::cout << e2->GetString() << std::endl;
    std::cout << e3->GetString() << std::endl;

    // heap deep copy
    Entity<int, std::string>* e4 = new Entity<int, std::string>(*e2);
    e4->SetInt(9);
    std::cout << e4->GetInt() << std::endl;
    std::cout << e2->GetInt() << std::endl;
    std::cout << e2->GetString() << std::endl;
    std::cout << e2->GetString() << std::endl;

    Entity<int, std::string>* e5 = new Entity<int, std::string>(7, "Seven");
    std::cout << "before copy" << std::endl;
    std::cout << e5->GetString() << std::endl;

    std::cout << "after copy" << std::endl;
    // calls copy assignment op
    *e5 = *e2;
    std::cout << e5->GetString() << std::endl;
    std::cout << e2->GetString() << std::endl;

    delete(e3);
    delete(e4);
    delete(e5);

}

