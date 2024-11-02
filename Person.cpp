#include "Person.h"
#include <Windows.h>

void SetTextColor2(int color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

PersonC::PersonC(std::string name, std::string description, int hp, int damage, int die_bonus)
	: name(name), description(description), hp(hp), damage(damage), die_bonus(die_bonus) {}
GameC::GameC(std::string name, std::string description, int hp, int damage, int die_bonus, CharacterType charter_type)
	:PersonC(name, description, hp, damage, die_bonus) ,charter_type(charter_type) {}
BastardC::BastardC(std::string name, std::string description, int hp, int damage, int die_bonus, CharacterType charter_type)
	: GameC(name, description, hp, damage, die_bonus, charter_type) {}
KnightC::KnightC(std::string name, std::string description, int hp, int damage, int die_bonus, CharacterType charter_type)
	: GameC(name, description, hp, damage, die_bonus, charter_type) {}
BanditC::BanditC(std::string name, std::string description, int hp, int damage, int die_bonus, CharacterType charter_type)
	: GameC(name, description, hp, damage, die_bonus, charter_type) {}
DrowC::DrowC(std::string name, std::string description, int hp, int damage, int die_bonus, CharacterType charter_type)
	: GameC(name, description, hp, damage, die_bonus, charter_type) {}
EnemyC::EnemyC(std::string name, std::string description, int hp, int damage, int die_bonus, int reward)
	:PersonC(name, description, hp, damage, die_bonus), reward(reward) {}


bool PersonC::IsAlive()
{
	return hp > 0;
}
void PersonC::DisplayStatus()
{
	std::cout << name << ": " << hp << " HP, Damage " << damage << ", Die Bonus " << die_bonus << std::endl;
}

void BastardC::Abilites()
{
	int chance = rand() % 100 + 1;
	if (chance <= 10)
	{
		SetTextColor2(3);
		std::cout << name << "Bastard exit the battle" << std::endl;
		exit_the_battle = true;
	}
	else
	{
		exit_the_battle = false;
	}
}
void KnightC::Abilites()
{

	int chance = rand() % 100 + 1;
	if (chance <= 30)
	{
		skip_hod = true;
	}
	else
	{
		skip_hod = false;
	}
}
void BanditC::Abilites()
{
	int chance = rand() % 100 + 1;
	if (chance <= 60)
	{
		SetTextColor2(3);
		std::cout << name << "Double damag" << std::endl;
		this->damage *= 2;
	}
}
void DrowC::Abilites()
{
	int chance = rand() % 100 + 1;
	if (chance <= 10)
	{
		SetTextColor2(3);
		std::cout << name << "Took two damage" << std::endl;
		this->damage += 2;

		if (target != nullptr)
		{
			target->hp -= 2;
		}
	}
}
