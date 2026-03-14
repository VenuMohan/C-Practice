// templateClass3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

template<typename T1, typename T2>
class A
{
private:
    T1 t1;
    T2 t2;
public:
    A(const T1& _t1, const T2& _t2)
    {
        t1 = _t1;
        t2 = _t2;
    }

    T1 sum(const T1& t1, const T2& t2)
    {
        return t1 + t2;
    }

    T1 sum()
    {
        return t1 + t2;
    }
};

int main()
{
    // set in class
    std::cout << "float , int" << std::endl;
    A<float, int> a(6.8, 2);
    std::cout<< a.sum() << std::endl;
    // set const from here
    std::cout << a.sum(9.4, 5) << std::endl;

    std::cout << "int, int" << std::endl;
    A<int, int> b(6.8, 2);
    std::cout << b.sum() << std::endl;
    std::cout << b.sum(9.4, 5) << std::endl;
}
