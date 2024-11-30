#include <iostream>
#include "Person.h"
#include "Item.h"
#include <string>
#include <cstdlib>
#include <ctime>
#include "Function.h"

using namespace std;

int RandomNumberDieValue()
{
    return rand() % 100 + 1;
}

int main()
{

    Equipted_Items_Base* bow = new Equipten_Weapon_Class("Bow", "A ranged weapon", 3, 120, 10, Equipted_Item_Type::Bow);
    ItemC* healthPotion = new Health_PotkaC("Health Potion", "Restores health", 1, 50, 20);
    Equipted_Items_Base* sword = new Equipten_Weapon_Class("Sword", "A sharp blade", 2, 100, 15, Equipted_Item_Type::Sword);
    std::cout << "Created Sword with type: " << static_cast<int>(sword->Item_Type) << std::endl;

    cin.get();
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

    Player->inventory.AddItem(bow);
    Player->inventory.AddItem(sword);
    Player->inventory.AddItem(healthPotion);

    InventoryRealization(*Player);

    cin.get();
    Player->DisplayStatus();
    cin.get();

    cin.get();
    std::cout << "Starting Battle..." << std::endl;
    Battle(*Player);

    delete Player;
    return 0;
}

//Test
// if an object is required for a few function, create it in main
// if it's function specific create the object in a corresponding function