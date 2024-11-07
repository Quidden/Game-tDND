#pragma once
#include <string>
#include <iostream>
#include "Item.h"
#include "Inventory.h"
#include <vector>

enum class CharacterType {Knight, Drow, Bandit, Bastard};

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

class PlayerC : public PersonC
{
public:

	InventoryC inventory;
	CharacterType charter_type;

	bool exit_the_battle = false;
	bool skip_hod = false;

	virtual void Abilites() = 0;

	PlayerC(std::string name, std::string description, int hp, int damage, int die_bonus, CharacterType charter_type);

	virtual bool CanEquip(WeaponType weapon_type) const = 0;

	std::vector<ItemC*> items;
    ItemC* equipped_weapon = nullptr;

    void EquipWeapon(int index)
    {
    	if (!(index < 0 || index >= items.size()))
    	{
    		std::cout << "Invalid index." << std::endl;
    	}
            if (Weapon* weapon = dynamic_cast<Weapon*>(items[index]))
            {
                if (this->CanEquip(weapon->weapon_type))
                {
                    equipped_weapon = weapon;
                    std::cout << this->name << " equipped " << weapon->name << std::endl;
                }
                else
                {
                    std::cout << this->name << " cannot equip this weapon type." << std::endl;
                }
            }
            else
            {
                std::cout << "Selected item is not a weapon." << std::endl;
            }
    }

    void UseItem(int index)
    {
        if (!(index >= 0 && index < items.size()))
        {
        	std::cout << "Invalid index." << std::endl;
        }
            if (Health_PotkaC* potion = dynamic_cast<Health_PotkaC*>(items[index]))
            {
                std::cout << "Using " << potion->name << " to restore " << potion->health << " health points." << std::endl;
                this->hp += potion->health;
                delete items[index];
                items.erase(items.begin() + index);
            }
            else
            {
                std::cout << "Selected item is not a potion." << std::endl;
            }
    }

    int GetDamage()
    {
        this->damage += (equipped_weapon ? dynamic_cast<Weapon*>(equipped_weapon)->damage : 0);
    	return this->damage;
    }

	int UnGetDamage()
	{
	    this->damage -= (equipped_weapon ? dynamic_cast<Weapon*>(equipped_weapon)->damage : 0);
    	return this->damage;
    }

    void SellItem(int index, int& player_gold)
    {
        if (index >= 0 && index < items.size())
        {
            player_gold += items[index]->price;
            std::cout << "Sold item: " << items[index]->name << " for " << items[index]->price << " gold." << std::endl;
            delete items[index];
            items.erase(items.begin() + index);
        }
        else
        {
            std::cout << "Invalid index." << std::endl;
        }
    }

    /*~Inventory()
    {
        for (ItemC* item : items) {
            delete item;
        }
    }*/
};

class BastardC : public PlayerC
{
public:

	BastardC(std::string name, std::string description, int hp, int damage, int die_bonus, CharacterType charter_type);

	bool exit_the_battle = false;

	void Abilites() override;

	bool CanEquip(WeaponType weapon_type) const override
	{
		return true;
	}
};
class KnightC : public PlayerC
{
public:

	KnightC(std::string name, std::string description, int hp, int damage, int die_bonus, CharacterType charter_type);

	bool skip_hod = false;

	void Abilites() override;

	bool CanEquip(WeaponType weapon_type) const override
	{
		return weapon_type == WeaponType::Sword;
	}
};
class BanditC : public PlayerC
{
public:

	BanditC(std::string name, std::string description, int hp, int damage, int die_bonus, CharacterType charter_type);

	void Abilites() override;

	bool CanEquip(WeaponType weapon_type) const override
	{
		return weapon_type == WeaponType::Dagger;
	}
};
class DrowC : public PlayerC
{
public:

	DrowC(std::string name, std::string description, int hp, int damage, int die_bonus, CharacterType charter_type);

	PersonC* target;

	void Abilites() override;
	bool CanEquip(WeaponType weapon_type) const override
	{
		return weapon_type == WeaponType::Bow;
	}
};

class EnemyC : public PersonC
{
public:
	int reward;

	EnemyC(std::string name, std::string description, int hp, int damage, int die_bonus, int reward);

};
