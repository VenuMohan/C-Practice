// maps2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <vector>

struct CityRecord 
{
    std::string name;
    uint32_t population;
    float latitude, longitude;

    // add constructor and default constructor to a struct if you want top use in a map 
    CityRecord() = default;
    CityRecord(const std::string& _name, uint32_t _population, float _latitude, float _longitude)
    {
        name = _name;
        population = _population;
        latitude = _latitude;
        longitude = _longitude;
    }

    bool operator==(const CityRecord& other) const
    {
        return name == other.name;
    }
};

namespace std 
{
    template<>
    struct hash<CityRecord>
    {
        // const func that doesnt chaange anything and returns a size_t
        // takes a const of the struct as city
        size_t operator()(const CityRecord& city) const noexcept 
        {
            // predefined hash functor in stl that takes a string and produces a size_t
            // internally hashes the name of the city
            return std::hash<std::string>()(city.name);
        }
    };


}

int main()
{
    std::vector<CityRecord> cityData;
    // push_back copies the object at the back
    // emplace_back directly constructs the object at the end of the vector
    cityData.emplace_back("Hyderabad", 10, 40.6f, 72.5f);
    cityData.emplace_back("Banglore", 12, 35.6f, 60.5f);
    cityData.emplace_back("Chennai", 8, 37.f, 60.f);
    cityData.emplace_back("Vizag", 5, 50.6f, 80.8f);
    cityData.emplace_back("Pune", 10, 51.2f, 75.4f);

    uint32_t pop = 0;
    for (const auto& city : cityData)
    {
        if (city.name == "Hyderabad")
        {
            pop = city.population;
            break;
        }
    }
    std::cout << "population: " << pop << '\n';

    // ordered map
    std::map<std::string, CityRecord> cityMap;

    // pair a string with a struct
    cityMap["HYD"] = CityRecord("Hyderabad", 10, 40.6f, 72.5f);
    cityMap["BANG"] = CityRecord("Banglore", 12, 35.6f, 60.5f);
    cityMap["CHEN"] = CityRecord("Chennai", 8, 37.f, 60.f);
    cityMap["VIZ"] = CityRecord("Vizag", 5, 50.6f, 80.8f);
    cityMap["PUN"] = CityRecord("Pune", 10, 51.2f, 75.4f);

    CityRecord& HydRecord = cityMap["HYD"];
    std::cout << HydRecord.population << '\n';

    // ordered map
    std::unordered_map<std::string, CityRecord> unCityMap;

    // pair a string with a struct
    unCityMap["HYD"] = CityRecord("Hyderabad", 10, 40.6f, 72.5f);
    unCityMap["BANG"] = CityRecord("Banglore", 12, 35.6f, 60.5f);
    unCityMap["CHEN"] = CityRecord("Chennai", 8, 37.f, 60.f);
    unCityMap["VIZ"] = CityRecord("Vizag", 5, 50.6f, 80.8f);
    unCityMap["PUN"] = CityRecord("Pune", 10, 51.2f, 75.4f);

    CityRecord& BangRecord = cityMap["BANG"];
    std::cout << BangRecord.population << '\n';

    // hashing a custom type
    std::unordered_map<CityRecord, uint16_t > cityYearMap;

    // value is identified by the hashed string used as key 
    cityYearMap[{"Hyderabad", 10, 40.6f, 72.5f}] = 1960;
    cityYearMap[{"Banglore", 12, 35.6f, 60.5f}] = 1955;

    auto year = cityYearMap.find({ "Hyderabad", 10, 40.6f, 72.5f });
    std::cout << year->second << '\n';

    // inserts as city record to the unordered map
    uint16_t& yr = cityYearMap[{"Vizag", 20, 20.f, 20.f}];
    //prints 0 as its unitialiased
    std::cout << yr << '\n';

    cityYearMap[{"Vizag", 20, 20.f, 20.f}] = 1971;
    uint16_t& yr1 = cityYearMap[{"Vizag", 0, 0, 0}];
    std::cout << yr1 << '\n';

    // insert city record with MUM as key
    CityRecord& MumbaiRecord = unCityMap["MUM"];
    std::cout << MumbaiRecord.name << '\n';

    // set MUM struct
    unCityMap["MUM"] = CityRecord{ "Mumbai", 30, 45.2f, 37.5f };
    std::cout << unCityMap["MUM"].name << "\n";

    // simple lookup using at
    // at doesnt insert elements unlike [] operator
    CityRecord& rec = unCityMap.at("BANG");
    std::cout << rec.name << '\n';

    // verify if value is present
    if (unCityMap.find("VIZ") != unCityMap.end())
    {
        CityRecord& rec = unCityMap.at("VIZ");
        std::cout << rec.name << '\n';
    }

    if (unCityMap.find("DEL") != unCityMap.end())
    {
        CityRecord& rec = unCityMap.at("DEL");
        std::cout << rec.name << '\n';
    }
    else 
    {
        std::cout << "city record not found" << '\n';
    }

    for (auto& [name, city] : unCityMap)
    {
        const std::string& _name = name;
        const CityRecord& rec = city;

        std::cout << _name << '\n';
        std::cout << rec.name << ", " << rec.population <<"\n";
    }

    std::cout << "\n";

    for (auto& [city, year] : cityYearMap)
    {
        const CityRecord& _city = city;
        int _year = year;

        std::cout << _city.name << ", " << _city.population << "\n";
        std::cout << year << '\n';
    }
}

