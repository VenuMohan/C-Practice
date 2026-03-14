// smartPointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <memory>

class Entity 
{
private:
    std::string str;

public:
    Entity(const std::string& _str)
    {
        str = _str;
    }

    void SetString(const std::string& _str)
    {
        str = _str;
    }

    const std::string& GetString() const 
    {
        return str;
    }

    void PrintString()
    {
        for (const char& c : str)
        {
            std::cout << c << " ";
        }
        std::cout << '\n';
    }

    ~Entity() { std::cout << GetString()<< ": " << "Entity Destroyed" << '\n'; }
};

int main()
{
    // stack and heap objects
    Entity* e = new Entity("Venu");
    Entity e1("Mohan");

    // unique ptr
    std::unique_ptr<Entity> e2(new Entity("Venu Mohan"));
    e2->PrintString();

    // unique ptr signature
    std::unique_ptr<Entity> e3 = std::make_unique<Entity>("Sinnu Boy");
    e3->PrintString();

    // shared ptr
    std::shared_ptr<Entity> e4 = std::make_shared<Entity>("Cowboy");
    // shared ptr copied like a shallow ptr
    // increases ref count
    std::shared_ptr<Entity> e5 = e4;

    e5->SetString("Wayne Mohane");
    e4->PrintString();

    std::shared_ptr<Entity> e6 = std::make_shared<Entity>("Wajid Mohd");
    {
        std::shared_ptr<Entity> e7 = e6;
        e7->SetString("Walid Mehd");
    }

    // e7 is destroyed here as its out of scope
    e6->PrintString();

    std::shared_ptr<Entity> e8 = std::make_shared<Entity>("Wun Macho");
    {
        // weak ptr assigned to share ptr
        // doesnt imcrease ref count
        //useful to store a ref to shared ptr 
        std::weak_ptr<Entity> e9 = e8;
    }
    
}

