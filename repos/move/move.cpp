// move.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string> 


class Entity 
{
public:
    Entity(const char* s)
    {
        std::cout << "Entity created" << std::endl;
        size = strlen(s);
        str = new char[size];

        // memcpy copies from sopurce to destination
        memcpy(str, s, size);
    }

    // copy constructor
    Entity(const Entity& other)
    {
        std::cout << "Entity copied" << std::endl;
        size = other.size;

        // new allocates memory on heap
        str = new char[size];

        // memcpy copies from sopurce to destination
        memcpy(str, other.str, size);
    }

    // move constructor using rvalue ref
    Entity(Entity&& other) noexcept
    {
        std::cout << "Entity moved" << std::endl;

        // get data from other
        size = other.size;
        str = other.str;

        // set other data to null
        other.size = 0;
        other.str = nullptr;

        // other is now hollow
    }


    void Print()
    {
        for (uint16_t i = 0; i < size; i++)
        {
            printf("%c ", str[i]);
        }
        std::cout << std::endl;
    }

    ~Entity()
    {
        std::cout << "Destroyed entity" << std::endl;
        delete[] str;
    }
private:

    char* str;
    size_t size;
};

class Child
{
public:
    Child(const Entity& entity)
    {
        e = new Entity(entity);
    }

    // constructor with rvalue
    // used to move data
    Child(Entity&& entity) 
    {
        // move data from entity to e
        e = new Entity(std::move(entity));
    }

    void PrintName()
    {
        e->Print();
    }

    ~Child()
    {
        std::cout << "Destroyed child" << std::endl;
        delete e;
    }

private:
    Entity* e;
};
int main()
{
    Child* c = new Child((Entity)"Chinnu");
    c->PrintName();

    delete c;
}

