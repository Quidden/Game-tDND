#include "Person.h"
#include <Windows.h>
#include "Function.h"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define RESET   "\033[0m"

PersonC::PersonC(int hp, int damage, int die_bonus)
    : hp(hp), damage(damage), die_bonus(die_bonus)
{
}

PlayerC::PlayerC(int hp, int damage, int die_bonus, int wallet, int max_num_of_weapons, CharacterType charter_type)
    : PersonC(hp, damage, die_bonus),max_num_of_weapons(max_num_of_weapons), wallet(wallet), charter_type(charter_type)
{
}

EnemyC::EnemyC(std::string name, std::string description, int hp, int damage, int die_bonus, int reward)
    : PersonC(hp, damage, die_bonus), name(name), description(description),reward(reward)
{
}

const std::string BastardC::className = "Bastard";
const std::string BastardC::classDescription = "Test1";
void BastardC::Abilites()
{
    TryAbility(10, exit_the_battle, "Bastard exits the battle");
}

const std::string KnightC::className = "Knight";
const std::string KnightC::classDescription = "Test2";
void KnightC::Abilites()
{
    TryAbility(30, skip_hod, "Knight skips the turn");
}

const std::string BanditC::className = "Bandit";
const std::string BanditC::classDescription = "Test3";
void BanditC::Abilites()
{
    int chance = rand() % 100 + 1;
    if (chance <= 60)
    {
        std::cout <<  "Bandit get Double damag" << std::endl;
        this->damage *= 2;
    }
}

const std::string ArcherC::className = "Archer";
const std::string ArcherC::classDescription = "Test4";
void ArcherC::Abilites()
{
    int chance = rand() % 100 + 1;
    if (chance <= 10)
    {
        std::cout << "Archer get Took two damage" << std::endl;
        this->damage += 2;

        if (target != nullptr)
        {
            target->SetHP(target->GetHP() - 2);
        }
    }
}


bool PersonC::IsAlive()
{
    return hp > 0;
}

void PersonC::DisplayStatus(const PlayerC& player)
{
    //int hp_bonus = 0;
    int damage_bonus = 0;
    auto* Player = dynamic_cast<PlayerC*>(this);
    if (Player != nullptr)
    {
        //If you want to add a new element, just enter a new value into the internal if as already done here
        for (const auto& items : Player->equipped_items) //range cycle!!!
        {
            if (auto* weapon = items->AsType<Equipten_Weapon_Class>())
            {
                damage_bonus += weapon->damage;
            }
        }
    }
    if(damage_bonus >= 0)
        std::cout << player.GetClassName() << ": " << hp << " HP, Damage " << damage <<GREEN<<"("<<damage_bonus<<")"<<RESET<<", Die Bonus " << die_bonus << std::endl;
    else
        std::cout << player.GetClassName() << ": " << hp << " HP, Damage " << damage <<RED<<"("<<damage_bonus<<")"<<RESET<<", Die Bonus " << die_bonus << std::endl;

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

EquipResult PlayerC::EquipError(int index)
{
    bool error_action = false;
    Equipted_Items_Base* equipted_item = nullptr;

    if (index < 0 || index >= inventory.items.size())
       error_action = ErrorOutput("Invalid index.");

    if(!inventory.items[index]->IsType<Equipted_Items_Base>())
        error_action = ErrorOutput("You've chosen an unequipped item.");
    else
        auto* equipted_item = inventory.items[index]->AsType<Equipted_Items_Base>();


    if (!equipted_item)
        error_action = ErrorOutput("You've chosen an unequipped item.");

        /*if(!error_action)
        {
            std::cin.get();
            std::cout << RED <<"Trying to equip item of type: " << RESET << static_cast<int>(equipted_item->Item_Type) << std::endl;
            std::cout << RED <<"Trying to equip item of type: " << RESET <<static_cast<int>(equipted_item->Item_Type) << std::endl;
            std::cout << RED <<"Knight can equip this type: " << RESET <<(equipted_item->Item_Type == Equipted_Item_Type::Sword ? "Yes" : "No") << std::endl;
            std::cin.get();
        }*/

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

    if (Equipted_Items->IsType<Equipten_Weapon_Class>())
    {
        this->damage += Equipted_Items->AsType<Equipten_Weapon_Class>()->damage;
    }

    //this->damage += Equipted_Items->damage;

    std::cout << this->GetClassName() << " equipped " << Equipted_Items->name << std::endl;
}

bool PlayerC::UseItem(int index)
{
    if (index < 0 || index > inventory.items.size())
    {
        ErrorOutput("Invalid index. ");
        return false;
    }
    if (inventory.items[index]->IsType<Health_PotkaC>())
    {
        auto* potion = inventory.items[index]->AsType<Health_PotkaC>();
        std::cout << "Using " << potion->name << " to restore " << potion->health << " health points." << std::endl;
        this->hp += potion->health;
        delete inventory.items[index];
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
