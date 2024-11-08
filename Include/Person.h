#pragma once
#include <string>
#include <iostream>
#include <memory>
#include "Item.h"
#include "Inventory.h"
#include <vector>

enum class CharacterType : uint8_t { Knight, Drow, Bandit, Bastard };

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

    int wallet;

    InventoryC inventory;
    CharacterType charter_type;

    bool exit_the_battle = false;
    bool skip_hod = false;

    PlayerC(std::string name, std::string description, int hp, int damage, int die_bonus, int wallet, CharacterType charter_type);
    void TryAbility(int chanceThreshold, bool &effectFlag, const std::string &abilityMessage);

    std::vector<ItemC *> items;
    ItemC *equipped_weapon = nullptr;

    void EquipWeapon(int index);
    void UseItem(int index);
    int AdjustDamage(bool add);
    void SellItem(int index);
    virtual void Abilites() = 0;
    virtual bool CanEquip(WeaponType weapon_type) const = 0;
};

class BastardC : public PlayerC
{
public:
    BastardC(std::string name, std::string description, int hp, int damage, int die_bonus, int wallet, CharacterType charter_type);

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
    KnightC(std::string name, std::string description, int hp, int damage, int die_bonus, int wallet, CharacterType charter_type);

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
    BanditC(std::string name, std::string description, int hp, int damage, int die_bonus, int wallet, CharacterType charter_type);

    void Abilites() override;

    bool CanEquip(WeaponType weapon_type) const override
    {
        return weapon_type == WeaponType::Dagger;
    }
};

class ArcherC : public PlayerC
{
public:
    ArcherC(std::string name, std::string description, int hp, int damage, int die_bonus, int wallet, CharacterType charter_type);

    PersonC *target;

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
