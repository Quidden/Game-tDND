#include <iostream>
#include "Person.h"
#include "Item.h"
#include <string>
#include <cstdlib>
#include <ctime>
#include "Inventory.h"
#include "Function.h"

using namespace std;

int RandomNumberDieValue()
{
    return rand() % 100 + 1;
}

int main()
{
    Inventory inventory;

    ItemC* sword = new Weapon("Sword", "A sharp blade", 2, 100, 15, 1, WeaponType::Sword);
    ItemC* bow = new Weapon("Bow", "A ranged weapon", 3, 120, 10, 2, WeaponType::Bow);
    ItemC* healthPotion = new Health_PotkaC("Health Potion", "Restores health", 1, 50, 20);

    srand(time(nullptr));

    PlayerC* Player = SelectingGameCharacter();
    if (Player != nullptr) 
    {
        std::cout << "Selected Character: " << Player->name << " - " << Player->description << std::endl;
    }
    else 
    {
        std::cout << "Player selection failed!" << std::endl;
        return 1; 
    }

    cin.get();
    inventory.AddItem(healthPotion, Player);
    inventory.AddItem(sword, Player);
    inventory.AddItem(bow, Player);
    cin.get();
    inventory.DisplayInventory();
    cin.get();

    std::cout << "Starting Battle..." << std::endl;
    Battle(*Player);

    delete Player;
    return 0;
}

//Test
// if an object is required for a few function, create it in main
// if it's function specific create the object in a corresponding function