#pragma once
#include <string>
#include <memory>
#include <iostream>

enum class WeaponType : uint8_t {Sword, Bow, Dagger};

class ItemC
{
public:
	std::string name;
	std::string description;
	int rarity;
	int price;
	ItemC(std::string name, std::string description, int rarity, int price);
	virtual void Use() const = 0;
};

class Health_PotkaC : public ItemC
{
public:
	int health;
	Health_PotkaC(std::string name, std::string description, int rarity, int price, int health);
	void Use() const override 
	{
		std::cout << "Using " << name << " to restore " << health << " health points." << std::endl;
	}
};

class Luckest_PotkaC : public ItemC
{
public:
	int die_bonus;
	Luckest_PotkaC(std::string name, std::string description, int rarity, int price, int die_bonus);
	void Use() const override 
	{
		std::cout << "Using " << name << " to restore " << die_bonus << " Luckest points." << std::endl;
	}
};

class Weapon : public ItemC
{
public:
	int damage;
	int slot;

	WeaponType weapon_type;

	Weapon(std::string name, std::string description, int rarity, int price, int damage, int slot, WeaponType weapon_type);
	void Use() const override 
	{
		std::cout << "Using weapon: " << name << " with damage: " << damage << std::endl;
	}
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