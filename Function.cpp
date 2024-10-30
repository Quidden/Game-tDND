#include <Iostream>
#include <conio.h>
#include <Windows.h>
#include "Person.h"

using namespace std;

void SetTextColor(int color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

void TextToConfirmTheSelection()
{
	cout << "If you really want to play as this character press 1" << endl;
	cout << "If you want to change your character press 2" << endl;
}

void HeroInfoSelecting(GameClass* temp, int& Subverification)
{
	temp->DisplayStatus();
	cout << temp->Description << endl;
	cout << endl;
	TextToConfirmTheSelection();

	cin >> Subverification;
	if(Subverification != 1)
	{
		delete temp;
	}
}

GameClass* SelectingGameCharacter()
{

	int Subverification = 2;
	GameClass* temp = nullptr;

	while (Subverification == 2)
	{
		system("cls");

		cout << "Please choose your character:" << endl;
		cout << "1. Bastard" << endl;
		cout << "2. Knight" << endl;
		cout << "3. Bandit" << endl;
		cout << "4. Drow" << endl;
		cout << "Enter your choice (1-4): ";
		cout << endl;

		int choice = 0;
		cin >> choice;

		system("cls");

		switch (choice)
		{
		case 1:
		{
			
			temp = new BastardClass("Bastard", "A relentless and aggressive enemy who fights with brute strength and little regard for anything but victory.", 100, 15, 5);
			break;
		}
		case 2:
		{
			temp = new KnightClass("Knight", "A noble and honorable warrior, dedicated to defending the weak and striking down evil with formidable might and resilience.", 110, 20, 10);
			break;	
		}
		case 3:
		{
			temp = new BanditClass("Bandit", " A cunning and ruthless rogue, skilled in ambushes and quick attacks, always searching for an opportunity to take advantage.", 90, 10, 5);
			break;
		}
		case 4:
		{
			temp = new DrowClass("Drow", "A shadowy figure from the depths, mysterious and dangerous, using dark arts and stealth to overcome opponents.", 120, 10, 5);
			break;
		}
		default:
			system("cls");
			break;
		}
		if(temp != nullptr)
		{
			cout << "You've chosen a hero " << temp->Name << endl;
			HeroInfoSelecting(temp, Subverification);
		}
		system("cls");
	}
	return temp;
}

void TheEnemyMove(GameClass& Player, EnemyClass& Enemy)
{

	if (!Player.SkipHod)
	{
		cout << "" << endl;
		SetTextColor(12);
		cout << "Enemy's move" << endl;
		cout << "" << endl;

		Player.HP -= Enemy.Damage;
		SetTextColor(12);
		Enemy.DisplayStatus();
		SetTextColor(10);
		Player.DisplayStatus();
	}
	else
	{
		SetTextColor(3);
		cout << "Enemy is stunned and cannot take damage this turn" << endl;
	}

	if (!Player.IsAlive())
	{
		SetTextColor(6);
		cout << Enemy.Name << " You are defeated" << endl;
	}
}

void ThePlayerMove(GameClass& Player, EnemyClass& Enemy)
{
	cout << "" << endl;
	SetTextColor(10);
	cout << "Player's move" << endl;
	cout << "" << endl;

	Player.Abilites();

	Enemy.HP -= Player.Damage;
	SetTextColor(10);
	Player.DisplayStatus();

	if (Enemy.IsAlive())
	{
		SetTextColor(12);
		Enemy.DisplayStatus();
	}
	else
	{
		SetTextColor(6);
		cout << Enemy.Name << " defeated! You've won!" << endl;
	}
}

void Battle(GameClass& Player)
{
	system("cls");

	EnemyClass   Goblin("Goblin", "asdasdasd", 100, 10, 5, 1);
	EnemyClass   Skeleton("Skeleton", "asdasdasd", 100, 10, 5, 1);
	EnemyClass   Dark("Dark", "asdasdasd", 100, 10, 5, 1);
	EnemyClass   Shadow("Shadow", "asdasdasd", 100, 10, 5, 1);
	EnemyClass   King("King", "asdasdasd", 100, 10, 5, 1);

	EnemyClass& Enemy = Goblin;
	
	cout << "A fight breaks out between "<< Player.Name << " end "<< Enemy.Name << endl;
	cout << "To make a move in a battle press 'Enter'" << endl;

	cin.get();
	
	//Initialization_Check(Player, Enemy);

	while (Player.IsAlive() && Enemy.IsAlive() && !Player.ExitTheBattle)
	{

        ThePlayerMove(Player, Enemy);
		cin.get();

		if (Player.Name == "Bastard" && dynamic_cast<BastardClass*>(&Player)->ExitTheBattle)
		{
			break;
		}

		if (Player.Name == "Knight")
		{
			Player.SkipHod = dynamic_cast<KnightClass*>(&Player)->SkipHod;
		}

		if (Enemy.IsAlive())
		{
			TheEnemyMove(Player, Enemy);
			cin.get();
		}
		system("cls");
	}
	SetTextColor(7);
}