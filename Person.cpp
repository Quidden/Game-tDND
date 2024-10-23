#include "Person.h"
#include <Windows.h>

void SetTextColor2(int color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

Person_Class::Person_Class() : Name(""), Description(""), HP(0), Damage(0), Die_Bonus(0) {}
Person_Class::Person_Class(std::string Name, std::string Description, int HP, int Damage, int Die_Bonus)
	: Name(Name), Description(Description), HP(HP), Damage(Damage), Die_Bonus(Die_Bonus) {}
Game_Class::Game_Class(std::string Name, std::string Description, int HP, int Damage, int Die_Bonus)
	:Person_Class(Name, Description, HP, Damage, Die_Bonus) {}
Bastard_Class::Bastard_Class(std::string Name, std::string Description, int HP, int Damage, int Die_Bonus)
	: Game_Class(Name, Description, HP, Damage, Die_Bonus) {}
Knight_Class::Knight_Class(std::string Name, std::string Description, int HP, int Damage, int Die_Bonus)
	: Game_Class(Name, Description, HP, Damage, Die_Bonus) {}
Bandit_Class::Bandit_Class(std::string Name, std::string Description, int HP, int Damage, int Die_Bonus)
	: Game_Class(Name, Description, HP, Damage, Die_Bonus) {}
Drow_Class::Drow_Class(std::string Name, std::string Description, int HP, int Damage, int Die_Bonus)
	: Game_Class(Name, Description, HP, Damage, Die_Bonus) {}
Enemy_Class::Enemy_Class(std::string Name, std::string Description, int HP, int Damage, int Die_Bonus, int Reward)
	:Person_Class(Name, Description, HP, Damage, Die_Bonus) {}

Knight_Class  Knight_Obj(    "Knight",      "asdasd",           110, 20, 10);
Bandit_Class  Bandit_Obj(    "Bandit",      "aspfoasf",         90, 10, 5);
Drow_Class    Drow_Obj(      "Drow",        "Shadowy figure",   120, 10, 5);
Enemy_Class   Goblin_Obj(    "Goblin",      "asdasdasd",        100, 10, 5, 1);
Enemy_Class   Skeleton_Obj(  "Skeleton",    "asdasdasd",        100, 10, 5, 1);
Enemy_Class   Dark_Obj(      "Dark",        "asdasdasd",        100, 10, 5, 1);
Enemy_Class   Shadow_Obj(    "Shadow",      "asdasdasd",        100, 10, 5, 1);
Enemy_Class   King_Obj(      "King",        "asdasdasd",        100, 10, 5, 1);

bool Person_Class::Is_Alive()
{
	return HP > 0;
}
void Person_Class::Display_Status()
{
	std::cout << Name << ": " << HP << " HP, Damage " << Damage << ", Die Bonus " << Die_Bonus << std::endl;
}

void Bastard_Class::Abilites()
{
	int chance = rand() % 100 + 1;
	if (chance <= 10)
	{
		SetTextColor2(3);
		std::cout << Name << "Bastard exit the battle" << std::endl;
		Exit_the_battle = true;
	}
	else
	{
		Exit_the_battle = false;
	}
}
void Knight_Class::Abilites()
{

	int chance = rand() % 100 + 1;
	if (chance <= 30)
	{
		Skip_Hod = true;
	}
	else
	{
		Skip_Hod = false;
	}
}
void Bandit_Class::Abilites()
{
	int chance = rand() % 100 + 1;
	if (chance <= 60)
	{
		SetTextColor2(3);
		std::cout << Name << "Double damag" << std::endl;
		this->Damage *= 2;
	}
}
void Drow_Class::Abilites()
{
	int chance = rand() % 100 + 1;
	if (chance <= 10)
	{
		SetTextColor2(3);
		std::cout << Name << "Took two damage" << std::endl;
		this->Damage += 2;

		if (target != nullptr)
		{
			target->HP -= 2;
		}
	}
}

Bastard_Class& Get_Bastard_Obj()
{
	return(Bastard_Obj);
}
Knight_Class& Get_Knight_Obj()
{
	return(Knight_Obj);
}
Bandit_Class& Get_Bandit_Obj()
{
	return(Bandit_Obj);
}
Drow_Class& Get_Drow_Obj()
{
	return(Drow_Obj);
}
Enemy_Class& Get_Goblin_Obj()
{
	return(Goblin_Obj);
}
Enemy_Class& Get_Skeleton_Obj()
{
	return(Skeleton_Obj);
}
Enemy_Class& Get_Dark_Obj()
{
	return(Dark_Obj);
}
Enemy_Class& Get_Shadow_Obj()
{
	return(Shadow_Obj);
}
Enemy_Class& Get_King_Obj()
{
	return(King_Obj);
}