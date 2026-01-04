// pureVirtual2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class convert 
{
protected:
    float val1;
    float val2;
    float val3;
public:
    convert(float i)
    {
        // set value of val1
        val1 = i;
    }

    float getConv() { return val2; }
    float getInt() { return val1; }
    virtual void ShowVal3() 
    {
        std::cout << "There is no third value" << std::endl;
    }

    virtual void compute() = 0;
};

class l_to_g : public convert
{
public:
    // inherited constructor
    l_to_g(float f) : convert(f){}
    void compute()
    {
        // convert liters to gallons
        val2 = val1 / 3.784;
    }
};

class f_to_c : public convert
{
public:
    f_to_c(float f) : convert(f){}
    void compute()
    {
        val2 = (val1 - 32) / 1.8;
    }

    void ShowVal3() override 
    {
        val3 = val1 + 273;
        std::cout << "Kelvin: " << val3 << std::endl;
    }
};

class kg_to_p : public convert
{
public :
    kg_to_p(float kg) : convert(kg){}
    void compute()
    {
        val2 = val1 / 2.2;
    }
};

int main()
{
    convert* p;

    float l;
    std::cout << "Enter the liters" << std::endl;
    std::cin >> l;

    float f;
    std::cout << "Enter the temp in farenheit" << std::endl;
    std::cin >> f;

    float kg;
    std::cout << "Enter the weight in kg" << std::endl;
    std::cin >> kg;

    // objects of class l_to_g and f_to_c
    l_to_g ltogObj(l);
    f_to_c ftocObj(f);
    kg_to_p kgtopObj(kg);

    p = &ltogObj;
    std::cout << "liters: " << p->getInt() << std::endl;
    p->compute();
    std::cout << "gallons: " << p->getConv() << std::endl;

    p = &ftocObj;
    std::cout << "farenheit: " << p->getInt() << std::endl;
    p->compute();
    std::cout << "celcius: " << p->getConv() << std::endl;
    p->ShowVal3();

    p = &kgtopObj;
    std::cout << "kg: " << p->getInt() << std::endl;
    p->compute();
    std::cout << "pounds: " << p->getConv() << std::endl;
    p->ShowVal3();
}
 