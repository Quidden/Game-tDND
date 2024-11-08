#include "Person.h"
#include <Windows.h>

void SetTextColor2(int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

PersonC::PersonC(std::string name, std::string description, int hp, int damage, int die_bonus)
    : name(std::move(name)), description(std::move(description)), hp(hp), damage(damage), die_bonus(die_bonus)
{
}
PlayerC::PlayerC(std::string name, std::string description, int hp, int damage, int die_bonus, CharacterType charter_type)
    : PersonC(std::move(name), std::move(description), hp, damage, die_bonus), charter_type(charter_type)
{
}
BastardC::BastardC(std::string name, std::string description, int hp, int damage, int die_bonus, CharacterType charter_type)
    : PlayerC(std::move(name), std::move(description), hp, damage, die_bonus, charter_type)
{
}
KnightC::KnightC(std::string name, std::string description, int hp, int damage, int die_bonus, CharacterType charter_type)
    : PlayerC(std::move(name), std::move(description), hp, damage, die_bonus, charter_type)
{
}
BanditC::BanditC(std::string name, std::string description, int hp, int damage, int die_bonus, CharacterType charter_type)
    : PlayerC(std::move(name), std::move(description), hp, damage, die_bonus, charter_type)
{
}
ArcherC::ArcherC(std::string name, std::string description, int hp, int damage, int die_bonus, CharacterType charter_type)
    : PlayerC(std::move(name), std::move(description), hp, damage, die_bonus, charter_type)
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
    }
    else
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

void PlayerC::EquipWeapon(int index)
{
    if (index < 0 || index >= items.size())
    {
        std::cout << "Invalid index." << std::endl;
        std::cin.get();
        return;
    }
    auto *weapon = dynamic_cast<Weapon *>(items[index]);
    if (!weapon)
    {
        std::cout << "Selected item is not a weapon." << std::endl;
        std::cin.get();
        return;
    }
    if (!this->CanEquip(weapon->weapon_type))
    {
        std::cout << this->name << " cannot equip this weapon type." << std::endl;
        std::cin.get();
        return;
    }
    equipped_weapon = weapon;
    std::cout << this->name << " equipped " << weapon->name << std::endl;
}
void PlayerC::UseItem(int index)
{
    if (index < 0 || index >= items.size())
    {
        std::cout << "Invalid index." << std::endl;
    } else if (auto *potion = dynamic_cast<Health_PotkaC *>(items[index]))
    {
        std::cout << "Using " << potion->name << " to restore " << potion->health << " health points." << std::endl;
        this->hp += potion->health;
        delete items[index];
        items.erase(items.begin() + index);
    } else
    {
        std::cout << "Selected item is not a potion." << std::endl;
    }
    std::cin.get();
}
int PlayerC::AdjustDamage(bool add)
{
    int weapon_damage = equipped_weapon ? dynamic_cast<Weapon *>(equipped_weapon)->damage : 0;
    this->damage += add ? weapon_damage : -weapon_damage;
    return this->damage;
}
void PlayerC::SellItem(int index, int &player_gold)
{
    if (index >= 0 && index < items.size())
    {
        player_gold += items[index]->price;
        std::cout << "Sold item: " << items[index]->name << " for " << items[index]->price << " gold." << std::endl;
        delete items[index];
        items.erase(items.begin() + index);
    } else
    {
        std::cout << "Invalid index." << std::endl;
    }
}
