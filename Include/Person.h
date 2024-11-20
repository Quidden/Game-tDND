#pragma once
#include <string>
#include <iostream>
#include <memory>
#include "Item.h"
#include "Inventory.h"
#include <vector>

enum class CharacterType : uint8_t { Knight, Drow, Bandit, Bastard };
struct EquipResult
{
    bool success;
    Equipted_Items_Base* Item;
};

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
    int max_num_of_weapons;

    InventoryC inventory;
    CharacterType charter_type;

    bool exit_the_battle = false;
    bool skip_hod = false;

    PlayerC(std::string name, std::string description, int hp, int damage, int die_bonus, int wallet, int max_num_of_weapons, CharacterType charter_type);
    void TryAbility(int chanceThreshold, bool &effectFlag, const std::string &abilityMessage);

    std::vector<Equipted_Items_Base *> equipped_items;

    EquipResult EquipError(int index);
    void EquipAction(Equipted_Items_Base* Equipted_Items, int index);
    bool UseItem(int index);
    int AdjustDamage(bool add);
    bool SellItem(int index);
    virtual void Abilites() = 0;
    virtual bool CanEquip(Equipted_Item_Type item_equip_seccess) const = 0;
};

class BastardC : public PlayerC
{
public:
    using PlayerC::PlayerC;

    std::vector<Equipted_Items_Base*> equpted_item;

    bool exit_the_battle = false;

    void Abilites() override;

    bool CanEquip(Equipted_Item_Type item_equip_seccess) const override
    {
        return true;
    }
};

class KnightC : public PlayerC
{
public:
    using PlayerC::PlayerC;

    bool skip_hod = false;

    void Abilites() override;

    bool CanEquip(Equipted_Item_Type item_equip_seccess) const override
    {
        return item_equip_seccess == Equipted_Item_Type::Sword || item_equip_seccess == Equipted_Item_Type::Armor;
    }
};

class BanditC : public PlayerC
{
public:
    using PlayerC::PlayerC;

    void Abilites() override;

    bool CanEquip(Equipted_Item_Type item_equip_seccess) const override
    {
        return item_equip_seccess == Equipted_Item_Type::Dagger;
    }
};

class ArcherC : public PlayerC
{
public:
    using PlayerC::PlayerC;

    PersonC *target;

    void Abilites() override;

    bool CanEquip(Equipted_Item_Type item_equip_seccess) const override
    {
        return item_equip_seccess == Equipted_Item_Type::Bow || item_equip_seccess == Equipted_Item_Type::Armor;
    }
};

class EnemyC : public PersonC
{
public:
    int reward;

    EnemyC(std::string name, std::string description, int hp, int damage, int die_bonus, int reward);
};
