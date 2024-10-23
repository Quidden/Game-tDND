#include <iostream>
#include "Person.h"
#include "Item.h"
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

Game_Class& Selecting_A_Game_Character();
int Rundom_Number_Die_Value();
void Battle(Game_Class& Player);

int Random_Number_Die_Value()
{
    return rand() % 100 + 1;
}

int main()
{

    srand(time(nullptr));

    Game_Class& Player = Selecting_A_Game_Character();
    cout << "Selected Character: " << Player.Name << " - " << Player.Description << endl;

    int Random_Value = Random_Number_Die_Value();

    Battle(Player);

}


// if an object is required for a few function, create it in main
// if it's function specific create the object in a corresponding function