#include <iostream>
#include "Person.h"
#include "Item.h"
#include <string>
#include <cstdlib>
#include <ctime>
#include <memory> 
#include "Inventory.h"
using namespace std;

GameC* SelectingGameCharacter();
int RundomNumberDieValue();
void Battle(GameC& Player);

int RandomNumberDieValue()
{
    return rand() % 100 + 1;
}

int main()
{
    Inventory inventory;

    ItemC* sword = new Weapon("Sword", "A sharp blade", 2, 100, 15, 1);
    ItemC* shield = new Weapon("Shield", "Provides protection", 1, 80, 0, 2);
    ItemC* healthPotion = new Health_PotkaC("Health Potion", "Restores health", 1, 50, 20);

    inventory.AddItem(sword);
    inventory.AddItem(shield);
    inventory.AddItem(healthPotion);

    std::cout << "Displaying inventory for the first time:" << std::endl;
    inventory.DisplayInventory();
    cin.get();

    srand(time(nullptr));

    GameC* Player = SelectingGameCharacter();
    if (Player != nullptr) 
    {
        std::cout << "Selected Character: " << Player->name << " - " << Player->description << std::endl;
    }
    else 
    {
        std::cout << "Player selection failed!" << std::endl;
        return 1; 
    }

    int Random_Value = RandomNumberDieValue();

    cin.get();
    std::cout << "Attempting to display inventory and player status:" << std::endl;
    inventory.DisplayInventory();
    Player->DisplayStatus();
    inventory.DisplayInventory();
    Player->DisplayStatus();
    std::cout << "Finished displaying inventory and player status." << std::endl;
    cin.get();

    std::cout << "Starting Battle..." << std::endl;
    Battle(*Player);

    delete Player;
    return 0;
}

//Test
// if an object is required for a few function, create it in main
// if it's function specific create the object in a corresponding function