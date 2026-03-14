// unique_ptr6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "memory"
#include "vector"

class Weapon
{
private:
    int damage;
    char* name;
public:
    Weapon(int dmg, char* nom)
    {
        damage = dmg;
        name = new char[strlen(nom) + 1];
        strcpy(name, nom);
    }

    Weapon(const Weapon& weapon)
    {
        damage = weapon.damage;
        name = new char[strlen(weapon.name) + 1];
        strcpy(name, weapon.name);
    }

    void PrintDamage() const
    {
        std::cout << damage << "\n";
    }

    const char GetWeaponName() const 
    {
        return *name;
    }

    ~Weapon()
    {
        std::cout << "Weapon Destroyed" << "\n";
        delete[] name;
    }
};

class Player 
{
private:
    Weapon* ActiveWeapon = nullptr;
    std::vector<std::unique_ptr<Weapon>> WeaponArray;


};

int main()
{
    std::cout << "Hello World!\n";
}

