// unique_ptr6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <cstdlib>

class Weapon
{
private:
    int damage;
    std::string name;
public:
    Weapon(int dmg, std::string nom)
    {
        damage = dmg;
        name = nom;
    }

    Weapon(const Weapon& weapon)
    {
        damage = weapon.damage;
        name = weapon.name;
    }

    void PrintDamage() const
    {
        std::cout << damage << "\n";
    }

    const std::string& GetWeaponName() const 
    {
        return name;
    }

    ~Weapon()
    {
        std::cout << "Weapon Destroyed" << "\n";
    }
};

class Player 
{
private:
    Weapon* activeWeapon = nullptr;
    std::vector<std::unique_ptr<Weapon>> WeaponArray;

public:

    void AddWeapon(std::unique_ptr<Weapon> wp)
    {
        if (!wp) { return; }

        // check if weapon already exists
        for (const auto& weapon : WeaponArray)
        {
            if (weapon.get() == wp.get())
            {
                return;
            }
        }

        // add to inventory by move
        WeaponArray.push_back(std::move(wp));
        std::cout << "Added to weapon array" << "\n";
    }

    void EquipWeapon(const std::string& name)
    {
        // check if weapon exists
        for (const auto& weapon : WeaponArray)
        {
            if (weapon->GetWeaponName() == name)
            {
                // equip the existing weapon
                activeWeapon = weapon.get();
                std::cout << "Equipped Existing Weapon" << "\n";
                return;
            }
        }

    }

    void PickupWeapon(std::unique_ptr<Weapon> wp)
    {
        if (!wp) { return; }

        for (const auto& weapon : WeaponArray)
        {
            if (weapon->GetWeaponName() == wp->GetWeaponName())
            {
                std::cout << "Weapon already in vault" << "\n";
                activeWeapon = weapon.get();
                return;
            }
        }

        // weapon not in inventory
        Weapon* weapon = wp.get();

        // add to inventory
        WeaponArray.push_back(std::move(wp));

        activeWeapon = weapon;

        std::cout << "Picked up weapon and made it active" << "\n";
    }

    void DropWeapon(Weapon* wp)
    {
        if (!wp) { return; }

        for (auto it = WeaponArray.begin(); it != WeaponArray.end(); ++it)
        {
            if (it->get() == wp)
            {
                // check if active
                bool isActiveWeapon = (activeWeapon == wp);

                // erase weapon
                WeaponArray.erase(it);

                std::cout << "Dropped Weapon" << "\n";

                if (isActiveWeapon)
                {
                    if (!WeaponArray.empty())
                    {
                        int randomIndex = rand() % WeaponArray.size();
                        activeWeapon = WeaponArray[randomIndex].get();
                        std::cout << "Switched to other active weapon\n";
                    }
                    else
                    {
                        activeWeapon = nullptr;
                        std::cout << "No weapons left" << "\n";
                    }
                }
                
                return;
            }
        }

        std::cout << "Weapon not found" << "\n";
    }

    void SwapWeapon(std::unique_ptr<Weapon> other)
    {
        if (!other) { return; }

        // if no active weapon, just pickup
        if (!activeWeapon) 
        {
            activeWeapon = other.get();
            WeaponArray.push_back(std::move(other));
            std::cout << "Pickup up weapon" << "\n";
        }

        //if there is active weapon
        // search through inventory
        for (auto it = WeaponArray.begin(); it != WeaponArray.end(); ++it)
        {
            // check for active weapon
            if (it->get() == activeWeapon)
            {
                // get the weapon at iterator
                std::unique_ptr<Weapon> WeaponToBeDropped = std::move(*it);

                // replace weapon at iterator with ground weapon
                *it = std::move(other);

                // set active weapon
                activeWeapon = it->get();

                std::cout << "Swapped Active Weapon" << "\n";
            }
           
        }

        return;
    }

    void SwapWeapon(Player& player)
    {
       
    }

    void ShowInventory() const
    {
        
    }


};

int main()
{
    std::cout << "Hello World!\n";
}

