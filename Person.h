#pragma once
#include <string>
#include <iostream>

class Person_Class
{
public:
	virtual ~Person_Class() = default;

	std::string Name;
	std::string Description;
	int HP;
	int Damage;
	int Die_Bonus;

	bool Is_Alive();
	void Display_Status();

	Person_Class();
	Person_Class(std::string Name, std::string Description, int HP, int Damage, int Die_Bonus);
};
class Game_Class : public Person_Class
{
public:

	virtual void Abilites() = 0;

	Game_Class(std::string Name, std::string Description, int HP, int Damage, int Die_Bonus);

};

class Bastard_Class : public Game_Class
{
public:

	Bastard_Class(std::string Name, std::string Description, int HP, int Damage, int Die_Bonus);

	bool Exit_the_battle = false;

	void Abilites() override;
};
class Knight_Class : public Game_Class
{
private:
	int x;

public:

	Knight_Class(std::string Name, std::string Description, int HP, int Damage, int Die_Bonus);

	bool Skip_Hod = false;

	void Abilites() override;
};
class Bandit_Class : public Game_Class
{
public:

	Bandit_Class(std::string Name, std::string Description, int HP, int Damage, int Die_Bonus);

	void Abilites() override;

};
class Drow_Class : public Game_Class
{
public:

	Drow_Class(std::string Name, std::string Description, int HP, int Damage, int Die_Bonus);

	Person_Class* target;

	void Abilites() override;
};


class Enemy_Class : public Person_Class
{
public:
	int Reward;

	Enemy_Class(std::string Name, std::string Description, int HP, int Damage, int Die_Bonus, int Reward);


};
