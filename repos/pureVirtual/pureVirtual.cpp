// pureVirtual.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class number {
protected:
    int val;

public:
    virtual void SetVal(int i)
    {
        val = i;
    }

    // pure virtual function
    virtual void ShowVal() = 0;
};

class hexType : public number 
{
public:
    void ShowVal()
    {
        std::cout << val << std::endl;
    }
};

class decType : public number
{
public:
    void SetVal(int i) override 
    {
        // fixed value for int
        val = 10;
    }

    void ShowVal()
    {
        std::cout << val << std::endl;
    }
};

class octType : public number 
{
public:

    // change value of variable by overriding function
    void SetVal(int i) override
    {
        val = i * 10;
    }

    void ShowVal()
    {
        std::cout << val << std::endl;
    }
};


int main()
{
    hexType h;
    decType d;
    octType o;

    int hVal, dVal, oVal;
    std::cout << "Enter the hextype, dectype and octtype values" << std::endl;
    std::cin >> hVal;
    std::cin >> dVal;
    std::cin >> oVal;

    h.SetVal(hVal);
    h.ShowVal();

    d.SetVal(dVal);
    d.ShowVal();

    o.SetVal(oVal);
    o.ShowVal();
}
