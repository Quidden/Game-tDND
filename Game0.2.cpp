#include <iostream>
#include "Person.h"
#include "Item.h"
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

Game_Class* Selecting_A_Game_Character();
int Rundom_Number_Die_Value();
void Battle();

Knight_Class& Knight = Get_Knight_Obj();
Bandit_Class& Bandit = Get_Bandit_Obj();
Drow_Class& Drow = Get_Drow_Obj();

int Random_Number_Die_Value()
{
    return rand() % 100 + 1;
}

int main()
{
    Bastard_Class Bastard("Bastard", "Aggressive enemy", 100, 15, 5);

    srand(time(nullptr));

    Game_Class* Player = Selecting_A_Game_Character(Bastard);

    int Base_Damage = Player->Damage;  
    int Base_HP = Player->HP;
    int Base_Die_Bonus = Player->Die_Bonus;

    int Random_Value = Random_Number_Die_Value() + Player->Die_Bonus;

    Battle(Player);

}
// if an object is required for a few function, create it in main
// if it's function specific create the object in a corresponding function