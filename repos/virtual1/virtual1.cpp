// virtual1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Entity 
{
public:
    // keyword virtual generates a vtable for the function   
    virtual std::string GetName() 
    {
        return "Name";
    }
};

class Player : public Entity 
{
private:
    std::string Name;
public:
    
    Player(std::string& _name)
    {
        Name = _name;
    }

    // setting function as override means that the child function overrides the parent 
    std::string GetName() override
    {
        return Name;
    }
};

void PrintName(Entity* entity)
{
    // executes the function in entity only, not its child classes
    std::cout << entity->GetName() << std::endl;
}

int main()
{
    Entity* entityObj = new Entity();
    std::cout << entityObj->GetName() << std::endl;

    std::string PlayerName;
    std::cout << "Enter the player name" << std::endl;
    std::cin >> PlayerName;

    Player* player = new Player(PlayerName);
    std::cout << "Player Name : " << player->GetName() << std::endl;

    PrintName(entityObj);
    PrintName(player);
}
