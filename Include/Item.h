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

	template <typename T>
   bool IsType() const
	{
		return typeid(*this) == typeid(T);
	}

	template <typename T>
	T* AsType()
	{
		if (IsType<T>())
			return static_cast<T*>(this);
		return nullptr;
	}
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
	   : ItemC(name, description, rarity, price), Item_Type(Item_Type) {}
};

class Equipten_Weapon_Class : public Equipted_Items_Base
{
public:
	int damage;

	Equipten_Weapon_Class(const std::string& name, const std::string& description, int rarity, int price, int damage, Equipted_Item_Type Item_Type);
};

class SpecificWeapon : public Equipted_Items_Base
{
	virtual void WeaponAbilites();
};

class LongSword : public SpecificWeapon
{
public:

};

class LSMagical : public SpecificWeapon
{
public:

};

class LSLegendary : public SpecificWeapon
{
public:

};

class dagger : public SpecificWeapon
{
public:

};

class DMagical : public SpecificWeapon
{
public:

};

class DLegendaryl : public SpecificWeapon
{
public:

};

class Bow : public SpecificWeapon
{
public:

};

class BLegendary : public SpecificWeapon
{
public:

};

class Armor : public Equipted_Items_Base
{
public:
	int armor;
	int die_bonus_armor;
	Armor(const std::string& name, const std::string& description, int rarity, int price, int armor, int die_bonus_armor, Equipted_Item_Type Item_Type);
};