// unique_ptr3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>

void PrintVal(int _p)
{
	std::unique_ptr<int> p = std::make_unique<int>(_p);
	// prints out hexadecimal address of p
	std::cout << p << "\n";
	// prints out actual val
	std::cout << *p << "\n";

	std::cout << sizeof(*p) << "\n";

	std::cout << "Move" << "\n";
	// unique ptr cannot be copied but can be moved
	std::unique_ptr<int> q = std::move(p);
	// p is nullptr 
	// data is moved from q to p, address moves as well
	std::cout << *q << "\n";
	std::cout << q << "\n";

	if (p != nullptr)
	{
		std::cout << p << "\n";
	}
}


int main()
{
	short i = 0;
	while (i < 2)
	{
		PrintVal(5);
		i++;
		// unique ptr gets deleted out of scope
	}
}


