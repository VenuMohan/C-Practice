// unique_ptr5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>

class Weapon 
{
private:
    int damage;
public:
    Weapon(int _dmg)
    {
        damage = _dmg;
    }

    Weapon(const Weapon& weapon)
    {
        damage = weapon.damage;
    }

    void SetDamage(const int& _dmg)
    {
        damage = _dmg;
    }

    void PrintDamage() const
    {
        std::cout << damage << "\n";
    }

    ~Weapon()
    {
        std::cout << "Weapon Destroyed" << "\n";
    }
};

class Player
{
private:
    std::unique_ptr<Weapon> CurrentWeapon;
public:
    Player(int dmg)
    {
        CurrentWeapon = std::make_unique<Weapon>(dmg);
    }

    ~Player()
    {
        std::cout << "Player Destroyed" << "\n";
    }

    Player(const Player& player)
    {
        CurrentWeapon = std::make_unique<Weapon>(*player.CurrentWeapon);
    }

    Player& operator = (const Player& other)
    {
        if (this != &other)
        {
            CurrentWeapon = std::make_unique<Weapon>(*other.CurrentWeapon);
        }
        return *this;
    }

    void SetCurrentWeapon(std::unique_ptr<Weapon> _weapon)
    {
        CurrentWeapon = std::move(_weapon);
    }

    void PrintCurrentWeaponDamage() const
    {
        std::cout << "Current Weapon Damage: ";
        CurrentWeapon->PrintDamage();
    }

    void SwapWeapons(std::unique_ptr<Weapon>& other)
    {
        std::swap(CurrentWeapon, other);
    }

    void SwapWeapons(Player& player)
    {
        std::swap(CurrentWeapon, player.CurrentWeapon);
    }

    // move constructor
    Player(Player&& player) noexcept = default;

    // move assignment
    Player& operator = (Player&& other) noexcept = default;

};


int main()
{
    std::unique_ptr<Weapon> groundWeapon = std::make_unique<Weapon>(100);
    std::unique_ptr<Weapon> groundWeapon2 = std::make_unique<Weapon>(200);

    Player player(50);
    Player player2(500);
    Player player3(1000);

    // std::move converts ground weapon to an r val which can be moved 
    player.SetCurrentWeapon(std::move(groundWeapon));
    player.PrintCurrentWeaponDamage();

    // swap weapons from ground
    player.SwapWeapons(groundWeapon2);
    player.PrintCurrentWeaponDamage();

    // swap weapons with player
    player.SwapWeapons(player2);
    player.PrintCurrentWeaponDamage();

    // player3 replaces player2
    player3 = std::move(player2);
    player3.PrintCurrentWeaponDamage();


}

