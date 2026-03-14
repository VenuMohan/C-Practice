// Rule3_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>

template<typename T1, typename T2>
class Entity 
{
private:
    // raw pointers to vector
    std::vector<T1>* V1 ;
    std::vector<T2>* V2 ;

    // derived value
    // should not copy
    std::map<T1, T2>* m;

    void CreateMap()
    {
        m->clear();
        for (size_t i = 0; i < V1->size(); i++)
        {
            std::pair<T1, T2> p;
            p.first = (*V1)[i];
            p.second = (*V2)[i];
            m->insert(p);
        }
    }

public:

    Entity(const T1& t1, const T2& t2)
    {
        // initialise vector
        V1 = new std::vector<T1>();
        V2 = new std::vector<T2>();
        m = new std::map<T1, T2>();

        // add init values
        V1->push_back(t1);
        V2->push_back(t2);

        // add to map
        CreateMap();
    }

    // copy constructor
    Entity(const Entity& other)
    {
        V1 = new std::vector<T1>(*other.V1);
        V2 = new std::vector<T2>(*other.V2);
        m = new std::map<T1, T2>(*other.m);

        CreateMap();
    }

    // copy assignment
    Entity& operator = (const Entity& other)
    {
        if (this != &other)
        {
            // delete existing
            delete V1;
            delete V2;
            delete m;

            // set new 
            V1 = new std::vector<T1>(*other.V1);
            V2 = new std::vector<T2>(*other.V2);
            m = new std::map<T1, T2>(*other.m);

            CreateMap();
        }

        return *this;
    }

    void AddToMap(const T1& _t1, const T2& _t2)
    {
        V1->push_back(_t1);
        V2->push_back(_t2);

        CreateMap();
    }

    void PrintVector()
    {
        for (const T1& _t1 : *V1)
        {
            std::cout << _t1 << ", ";
        }
        std::cout << '\n';
    }

    void PrintMap()
    {
        for (const std::pair<T1, T2> p : *m)
        {
            std::cout << p.first << ", " << p.second << '\n';
        }
        std::cout << '\n';
    }

    ~Entity()
    {
        delete V1;
        delete V2;
        delete m;
    }
};


int main()
{
    // heap shallow copy
    Entity<int, std::string>* e = new Entity<int, std::string>(8, "Eight");
    Entity<int, std::string>* f = e;
    f->AddToMap(4, "Four");
    e->AddToMap(7, "Seven");
    e->PrintVector();
    f->PrintMap();

    // heap deep copy
    Entity<int, std::string>* g = new Entity<int, std::string>(*e);
    g->AddToMap(6, "Six");
    e->PrintMap();
    g->PrintMap();

    // heap copy assignment
    Entity<int, std::string>* h = new Entity<int, std::string>(9, "Nine");
    h->PrintMap();
    *h = *g;
    h->PrintMap();
}

