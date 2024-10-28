#include <Iostream>
#include <conio.h>
#include <Windows.h>
#include "Person.h"

using namespace std;
//void Initialization_Check(Game_Class Player, Enemy_Class Enemy)
//{
//	if (Player == nullptr || Enemy == nullptr)
//	{
//		std::cerr << "Player or Enemy is not initialized!" << std::endl;
//		return;
//	}
//}

//void charter()
//{
//	Bastard_Class Bastard("Bastard", "Aggressive enemy", 100, 15, 5);
//	Knight_Class  Knight("Knight", "asdasd", 110, 20, 10);
//	Bandit_Class  Bandit("Bandit", "aspfoasf", 90, 10, 5);
//	Drow_Class    Drow("Drow", "Shadowy figure", 120, 10, 5);
//}

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
			cout << "You've chosen a hero Bastard" << endl;
			BastardClass* temp = new BastardClass("Bastard", "A relentless and aggressive enemy who fights with brute strength and little regard for anything but victory.", 100, 15, 5);
			HeroInfoSelecting(temp, Subverification);
			if (Subverification == 1)
			{
				return temp;
			}
			system("cls");
			break;
		}
		case 2:
		{
			cout << "You've chosen a hero Knight" << endl;
			KnightClass* temp = new KnightClass("Knight", "A noble and honorable warrior, dedicated to defending the weak and striking down evil with formidable might and resilience.", 110, 20, 10);
			HeroInfoSelecting(temp, Subverification);
			if (Subverification == 1)
			{
				return temp;
			}
			system("cls");
			break;	
		}
		case 3:
		{
			cout << "You've chosen a hero Bandit" << endl;
			BanditClass* temp = new BanditClass("Bandit", " A cunning and ruthless rogue, skilled in ambushes and quick attacks, always searching for an opportunity to take advantage.", 90, 10, 5);
			HeroInfoSelecting(temp, Subverification);
			if (Subverification == 1)
			{
				return temp;
			}
			system("cls");
			break;
		}
		case 4:
		{
			cout << "You've chosen a hero Drow" << endl;
			DrowClass* temp = new DrowClass("Drow", "A shadowy figure from the depths, mysterious and dangerous, using dark arts and stealth to overcome opponents.", 120, 10, 5);
			HeroInfoSelecting(temp, Subverification);
			if (Subverification == 1)
			{
				return temp;
			}
			system("cls");
			break;
		}
		default:
			cout << "Invalid choice. Please choose between 1-4." << endl;
			system("cls");
			break;
		}
	}
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