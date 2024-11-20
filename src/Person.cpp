#include "Person.h"
#include <Windows.h>
#include "Function.h"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define RESET   "\033[0m"

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
    //int hp_bonus = 0;
    int damage_bonus = 0;

    if (auto* Player = dynamic_cast<PlayerC*>(this))
    {
        //If you want to add a new element, just enter a new value into the internal if as already done here
        for (const auto& items : Player->equipped_items) //range cycle!!!
        {
            if (auto* weapon = dynamic_cast<Equipten_Items_Class*>(items))
            {
                damage_bonus += weapon->damage;
            }
        }
    }
    if(damage_bonus >= 0)
        std::cout << name << ": " << hp << " HP, Damage " << damage <<GREEN<<"("<<damage_bonus<<")"<<RESET<<", Die Bonus " << die_bonus << std::endl;
    else
        std::cout << name << ": " << hp << " HP, Damage " << damage <<RED<<"("<<damage_bonus<<")"<<RESET<<", Die Bonus " << die_bonus << std::endl;

}

void PlayerC::TryAbility(int chanceThreshold, bool &effectFlag, const std::string &abilityMessage)
{
    int chance = rand() % 100 + 1;
    if (chance <= chanceThreshold)
    {
        effectFlag = true;
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
        std::cout << name << "Double damag" << std::endl;
        this->damage *= 2;
    }
}

void ArcherC::Abilites()
{
    int chance = rand() % 100 + 1;
    if (chance <= 10)
    {
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

    auto *equipted_item = dynamic_cast<Equipted_Items_Base *>(inventory.items[index]);
    if (!equipted_item)
        error_action = ErrorOutput("You've chosen an unequipped item.");

    std::cin.get();
    std::cout << RED <<"Trying to equip item of type: " << RESET << static_cast<int>(equipted_item->Item_Type) << std::endl;
    std::cin.get();

    if (!this->CanEquip(equipted_item->Item_Type))
        error_action = ErrorOutput("You cannot equip this type of item on a hero.");

    if(equipped_items.size() >= max_num_of_weapons)
        error_action = ErrorOutput("You can't equip more items.");

    if(error_action)
    {
        return {true, nullptr};
    }

    return {false, equipted_item};
}

void PlayerC::EquipAction(Equipted_Items_Base* Equipted_Items, int index)
{
    equipped_items.push_back(Equipted_Items);
    inventory.items.erase(inventory.items.begin() + index);

    if (auto* weapon = dynamic_cast<Equipten_Items_Class*>(Equipted_Items)) //Understand type casting
    {
        this->damage += weapon->damage;
    }

    //this->damage += Equipted_Items->damage;

    std::cout << this->name << " equipped " << Equipted_Items->name << std::endl;
}

bool PlayerC::UseItem(int index)
{
    if (index < 0 || index > inventory.items.size())
    {
        ErrorOutput("Invalid index. ");
        return false;
    }
    if (auto *potion = dynamic_cast<Health_PotkaC *>(inventory.items[index]))
    {
        std::cout << "Using " << potion->name << " to restore " << potion->health << " health points." << std::endl;
        this->hp += potion->health;
        if (inventory.items[index] != nullptr)
        {
            delete inventory.items[index];
            inventory.items[index] = nullptr;
        }
        inventory.items.erase(inventory.items.begin() + index);
    }
    else
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
