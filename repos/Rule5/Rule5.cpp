// Rule5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

template<typename T>
class Entity 
{
private:
    size_t count = 0;
    std::vector<T>* V = nullptr;

public:
    Entity(size_t _count, const T& t)
    {
        count = _count;
        V = new std::vector<T>();

        V->push_back(t);
    }

    Entity(const Entity& other)
    {
        count = other.count;

        V = new std::vector<T>(*other.V);
    }

    Entity& operator = (const Entity& other)
    {
        if (this != &other)
        {
            delete V;
            count = 0;

            count = other.count;
            V = new std::vector<T>(*other.V);
        }

        return *this;
    }

    Entity(Entity&& other) noexcept
    {

        count = other.count;
        V = other.V;

        other.V = nullptr;
        other.count = 0;
    }

    Entity& operator = (Entity&& other) noexcept
    {
        if (this != &other)
        {
            delete V;
            count = 0;

            count = other.count;
            V = other.V;

            other.V = nullptr;
            other.count = 0;
        }

        return *this;
    }

    void AddToVector(const T& t)
    {
        V->push_back(t);
    }

    void PrintVector()
    {
        std::cout << '\n';
        for (const T& t : *V)
        {
            std::cout << t << '\n';
        }
    }

    ~Entity() { delete V; }

};

int main()
{
    Entity<std::string>* e = new Entity<std::string>(4, "Venu");
    e->AddToVector("Mohan");
    e->PrintVector();

    // shallow copy
    Entity<std::string> *e1 = e;
    e1->AddToVector("Sharma");
    e->PrintVector();

    // deep copy
    Entity<std::string>* e2 = new Entity<std::string>(*e1);
    e2->AddToVector("Ayachitula");
    e2->PrintVector();

    // copy assign op
    Entity<std::string>* e3 = new Entity<std::string>(7, "Chinnu");
    *e3 = *e2;
    e3->PrintVector();

    // move
    Entity<std::string>* e4 = new Entity<std::string>(std::move(*e2));
    e4->AddToVector("Chinnu");
    e4->PrintVector();

    // move assign op
    Entity<std::string>* e5 = new Entity<std::string>(9, "Cowboy");
    *e5 = std::move(*e4);
    e5->AddToVector("Cowboy");
    e5->PrintVector();

    delete e;
    delete e2;
    delete e3;
    delete e4;
    delete e5;

}

