#pragma once
#include <string>

class ItemC
{
public:
	std::string name;
	std::string description;
	int rarity;
	int price;
	ItemC(std::string name, std::string description, int rarity, int price);
};

class Health_PotkaC : public ItemC
{
public:
	int health;
	Health_PotkaC(std::string name, std::string description, int rarity, int price, int health);
};

class Luckest_PotkaC : public ItemC
{
public:
	int die_bonus;
	Luckest_PotkaC(std::string name, std::string description, int rarity, int price, int die_bonus);
};

class Weapon : public ItemC
{
public:
	int damage;
	int slot;
	Weapon(std::string name, std::string description, int rarity, int price, int damage, int slot);
};

class LongSword : public Weapon
{
public:
	void CSWA2C() //Can stun with a 20% chance
	{

	}
};

class LSMagical : public Weapon
{
public:
	void WA2CTHWMD() //With a 20% chance to hit with magic damage.
	{

	}
};

class LSLegendary : public Weapon
{
public:
	void WA8COWAND() //With an 80% chance of winning any duel.
	{

	}
};

class dagger : public Weapon
{
public:
	void WA1COKI() //With a 10% chance of killing instantly
	{

	}
};

class DMagical : public Weapon
{
public:
	void WA5COKI() //With a 50% chance of killing instantly
	{

	}
};

class DLegendaryl : public Weapon
{
public:
	void ILB1() //Increases luck by +10
	{

	}
};

class Bow : public Weapon
{
public:
	void CTA1DC() //Can take a 10 damage crit
	{

	}
};

class BLegendary : public Weapon
{
public:
	void AYTMTFAAHA9CTK() //Allows you to make the first attack and have a 90% chance to kill 
	{

	}
};