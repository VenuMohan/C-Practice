// uniqueptr2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>

class Weapon
{
private:
    int dmg;

public:

    Weapon(int _dmg)
    {
        std::cout << "Weapon created" << "\n";
        dmg = _dmg;
    }

    // copy constructor
    Weapon(const Weapon& other)
    {
        dmg = other.dmg;
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


class Player
{
private:
    std::unique_ptr<Weapon> weapon;
public:

    Player(int dmg)
    {
        // calls weapon constructor
        weapon = std::make_unique<Weapon>(dmg);
    }

    // deep copy 
    Player(const Player& other)
    {
        // calls weapon copy constructor
        weapon = std::make_unique<Weapon>(*other.weapon);
    }

    // copy assignment
    Player& operator = (const Player& other)
    {
        if (this != &other)
        {
            weapon = std::make_unique<Weapon>(*other.weapon);
        }
        return *this;
    }

    // move constructor
    // unique ptr moves itself
    Player(Player&& other) noexcept = default;

    Player& operator = (Player&& other) noexcept = default;

    /*Player(Player&& other) noexcept
    {
        weapon = std::move(other.weapon);
    }*/

    void Print() const
    {
        weapon->PrintDamage();
    }
   
};

int main()
{
    std::unique_ptr<Weapon> wp = std::make_unique<Weapon>(5);
    wp->SetDamage(20);

    std::unique_ptr<Weapon> wp1 = std::move(wp);
    wp1->PrintDamage();

    std::unique_ptr<Weapon> wp2 = std::make_unique<Weapon>(40);
    wp2 = std::move(wp1);
    wp2->PrintDamage();

    Player* player1 = new Player(40);

    // deep copy
    Player* player2 = new Player(*player1);
    player2->Print();

    // copy assign
    Player* player3 = new Player(80);
    *player3 = *player2;
    player3->Print();

    // move
    Player* player4 = new Player(std::move(*player3));
    player4->Print();

    // move assign
    Player* player5 = new Player(100);
    *player5 = std::move(*player4);
    player5->Print();

    delete player5;
    delete player2;
    delete player1;
    delete player3;
    delete player4;
}

