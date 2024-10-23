#pragma once
#include <string>
class Item
{
public:
	std::string Name;
	std::string Description;
	int Rarity;
	int price;
	Item();
};

class HealthPotka : public Item
{
public:
	int health;
};

class LuckestPotka : public Item
{
public:
	int bonusKub;
};

class Weapon : public Item
{
public:
	int damage;
	int slot;
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