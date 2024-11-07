#include <iostream>
#include <vector>
#include "Item.h"
#include "Person.h"

class Inventory
{
public:
    std::vector<ItemC*> items;
    ItemC* equipped_weapon = nullptr;
 
    void AddItem(ItemC* item, PlayerC* character)
    {
        if (Weapon* weapon = dynamic_cast<Weapon*>(item))
        {
            if (character->CanEquip(weapon->weapon_type))
            {
                items.push_back(item);
                std::cout << character->name << " added item: " << item->name << std::endl;
            }
            else
            {
                std::cout << character->name << " cannot equip " << item->name << std::endl;
            }
        }
        else
        {
            items.push_back(item);
            std::cout << "Added item: " << item->name << std::endl;
        }
    }

    void EquipWeapon(int index, PlayerC* character)
    {
        if (index >= 0 && index < items.size())
        {
            if (Weapon* weapon = dynamic_cast<Weapon*>(items[index]))
            {
                if (character->CanEquip(weapon->weapon_type))
                {
                    equipped_weapon = weapon;
                    std::cout << character->name << " equipped " << weapon->name << std::endl;
                }
                else
                {
                    std::cout << character->name << " cannot equip this weapon type." << std::endl;
                }
            }
            else
            {
                std::cout << "Selected item is not a weapon." << std::endl;
            }
        }
        else
        {
            std::cout << "Invalid index." << std::endl;
        }
    }
   
    void UseItem(int index, PlayerC* character)
    {
        if (index >= 0 && index < items.size())
        {
            if (Health_PotkaC* potion = dynamic_cast<Health_PotkaC*>(items[index]))
            {
                std::cout << "Using " << potion->name << " to restore " << potion->health << " health points." << std::endl;
                character->hp += potion->health;
                delete items[index];
                items.erase(items.begin() + index); 
            }
            else
            {
                std::cout << "Selected item is not a potion." << std::endl;
            }
        }
        else
        {
            std::cout << "Invalid index." << std::endl;
        }
    }
   
    void DisplayInventory()
    {
        std::cout << "Inventory contents:" << std::endl;
        for (int i = 0; i < items.size(); ++i) {
            std::cout << i << ": " << items[i]->name << " - " << items[i]->description << std::endl;
        }
    }
 
    int GetTotalDamage(int base_damage)
    {
        base_damage += (equipped_weapon ? dynamic_cast<Weapon*>(equipped_weapon)->damage : 0);
        return base_damage;
    }

    void SellItem(int index, int& player_gold)
    {
        if (index >= 0 && index < items.size())
        {
            player_gold += items[index]->price;
            std::cout << "Sold item: " << items[index]->name << " for " << items[index]->price << " gold." << std::endl;
            delete items[index];
            items.erase(items.begin() + index); // Удаляем предмет из инвентаря
        }
        else
        {
            std::cout << "Invalid index." << std::endl;
        }
    }
  
    ~Inventory()
    {
        for (ItemC* item : items) {
            delete item;
        }
    }
};

