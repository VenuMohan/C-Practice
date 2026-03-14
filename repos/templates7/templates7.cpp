// templates7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

template<typename T>
T Add(T t)
{
    return t;
}

template <typename T, typename ...Others>
T Add(T t, Others... others)
{
    return t + Add<T>(others...);
}

std::string Cancatenate(std::string t)
{
    return t;
}

template <typename...Others>
std::string Cancatenate(std::string str, Others... others)
{
    return str + ", " + Cancatenate(others...);
}
int main()
{
    // for string, the type should be explicitly mentioned
    std::cout << Add<std::string>("Venu", "Sanjay", "Karthik") << std::endl;

    //cancatenate strings
    std::string str;
    for (short i = 0; i < 10; i++)
    {
        std::string iString = std::to_string(i);
        str = Add<std::string>(str, iString);
    }

    std::cout << str << std::endl;

    std::cout << std::endl;

    // add strings at indices
    std::string s1 = "Venu";
    for (short i = 1; i <= 10; i++)
    {
        if (i == 10)
        {
            s1 = Add<std::string>(s1, "Karthik");
            break;
        }
        std::string iString = std::to_string(i);
        s1 = Add<std::string>(s1, iString);

    }

    std::cout << s1 << std::endl;

    std::string s2;
    for (short i = 11; i <= 20; i++)
    {
        if (i == 20)
        {
            s2 = Add<std::string>(s2, "Sanjay");
            break;
        }

        std::string iString = std::to_string(i);
        s2 = Add<std::string>(s2, iString);

    }

    std::string s3 = Add<std::string>(s1, s2);
    std::cout << s3 << std::endl;

    for (char c : s3)
    {
        std::string _s = ", ";
        s3 = Add<std::string>(s3, _s);
    }

    std::cout << s3 << std::endl;

    std::string s4 = Cancatenate<std::string>(s1, s2);
    std::cout << s4 << std::endl;

    
}

