#include "Person.h"
#include <Windows.h>

void SetTextColor2(int color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

PersonClass::PersonClass() : Name(""), Description(""), HP(0), Damage(0), DieBonus(0) {}
PersonClass::PersonClass(std::string Name, std::string Description, int HP, int Damage, int DieBonus)
	: Name(Name), Description(Description), HP(HP), Damage(Damage), DieBonus(DieBonus) {}
GameClass::GameClass(std::string Name, std::string Description, int HP, int Damage, int DieBonus)
	:PersonClass(Name, Description, HP, Damage, DieBonus) {}
BastardClass::BastardClass(std::string Name, std::string Description, int HP, int Damage, int DieBonus)
	: GameClass(Name, Description, HP, Damage, DieBonus) {}
KnightClass::KnightClass(std::string Name, std::string Description, int HP, int Damage, int DieBonus)
	: GameClass(Name, Description, HP, Damage, DieBonus) {}
BanditClass::BanditClass(std::string Name, std::string Description, int HP, int Damage, int DieBonus)
	: GameClass(Name, Description, HP, Damage, DieBonus) {}
DrowClass::DrowClass(std::string Name, std::string Description, int HP, int Damage, int DieBonus)
	: GameClass(Name, Description, HP, Damage, DieBonus) {}
EnemyClass::EnemyClass(std::string Name, std::string Description, int HP, int Damage, int DieBonus, int Reward)
	:PersonClass(Name, Description, HP, Damage, DieBonus) {}


bool PersonClass::IsAlive()
{
	return HP > 0;
}
void PersonClass::DisplayStatus()
{
	std::cout << Name << ": " << HP << " HP, Damage " << Damage << ", Die Bonus " << DieBonus << std::endl;
}

void BastardClass::Abilites()
{
	int chance = rand() % 100 + 1;
	if (chance <= 10)
	{
		SetTextColor2(3);
		std::cout << Name << "Bastard exit the battle" << std::endl;
		ExitTheBattle = true;
	}
	else
	{
		ExitTheBattle = false;
	}
}
void KnightClass::Abilites()
{

	int chance = rand() % 100 + 1;
	if (chance <= 30)
	{
		SkipHod = true;
	}
	else
	{
		SkipHod = false;
	}
}
void BanditClass::Abilites()
{
	int chance = rand() % 100 + 1;
	if (chance <= 60)
	{
		SetTextColor2(3);
		std::cout << Name << "Double damag" << std::endl;
		this->Damage *= 2;
	}
}
void DrowClass::Abilites()
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
