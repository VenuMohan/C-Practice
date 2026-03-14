// move2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

template <typename T>
class Entity 
{
private:
    T* data = nullptr;
    int size = 0;
public:

    // constructor
    Entity(const int& count, const T& entityData)
    {
        size = count;
        data = new T(entityData);
    }

    // copy constructor
    Entity(const Entity& other)
    {
        size = other.size;
        data = new T(*other.data);
    }

    // copy assignment
    Entity& operator = (const Entity& other)
    {
        if (this != &other)
        {
            delete data;
            size = 0;

            data = new T(*other.data);
            size = other.size;
        }
        return *this;
    }

    // move
    Entity(Entity&& other) noexcept
    {
        data = other.data;
        size = other.size;

        other.size = 0;
        other.data = nullptr;
    }


    const T& GetData() const  { return *data;}
    const int& GetSize() const { return size; }

    void SetData(const T& _data)
    {
        *data = _data;
    }

    ~Entity()
    {
        delete data;
    }


};

int main()
{
    std::cout << "Hello World!\n";

    Entity<float> e(5, 3.1417);
    std::cout <<"e: " << e.GetData() << std::endl;

    // stack object deep copy
    Entity<float> f = e;
    f.SetData(2.7527);
    std::cout << "f: " << f.GetData() << std::endl;

    // copy assignment
    Entity<float> g(8, 64);
    g = f;
    std::cout << "g: " << g.GetData() << std::endl;

    // move
    Entity<float> h = std::move(g);
    std::cout <<"h: " << h.GetData() << std::endl;

    // heap
    // heap shallow copy
    Entity<std::string>* p = new Entity<std::string>(7, "Chinnu");
    Entity<std::string>* q = p;
    q->SetData("Venu");
    std::cout << p->GetData() << '\n';
    std::cout << q->GetData() << '\n';

    // heap deep copy
    Entity<std::string>* r = new Entity<std::string>(*p);
    r->SetData("Cowboy");
    std::cout << r->GetData() << '\n';
    std::cout << p->GetData() << '\n';

    // copy assignment
    Entity<std::string>* s = new Entity<std::string>(8, "Mohan");
    std::cout << "before assign: " << s->GetData() << '\n';
    *s = *r;
    std::cout << r->GetData() << '\n';
    std::cout << "after assign: " << s->GetData() << '\n';

    // move
    Entity<std::string>* t = new Entity<std::string>(std::move(*p));
    std::cout << t->GetData() << '\n';

    delete r;
    delete p;
    //delete q;
    delete s;
    delete t;
}

