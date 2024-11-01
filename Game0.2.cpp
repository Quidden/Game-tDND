#include <iostream>
#include "Person.h"
#include "Item.h"
#include <string>
#include <cstdlib>
#include <ctime>
#include <memory> 
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

    srand(time(nullptr));

    GameC* Player = SelectingGameCharacter();
    cout << "Selected Character: " << Player->name << " - " << Player->description << endl;

    int Random_Value = RandomNumberDieValue();

    Battle(*Player);

    delete Player;
}

//Test
// if an object is required for a few function, create it in main
// if it's function specific create the object in a corresponding function