// virtual2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Animal
{
public:
    std::string sound;
    Animal(std::string& _sound)
    {
        sound = _sound;
    }
    virtual void MakeSound()
    {
        std::cout << sound << std::endl;
    }

    virtual void Walk()
    {
        std::cout << "Stomp" << std::endl;
    }

    void Eat() 
    {
        std::cout << "nom nom" << std::endl;
    }

    virtual void Fly()
    {
        std::cout << "Cant fly " << std::endl;
    }

};

class Cow : public  Animal
{
public:
    Cow(std::string& _sound) :Animal(_sound){ }
    void MakeSound() override
    {
        std::cout << sound << std::endl;
    }

};

class Crow : public Animal
{
public:
    Crow(std::string& _sound) : Animal(_sound){}
    void Fly() override
    {
        std::cout << "Flyyyy" << std::endl;
    }
};

class Horse : public Animal
{
public:
    Horse(std::string& _sound) : Animal(_sound){}
    void MakeSound() override
    {
        std::cout << sound << std::endl;
    }

    void Walk() override
    {
        std::cout << "Hoof " << std::endl;
    }
};

void AnimalFunctions(Animal* animal)
{
    animal->Eat();
    animal->Fly();
    animal->MakeSound();
    animal->Walk();
}

int main()
{
    int a;
    std::cout << "Enter the value" << std::endl;
    std::cin >> a;

    Animal* animal;
    std::string cowSound = "Moo";
    std::string CrowSound = "Kawww";
    std::string HorseSound = "Neeiggghh";
    std::string AnimalSound = "Oooo";

    switch (a)
    {
    case(1):
        animal = new Cow(cowSound);
        AnimalFunctions(animal);
        break;
    case(2):
        animal = new Crow(CrowSound);
        AnimalFunctions(animal);
        break;
    case(3):
        animal = new Horse(HorseSound);
        AnimalFunctions(animal);
        break;
    default:
        animal = new Animal(AnimalSound);
        AnimalFunctions(animal);
        break;
    }
}

