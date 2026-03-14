// unique_ptr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>

class Weapon 
{
private :
    int dmg;

public:

    Weapon(const int& _dmg)
    {
        std::cout << "Weapon created" << "\n";
        dmg = _dmg;
    }

    ~Weapon()
    {
        std::cout << "Weapon destroyed" << "\n";
    }

    void PrintDamage() const
    {
        std::cout << "Damage:" << dmg << "\n";
    }

    void SetDamage(const int& _dmg)
    {
        dmg = _dmg;
    }
};

int main()
{
    std::unique_ptr<Weapon> wp = std::make_unique<Weapon>(10);
    wp->PrintDamage();

    // uses move cons
    std::unique_ptr<Weapon> wp1 = std::move(wp);
    wp1->SetDamage(20);
    wp1->PrintDamage();
    //wp->PrintDamage();

    std::unique_ptr<Weapon> wp2 = std::make_unique<Weapon>(40);
    // move assign op
    wp2 = std::move(wp1);

    wp2->SetDamage(80);
    wp2->PrintDamage();
}

