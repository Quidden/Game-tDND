#include <iostream>
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

void HeroInfoSelecting(PlayerC* temp, int& Subverification)
{
	temp->DisplayStatus();
	cout << temp->description << endl;
	cout << endl;
	TextToConfirmTheSelection();

	cin >> Subverification;
	if(Subverification != 1)
	{
		delete temp;
	}
}

PlayerC* SelectingGameCharacter()
{

	int Subverification = 2;
	PlayerC* temp = nullptr;

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

			temp = new BastardC("Bastard", "A relentless and aggressive enemy who fights with brute strength and little regard for anything but victory.", 100, 15, 5, CharacterType::Bastard);
			break;
		}
		case 2:
		{
			temp = new KnightC("Knight", "A noble and honorable warrior, dedicated to defending the weak and striking down evil with formidable might and resilience.", 110, 20, 10, CharacterType::Knight);
			break;
		}
		case 3:
		{
			temp = new BanditC("Bandit", " A cunning and ruthless rogue, skilled in ambushes and quick attacks, always searching for an opportunity to take advantage.", 90, 10, 5, CharacterType::Bandit);
			break;
		}
		case 4:
		{
			temp = new DrowC("Drow", "A shadowy figure from the depths, mysterious and dangerous, using dark arts and stealth to overcome opponents.", 120, 10, 5, CharacterType::Drow);
			break;
		}
		default:
			system("cls");
			break;
		}
		if(temp != nullptr)
		{
			cout << "You've chosen a hero " << temp->name << endl;
			HeroInfoSelecting(temp, Subverification);
		}
		system("cls");
	}
	return temp;
}

void TheEnemyMove(PlayerC& Player, EnemyC& Enemy)
{

	if (!Player.skip_hod)
	{
		cout << "" << endl;
		SetTextColor(12);
		cout << "Enemy's move" << endl;
		cout << "" << endl;

		Player.hp -= Enemy.damage;
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
		cout << Enemy.name << " You are defeated" << endl;
	}
}

void ThePlayerMove(PlayerC& Player, EnemyC& Enemy)
{
	cout << "" << endl;
	SetTextColor(10);
	cout << "Player's move" << endl;
	cout << "" << endl;

	Player.Abilites();

	Enemy.hp -= Player.damage;
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
		cout << Enemy.name << " defeated! You've won!" << endl;
	}
}

void Battle(PlayerC& Player)
{
	system("cls");

	EnemyC   Goblin("Goblin", "asdasdasd", 100, 10, 5, 1);
	EnemyC   Skeleton("Skeleton", "asdasdasd", 100, 10, 5, 1);
	EnemyC   Dark("Dark", "asdasdasd", 100, 10, 5, 1);
	EnemyC   Shadow("Shadow", "asdasdasd", 100, 10, 5, 1);
	EnemyC   King("King", "asdasdasd", 100, 10, 5, 1);

	EnemyC& Enemy = Goblin;

	cout << "A fight breaks out between "<< Player.name << " end "<< Enemy.name << endl;
	cout << "To make a move in a battle press 'Enter'" << endl;

	cin.get();

	//Initialization_Check(Player, Enemy);

	while (Player.IsAlive() && Enemy.IsAlive() && !Player.exit_the_battle)
	{

        ThePlayerMove(Player, Enemy);
		cin.get();

		if (Player.name == "Bastard" && dynamic_cast<BastardC*>(&Player)->exit_the_battle)
		{
			break;
		}

		if (Player.name == "Knight")
		{
			Player.skip_hod = dynamic_cast<KnightC*>(&Player)->skip_hod;
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