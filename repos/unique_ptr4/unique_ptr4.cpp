// unique_ptr4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
#include <vector>

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

	Weapon(const Weapon& other)
	{
		dmg = other.dmg;
	}

	~Weapon()
	{
		std::cout << "Weapon Destroyed" << "\n";
	}

	void SetDamage(const int& _dmg)
	{
		dmg = _dmg;
	}

	void PrintDamage() const
	{
		std::cout << "Damage is " << dmg << "\n";
	}
};

void func(std::unique_ptr<Weapon> weapon)
{
	weapon->SetDamage(100);
	weapon->PrintDamage();
}

std::unique_ptr<Weapon> GetWeapon(int dmg)
{
	std::unique_ptr<Weapon> w = std::make_unique<Weapon>(dmg);
	return w;
}

int main()
{
   // one object owned by one uniq ptr within a scope
	std::unique_ptr<Weapon> wp1 = std::make_unique<Weapon>(20);
	std::unique_ptr<Weapon> wp2 = std::move(wp1);


	// release makes uniq ptr give up ownership of object
	Weapon* wp = wp2.release();
	wp->SetDamage(40);
	wp->PrintDamage();

	delete wp;

	std::unique_ptr<Weapon> wp3 = std::make_unique<Weapon>(80);
	wp3->PrintDamage();

	// destroy old obj and create new
	wp3 = std::make_unique<Weapon>(20);
	wp3->PrintDamage();

	// reset uniq ptr with raw ptr
	wp3.reset(new Weapon(40));
	wp3->PrintDamage();

	// set dmg values to new uni ptr
	wp3->SetDamage(160);
	wp3->PrintDamage();

	// move uniq ptr
	// helpful in mem managment as ptr is not copied
	func(move(wp3));
	if (!wp3)
	{
		// wp3 becomes null
		std::cout << "uniq ptr destroyed out of scope " << "\n";
	}

	// returns a uniq ptr weapon with dmg 80
	std::unique_ptr<Weapon> w4 = GetWeapon(80);
	w4->PrintDamage();


	std::vector<std::unique_ptr<Weapon>> weaponArray;
	std::vector<std::unique_ptr<Weapon>> weaponArray1;

	int vectorLen = 5;
	for (int i = 0; i < vectorLen; i++)
	{
		weaponArray.push_back(std::make_unique<Weapon>(80));
	}

	for (const std::unique_ptr<Weapon>& weapon : weaponArray)
	{
		int i = 1;
		weapon->SetDamage(20 * i * i);
		i++;
	}

	for (auto& weapon : weaponArray)
	{
		weaponArray1.push_back(std::move(weapon));
	}

	std::cout << "Weapon array transferred" << "\n";

	for (auto& weapon : weaponArray1)
	{
		weapon->PrintDamage();
	}


}

