#include <iostream>
#include "Person.h"
#include "Item.h"
#include <string>
#include <cstdlib>
#include <ctime>
#include <memory> 
using namespace std;

GameClass* SelectingGameCharacter();
int RundomNumberDieValue();
void Battle(GameClass& Player);

int Random_Number_Die_Value()
{
    return rand() % 100 + 1;
}

int main()
{

    srand(time(nullptr));

    GameClass* Player = SelectingGameCharacter();
    cout << "Selected Character: " << Player->Name << " - " << Player->Description << endl;

    int Random_Value = Random_Number_Die_Value();

    Battle(*Player);

    delete Player;
}


// if an object is required for a few function, create it in main
// if it's function specific create the object in a corresponding function