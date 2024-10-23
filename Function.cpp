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

Bastard_Class& Bastard_switch = Get_Bastard_Obj();
Knight_Class& Knight_switch = Get_Knight_Obj();
Bandit_Class& Bandit_switch = Get_Bandit_Obj();
Drow_Class& Drow_switch = Get_Drow_Obj();
Enemy_Class& Skeleton = Get_Skeleton_Obj();
Enemy_Class& Dark = Get_Dark_Obj();
Enemy_Class& Shadow = Get_Shadow_Obj();
Enemy_Class& King = Get_King_Obj();

Game_Class* Player = nullptr;

void Text_To_Confirm_The_Selection()
{
	cout << "If you really want to play as this character press 1" << endl;
	cout << "If you want to change your character press 2" << endl;
}

Game_Class* Selecting_A_Game_Character(Bastard_Class x)
{
	x.Damage = 10;
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
			Bastard_switch.Display_Status();
			cout << endl;
			Text_To_Confirm_The_Selection();

			cin >> Subverification;
			if (Subverification == 1)
			{
				Player = &Bastard_switch;
			}
			system("cls");
			break;
		}
		case 2:
		{
			cout << "You've chosen a hero Knight" << endl;
			Knight_switch.Display_Status();
			cout << endl;
			Text_To_Confirm_The_Selection();

			cin >> Subverification;
			if (Subverification == 1)
			{
				Player = &Knight_switch;
			}
			system("cls");
			break;
		}
		case 3:
		{
			cout << "You've chosen a hero Bandit" << endl;
			Bandit_switch.Display_Status();
			cout << endl;
			Text_To_Confirm_The_Selection();

			cin >> Subverification;
			if (Subverification == 1)
			{
				Player = &Bandit_switch;
			}
			system("cls");
			break;
		}
		case 4:
		{
			cout << "You've chosen a hero Drow" << endl;
			Drow_switch.Display_Status();
			cout << endl;
			Text_To_Confirm_The_Selection();

			cin >> Subverification;
			if (Subverification == 1)
			{
				Player = &Drow_switch;
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
	return Player;
}

bool Skip_Hod = false;
bool Exit_the_battle = false;

void Initialization_Check(Game_Class Player, Enemy_Class Enemy)
{
	if (Player == nullptr || Enemy == nullptr)
	{
		std::cerr << "Player or Enemy is not initialized!" << std::endl;
		return;
	}
}

void The_Enemy_Move()
{
	if (!Skip_Hod)
	{
		cout << "" << endl;
		SetTextColor(12);
		cout << "Enemy's move" << endl;
		cout << "" << endl;

		Player->HP -= Enemy->Damage;
		SetTextColor(12);
		Enemy->Display_Status();
		SetTextColor(10);
		Player->Display_Status();
	}
	else
	{
		SetTextColor(3);
		cout << "Enemy is stunned and cannot take damage this turn" << endl;
	}

	if (!Player->Is_Alive())
	{
		SetTextColor(6);
		cout << Enemy->Name << " You are defeated" << endl;
	}
}

void The_Player_Move()
{
	cout << "" << endl;
	SetTextColor(10);
	cout << "Player's move" << endl;
	cout << "" << endl;

	Player->Abilites();

	Enemy->HP -= Player->Damage;
	SetTextColor(10);
	Player->Display_Status();

	if (Enemy->Is_Alive())
	{
		SetTextColor(12);
		Enemy->Display_Status();
	}
	else
	{
		SetTextColor(6);
		cout << Enemy->Name << " defeated! You've won!" << endl;
	}
}

void Battle(Game_Class Player)
{
	Enemy_Class& Enemy = Enemy_Class   Goblin_Obj("Goblin", "asdasdasd", 100, 10, 5, 1);

	
	cout << "A fight breaks out between "<< Player->Name << " end "<< Enemy->Name << endl;
	cout << "To make a move in a battle press “Enter”" << endl;

	cin.get();

	Initialization_Check(Player, Enemy);

	while (Player->Is_Alive() && Enemy->Is_Alive() && Exit_the_battle == false)
	{

        The_Player_Move();
		cin.get();

		if (Player->Name == "Bastard" && dynamic_cast<Bastard_Class*>(Player)->Exit_the_battle)
		{
			break;
		}

		if (Player->Name == "Knight")
		{
			Skip_Hod = dynamic_cast<Knight_Class*>(Player)->Skip_Hod;
		}

		if (Enemy->Is_Alive())
		{
			The_Enemy_Move();
			cin.get();
		}
		system("cls");
	}
	SetTextColor(7);
}