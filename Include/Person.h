#pragma once
#include <string>
#include <iostream>
#include "Item.h"

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

	CharacterType charter_type;

	bool exit_the_battle = false;
	bool skip_hod = false;

	virtual void Abilites() = 0;

	PlayerC(std::string name, std::string description, int hp, int damage, int die_bonus, CharacterType charter_type);

	virtual bool CanEquip(WeaponType weapon_type) const = 0;
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
