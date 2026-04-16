 // shared_ptr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>

// shared ptr
// allows copy and keeps ref count
// behaves like uniq ptr without copy

void PrintPtrVal(const std::shared_ptr<int>& ptr)
{
    // deref raw ptr even when const
    // no change in actual shared ptr, only raw data
    *ptr = 7;
    std::cout << "changed ptr value: " << *ptr.get() << "\n";
}

void PrintPtrVal(int *p,int&& q)
{
    // set raw ptr val to r value
    *p = q;
    std::cout << "changed ptr value: " << *p << "\n";
}


int main()
{
    std::shared_ptr<int> p = std::make_shared<int>(5);

    // get address of raw ptr
    std::cout << p.get() << "\n";

    // get value of raw ptr by deref
    std::cout << *p << "\n";

    // copy shared ptr
    PrintPtrVal(p);

    // set new val
    PrintPtrVal(p.get(), 12);

    // shared ptr shares raw ptr b/w each other
    std::shared_ptr<int> q = p;
    
    // set value in q
    PrintPtrVal(q.get(), 15);

    // print ptr value via p
    // q copies to p, same value
    std::cout << "p val: " << * p << "\n";

    p.reset();

    if (p)
    {
        std::cout << "initial ptr is still active" << "\n";
    }

    PrintPtrVal(q.get(), 20);

    q.reset();

    if (q)
    {
        std::cout << "initial ptr is still active" << "\n";
    }

}



