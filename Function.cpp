#include <Iostream>
#include <conio.h>
#include <Windows.h>
#include "Person.h"

using namespace std;

bool Exit_the_battle = false;
bool Skip_Hod = false;

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

void Text_To_Confirm_The_Selection()
{
	cout << "If you really want to play as this character press 1" << endl;
	cout << "If you want to change your character press 2" << endl;
}

Game_Class* Selecting_A_Game_Character()
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
			Bastard_Class* temp = new Bastard_Class("Bastard", "Aggressive enemy", 100, 15, 5);
			temp->Display_Status();
			cout << endl;
			Text_To_Confirm_The_Selection();

			cin >> Subverification;
			if (Subverification == 1)
			{
				return temp; 
			}
			else
			{
				delete temp; 
			}
			system("cls");
			break;
		}
		case 2:
		{
			cout << "You've chosen a hero Knight" << endl;
			Knight_Class* temp = new Knight_Class("Knight", "asdasd", 110, 20, 10);
			temp->Display_Status();
			cout << endl;
			Text_To_Confirm_The_Selection();

			cin >> Subverification;
			if (Subverification == 1)
			{
				return temp;
			}
			else
			{
				delete temp;
			}
			system("cls");
			break;
		}
		case 3:
		{
			cout << "You've chosen a hero Bandit" << endl;
			Bandit_Class* temp = new Bandit_Class("Bandit", "aspfoasf", 90, 10, 5);
			temp->Display_Status();
			cout << endl;
			Text_To_Confirm_The_Selection();

			cin >> Subverification;
			if (Subverification == 1)
			{
				return temp;
			}
			else
			{
				delete temp;
			}
			system("cls");
			break;
		}
		case 4:
		{
			cout << "You've chosen a hero Drow" << endl;
			Drow_Class* temp = new Drow_Class("Drow", "Shadowy figure", 120, 10, 5);
			temp->Display_Status();
			cout << endl;
			Text_To_Confirm_The_Selection();

			cin >> Subverification;
			if (Subverification == 1)
			{
				return temp;
			}
			else
			{
				delete temp;
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

//void Initialization_Check(Game_Class Player, Enemy_Class Enemy)
//{
//	if (Player == nullptr || Enemy == nullptr)
//	{
//		std::cerr << "Player or Enemy is not initialized!" << std::endl;
//		return;
//	}
//}

void The_Enemy_Move(Game_Class& Player, Enemy_Class& Enemy)
{

	if (!Skip_Hod)
	{
		cout << "" << endl;
		SetTextColor(12);
		cout << "Enemy's move" << endl;
		cout << "" << endl;

		Player.HP -= Enemy.Damage;
		SetTextColor(12);
		Enemy.Display_Status();
		SetTextColor(10);
		Player.Display_Status();
	}
	else
	{
		SetTextColor(3);
		cout << "Enemy is stunned and cannot take damage this turn" << endl;
	}

	if (!Player.Is_Alive())
	{
		SetTextColor(6);
		cout << Enemy.Name << " You are defeated" << endl;
	}
}

void The_Player_Move(Game_Class& Player, Enemy_Class& Enemy)
{
	cout << "" << endl;
	SetTextColor(10);
	cout << "Player's move" << endl;
	cout << "" << endl;

	Player.Abilites();

	Enemy.HP -= Player.Damage;
	SetTextColor(10);
	Player.Display_Status();

	if (Enemy.Is_Alive())
	{
		SetTextColor(12);
		Enemy.Display_Status();
	}
	else
	{
		SetTextColor(6);
		cout << Enemy.Name << " defeated! You've won!" << endl;
	}
}

void Battle(Game_Class& Player)
{
	Enemy_Class   Goblin("Goblin", "asdasdasd", 100, 10, 5, 1);
	Enemy_Class   Skeleton("Skeleton", "asdasdasd", 100, 10, 5, 1);
	Enemy_Class   Dark("Dark", "asdasdasd", 100, 10, 5, 1);
	Enemy_Class   Shadow("Shadow", "asdasdasd", 100, 10, 5, 1);
	Enemy_Class   King("King", "asdasdasd", 100, 10, 5, 1);

	Enemy_Class& Enemy = Goblin;
	
	cout << "A fight breaks out between "<< Player.Name << " end "<< Enemy.Name << endl;
	cout << "To make a move in a battle press “Enter”" << endl;

	cin.get();
	
	//Initialization_Check(Player, Enemy);

	while (Player.Is_Alive() && Enemy.Is_Alive() && Exit_the_battle == false)
	{

        The_Player_Move(Player, Enemy);
		cin.get();

		if (Player.Name == "Bastard" && dynamic_cast<Bastard_Class*>(&Player)->Exit_the_battle)
		{
			break;
		}

		if (Player.Name == "Knight")
		{
			Skip_Hod = dynamic_cast<Knight_Class*>(&Player)->Skip_Hod;
		}

		if (Enemy.Is_Alive())
		{
			The_Enemy_Move(Player, Enemy);
			cin.get();
		}
		system("cls");
	}
	SetTextColor(7);
}