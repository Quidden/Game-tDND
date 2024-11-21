#pragma once
#include <string>
#include <memory>
#include <iostream>

enum Equipted_Item_Type {Sword, Bow, Dagger, Armor};

class ItemC
{
public:
	std::string name;
	std::string description;
	int rarity;
	int price;
	ItemC(std::string name, std::string description, int rarity, int price);
	virtual ~ItemC() = default;
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

class Equipted_Items_Base : public ItemC
{
public:
	Equipted_Item_Type Item_Type;
	Equipted_Items_Base(const std::string& name, const std::string& description, int rarity, int price, Equipted_Item_Type Item_Type)
	   : ItemC(name, description, rarity, price) {}
};

class Equipten_Items_Class : public Equipted_Items_Base
{
public:
	int damage;

	Equipten_Items_Class(const std::string& name, const std::string& description, int rarity, int price, int damage, Equipted_Item_Type weapon_type);
};

class SpecificWeapon : public Equipted_Items_Base
{
	virtual void WeaponAbilites();
};

class LongSword : public SpecificWeapon
{
public:
	void CSWA2C() //Can stun with a 20% chance
	{

	}
};

class LSMagical : public SpecificWeapon
{
public:
	void WA2CTHWMD() //With a 20% chance to hit with magic damage.
	{

	}
};

class LSLegendary : public SpecificWeapon
{
public:
	void WA8COWAND() //With an 80% chance of winning any duel.
	{

	}
};

class dagger : public SpecificWeapon
{
public:
	void WA1COKI() //With a 10% chance of killing instantly
	{

	}
};

class DMagical : public SpecificWeapon
{
public:
	void WA5COKI() //With a 50% chance of killing instantly
	{

	}
};

class DLegendaryl : public SpecificWeapon
{
public:
	void ILB1() //Increases luck by +10
	{

	}
};

class Bow : public SpecificWeapon
{
public:
	void CTA1DC() //Can take a 10 damage crit
	{

	}
};

class BLegendary : public SpecificWeapon
{
public:
	void AYTMTFAAHA9CTK() //Allows you to make the first attack and have a 90% chance to kill 
	{

	}
};

class Armor : public Equipted_Items_Base
{
public:
	int armor;
	int die_bonus_armor;
	Armor(const std::string& name, const std::string& description, int rarity, int price, int armor, int die_bonus_armor, Equipted_Item_Type weapon_type);
};