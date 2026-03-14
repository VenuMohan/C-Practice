// move3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

template<typename T>
class Entity 
{
private:
    std::vector<T> *V = nullptr;
    int count = 0;

public:
    Entity(const int& size, const T& t)
    {
        count = size;

        // init vector
        V = new std::vector<T>();
        V->push_back(t);
    }

    Entity(const Entity& other)
    {
        count = other.count;
        V = new std::vector<T>(*other.V);
    }

    // copy assignment op
    Entity& operator = (const Entity& other)
    {
        if (this != &other)
        {
            delete V;

            count = other.count;
            V = new std::vector<T>(*other.V);

        }

        return *this;
    }

    Entity(Entity&& other) noexcept
    {
        count = other.count;
        V = other.V;

        other.count = 0;
        other.V = nullptr;
    }

    void AddToVector(const T& t1)
    {
        V->push_back(t1);
    }

    void PrintVector()
    {
        for (const T& t : *V)
        {
            std::cout << t << ", ";
        }
        std::cout << '\n';
    }

    ~Entity()
    {
        delete V;
    }

};

int main()
{
    // heap shallow copy
    Entity<char>* a = new Entity<char>(1, 'a');
    Entity<char>* b = a;

    b->AddToVector('b');
    a->PrintVector();
    b->PrintVector();

    // heap deep copy
    Entity<char>* ab = new Entity<char>(*a);
    ab->AddToVector('c');
    ab->PrintVector();
    a->PrintVector();

    // copy assignment
    Entity<char>* d = new Entity<char>(4,'d');
    d->PrintVector();
    *d = *ab;
    d->AddToVector('d');
    d->PrintVector();

    // move
    Entity<char>* e = new Entity<char>(std::move(*d));
    e->AddToVector('e');
    e->PrintVector();

    delete a;
    delete ab;
    delete e;


}

