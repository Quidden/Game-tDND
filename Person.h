#pragma once
#include <string>
#include <iostream>

class PersonC
{
public:
	virtual ~PersonC() = default;

	std::string name;
	std::string description;
	int hp;
	int damage;
	int die_bonus;

	bool IsAlive();
	void DisplayStatus();

	PersonC(std::string name, std::string description, int hp, int damage, int die_bonus);
};
class GameC : public PersonC
{
public:

	bool exit_the_battle = false;
	bool skip_hod = false;

	virtual void Abilites() = 0;

	GameC(std::string name, std::string description, int hp, int damage, int die_bonus);

};

class BastardC : public GameC
{
public:


	BastardC(std::string name, std::string description, int hp, int damage, int die_bonus);

	bool exit_the_battle = false;

	void Abilites() override;
};
class KnightC : public GameC
{
private:
	int x;

public:

	KnightC(std::string name, std::string description, int hp, int damage, int die_bonus);

	bool skip_hod = false;

	void Abilites() override;
};
class BanditC : public GameC
{
public:

	BanditC(std::string name, std::string description, int hp, int damage, int die_bonus);

	void Abilites() override;

};
class DrowC : public GameC
{
public:

	DrowC(std::string name, std::string description, int hp, int damage, int die_bonus);

	PersonC* target;

	void Abilites() override;
};


class EnemyC : public PersonC
{
public:
	int reward;

	EnemyC(std::string name, std::string description, int hp, int damage, int die_bonus, int reward);

};
