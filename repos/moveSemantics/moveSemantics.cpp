// moveSemantics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// move.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
 

class String 
{
public:
    String(const char* s)
    {
        std::cout << "String created" << std::endl;
        size = strlen(s);
        str = new char[size];

        // memcpy copies from source to destination
        memcpy(str, s, size);
    }

    // copy constructor
    String(const String& other)
    {
        std::cout << "String copied" << std::endl;
        size = other.size;

        // new allocates memory on heap
        str = new char[size];

        // memcpy copies from sopurce to destination
        memcpy(str, other.str, size);
    }

    // copy assignment op
    String& operator = (const String& other)
    {
        if (this != &other)
        {
            delete []str;

            size = other.size;
            str = new char[size];

            memcpy(str, other.str, size);
        }

        return *this;
    }
    // move constructor using rvalue ref
    String(String&& other) noexcept
    {
        std::cout << "String moved" << std::endl;

        // get data from other
        size = other.size;
        str = other.str;

        // set other data to null
        other.size = 0;
        other.str = nullptr;
        // other is now hollow
    }

    // move assignment op
    String& operator = (String&& other) noexcept 
    {
        if (this != &other)
        {
            std::cout << "String move assigned" << std::endl;
            // delete current data
            delete []str;

            // get data from other
            size = other.size;
            str = other.str;

            // set other data to null
            other.size = 0;
            other.str = nullptr;
            // other is now hollow
        }

        return *this;
    }


    void Print()
    {
        for (uint16_t i = 0; i < size; i++)
        {
            printf("%c ", str[i]);
        }
        std::cout << std::endl;
    }

    ~String()
    {
        std::cout << "Destroyed string" << std::endl;
        delete[] str;
    }
private:

    char* str;
    size_t size;
};

class Entity
{
public:
    Entity(const String& string)
    {
        e = new String(string);
    }

    // constructor with rvalue
    // used to move data
    Entity(String&& string)
    {
        // move data from other to e
        e = new String(std::move(string));
    }

    void PrintName()
    {
        e->Print();
    }

    ~Entity()
    {
        std::cout << "Destroyed entity" << std::endl;
        delete e;
    }

private:
    String* e;
};
int main()
{
    Entity* e = new Entity((String)"Chinnu");
    e->PrintName();

    String name = "Cowboy";
    // copies string
    String nickname = name;
    // moves string via rvalue ref
    String nn1 = (String&&)name;
    std::cout << "nn1: ";
    nn1.Print();

    // move via std func
    // move to nn2 from nn1
    // nn2 is a new object in this case that steals from nn1
    // nn2 calls for move constructor 
    String nn2 = std::move(nn1);
    std::cout << "nn2 after move: ";
    nn2.Print();


    String nn3 = "Mohan";
    std::cout << "nn3 before moving: ";
    nn3.Print();
    nn3 = std::move(nn2);
    std::cout << "nn3 after moving: ";
    nn3.Print();
    nn2.Print();
    delete e;
}

