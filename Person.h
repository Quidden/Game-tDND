#pragma once
#include <string>
#include <iostream>

class PersonClass
{
public:
	virtual ~PersonClass() = default;

	std::string Name;
	std::string Description;
	int HP;
	int Damage;
	int DieBonus;

	bool IsAlive();
	void DisplayStatus();

	PersonClass();
	PersonClass(std::string Name, std::string Description, int HP, int Damage, int DieBonus);
};
class GameClass : public PersonClass
{
public:

	bool ExitTheBattle = false;
	bool SkipHod = false;

	virtual void Abilites() = 0;

	GameClass(std::string Name, std::string Description, int HP, int Damage, int DieBonus);

};

class BastardClass : public GameClass
{
public:


	BastardClass(std::string Name, std::string Description, int HP, int Damage, int DieBonus);

	bool ExitTheBattle = false;

	void Abilites() override;
};
class KnightClass : public GameClass
{
private:
	int x;

public:

	KnightClass(std::string Name, std::string Description, int HP, int Damage, int DieBonus);

	bool SkipHod = false;

	void Abilites() override;
};
class BanditClass : public GameClass
{
public:

	BanditClass(std::string Name, std::string Description, int HP, int Damage, int DieBonus);

	void Abilites() override;

};
class DrowClass : public GameClass
{
public:

	DrowClass(std::string Name, std::string Description, int HP, int Damage, int DieBonus);

	PersonClass* target;

	void Abilites() override;
};


class EnemyClass : public PersonClass
{
public:
	int Reward;

	EnemyClass(std::string Name, std::string Description, int HP, int Damage, int DieBonus, int Reward);


};
