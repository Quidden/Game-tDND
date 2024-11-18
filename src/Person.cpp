#include "Person.h"
#include <Windows.h>
#include "Function.h"

void SetTextColor2(int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

PersonC::PersonC(std::string name, std::string description, int hp, int damage, int die_bonus)
    : name(std::move(name)), description(std::move(description)), hp(hp), damage(damage), die_bonus(die_bonus)
{
}

PlayerC::PlayerC(std::string name, std::string description, int hp, int damage, int die_bonus, int wallet, int max_num_of_weapons, CharacterType charter_type)
    : PersonC(std::move(name), std::move(description), hp, damage, die_bonus),max_num_of_weapons(max_num_of_weapons), wallet(wallet), charter_type(charter_type)
{
}

EnemyC::EnemyC(std::string name, std::string description, int hp, int damage, int die_bonus, int reward)
    : PersonC(std::move(name), std::move(description), hp, damage, die_bonus), reward(reward)
{
}


bool PersonC::IsAlive()
{
    return hp > 0;
}

void PersonC::DisplayStatus()
{
    std::cout << name << ": " << hp << " HP, Damage " << damage << ", Die Bonus " << die_bonus << std::endl;
}

void PlayerC::TryAbility(int chanceThreshold, bool &effectFlag, const std::string &abilityMessage)
{
    int chance = rand() % 100 + 1;
    if (chance <= chanceThreshold)
    {
        effectFlag = true;
        SetTextColor2(3);
        std::cout << name << " " << abilityMessage << std::endl;
    } else
    {
        effectFlag = false;
    }
}

void BastardC::Abilites()
{
    TryAbility(10, exit_the_battle, "Bastard exits the battle");
}

void KnightC::Abilites()
{
    TryAbility(30, skip_hod, "Knight skips the turn");
}

void BanditC::Abilites()
{
    int chance = rand() % 100 + 1;
    if (chance <= 60)
    {
        SetTextColor2(3);
        std::cout << name << "Double damag" << std::endl;
        this->damage *= 2;
    }
}

void ArcherC::Abilites()
{
    int chance = rand() % 100 + 1;
    if (chance <= 10)
    {
        SetTextColor2(3);
        std::cout << name << "Took two damage" << std::endl;
        this->damage += 2;

        if (target != nullptr)
        {
            target->hp -= 2;
        }
    }
}

EquipResult PlayerC::EquipError(int index)
{
    bool error_action = false;
    if (index < 0 || index >= inventory.items.size())
       error_action = ErrorOutput("Invalid index.");

    auto *weapon = dynamic_cast<Weapon *>(inventory.items[index]);
    if (!weapon)
        error_action = ErrorOutput("Selected item is not a weapon.");

    if (!this->CanEquip(weapon->weapon_type))
        error_action = ErrorOutput("cannot equip this weapon type.");

    if(equipped_weapons.size() >= max_num_of_weapons)
        error_action = ErrorOutput("You cannot equip more weapons.");

    if(error_action)
    {
        return {true, nullptr};
    }

    return {false, weapon};
}

void PlayerC::EquipAction(Weapon* weapon, int index)
{
    equipped_weapons.push_back(weapon);
    inventory.items.erase(inventory.items.begin() + index);

    this->damage += weapon->damage;

    std::cout << this->name << " equipped " << weapon->name << std::endl;
}

bool PlayerC::UseItem(int index)
{
    if (index < 0 || index >= inventory.items.size())
    {
        ErrorOutput("Invalid index. ");
        return false;
    }
    if (auto *potion = dynamic_cast<Health_PotkaC *>(inventory.items[index]))
    {
        std::cout << "Using " << potion->name << " to restore " << potion->health << " health points." << std::endl;
        this->hp += potion->health;
        delete inventory.items[index];
        inventory.items.erase(inventory.items.begin() + index);
    } else
    {
        ErrorOutput("Selected item is not a potion.");
        return false;
    }
    return true;
}


bool PlayerC::SellItem(int index)
{
    if (index >= 0 && index < inventory.items.size())
    {
        this->wallet += inventory.items[index]->price;
        std::cout << "Sold item: " << inventory.items[index]->name << " for " << inventory.items[index]->price << " gold." << std::endl;
        delete inventory.items[index];
        inventory.items.erase(inventory.items.begin() + index);
    } else
    {
        ErrorOutput("Invalid index. ");
        return false;
    }
    return true;
}
