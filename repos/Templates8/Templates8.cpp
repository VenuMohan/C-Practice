// Templates8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

// method to return last string
std::string Add(std::string str)
{
    return str;
}

// method to add multiple variables together
template<typename...Others>
std::string Add(std::string str, Others... others)
{
    return str + ", " + Add(others...);
}

int main()
{
    std::string s = "Venu";
    s = Add<std::string>(s, "Karthik", "Sanjay");
    std::cout << s << std::endl;

    std::string s1 = "0";
    for (short i = 1; i < 50; i++)
    {
        if (i % 3 == 0)
        {
            std::string iString = std::to_string(i);
            s1 = Add(s1, iString);
        }
    }
    std::cout << s1 << std::endl;

    // fibonacci seq with variadic templates 
    std::string s2 = "Venu";
    short j = 1;
    short k = 1;
    for (short i = 0; i <= 5; i++)
    {
        if (i == 5)
        {
            s2 = Add(s2, "Karthik");
            break;
        }

        short l = j + k;
        j = k;
        k = l;
        std::string lStr = std::to_string(l);
        s2 = Add(s2, lStr);
    }
    std::cout << s2 << std::endl;

    std::string s3 = "80";
    for (short i = 80; i >= 20; i--)
    {
        if (i == 20)
        {
            s3 = Add(s3, "Sanjay");
            break;
        }
        if (i % 5 == 0 || i % 50 <= 9)
        {
            std::string iStr = std::to_string(i);
            s3 = Add(s3, iStr);
        }
    }
    std::cout << s3 << std::endl;

    std::string s4 = Add(s2, s3);
    std::cout << std::endl;
    std::cout << s4 << std::endl;
}

