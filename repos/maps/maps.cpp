// maps.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <utility>

int main()
{
    std::vector<size_t> id;
    std::vector<std::string> names;
    std::map<size_t, std::string> NameMap = { {2317, "Prasanna"}, {2318, "Banaka"}, {2319, "Adarsh"}, {2320, "Venu"}, {2321, "Mouli"} };

    // prints the value associated with key
    std::cout << NameMap[2320] << std::endl;

    // prints key associated with value
    for (std::pair<size_t, std::string> p : NameMap)
    {
        if (p.second == "Prasanna")
        {
            std::cout << "id is " << p.first << std::endl;
        }
    }

    // change value associated with key
    NameMap[2321] = "Chetan";
    std::cout << NameMap[2321] << std::endl;

    // insert a key value pair
    NameMap.insert({ 2322, "Shaurya" });
    std::cout << NameMap[2322] << std::endl;

    // remove pair via key
    NameMap.erase(2319);

    std::cout << "modded map is " << std::endl;
    for (std::pair<size_t, std::string> p : NameMap)
    {
        std::cout << p.first << ", " << p.second << std::endl;
    }

    // add just a key without value
    NameMap[2323];
    std::cout << "modded map is " << std::endl;
    for (std::pair<size_t, std::string> p : NameMap)
    {
        std::cout << p.first << ", " << p.second << std::endl;
    }

    // size increses even with just value added
    std::cout << "size is " << NameMap.size() << std::endl;

    NameMap.clear();
    std::cout << "Map cleared, size : " << NameMap.size() << std::endl;
}

