// Rule3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Entity 
{
private:
    int* p;
public:
    Entity() : p(new int(0)) { std::cout << "Entity Obj created" << std::endl; }
    Entity(const int& i)
    {
        p = new int(i);
    }

    // copy constructor
    Entity(const Entity& other)
    {
        p = new int(*other.p);
    }

    // copy assignment operator
    Entity& operator = (const Entity& other)
    {
        if (this  != &other)
        {
            // free old
            delete p;

            // assign new
            p = new int(*other.p);
        }
        return *this;
    }

    // getter
    const int& GetVar() const 
    {
        return *p;
    }

    void SetVar(const int& i)
    {
        *p = i;
    }

    ~Entity() 
    {
        delete(p);
        std::cout << "Entity obj deleted" << std::endl; 
    }

};

int main()
{
    // stack object deep copy
    Entity a(6);
    Entity b = a;

    a.SetVar(7);
    std::cout << a.GetVar() << std::endl;
    std::cout << b.GetVar() << std::endl;

    // heaap shallow copy
    Entity* e1 = new Entity(8);
    Entity* e2 = e1;

    e1->SetVar(9);
    std::cout << e1->GetVar() << std::endl;
    std::cout << e2->GetVar() << std::endl;

    Entity* e3 = new Entity(*e1);
    e3->SetVar(2);
    std::cout << e1->GetVar() << std::endl;
    std::cout << e3->GetVar() << std::endl;
}

