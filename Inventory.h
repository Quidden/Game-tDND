#include <iostream>
#include <vector>
#include "Item.h"
#include "Person.h"

class Inventory
{
public:
    std::vector<ItemC*> items;           
    std::vector<ItemC*> activeItems;      
    int baseDamage = 10;                
 
    void AddItem(Weapon* item, GameC* character)
    {
        if (character->CanEquip(item->weapon_type))
        {
            items.push_back(item);
            std::cout << character->name << " added item: " << item->name << " to inventory." << std::endl;
        }
        else
        {
            std::cout << character->name << " cannot equip " << item->name << std::endl;
        }
    }
  
    void AddItem(ItemC* item)
    {
        items.push_back(item);
        std::cout << "Added item: " << item->name << std::endl;
    }

    void EquipItem(int index, GameC* character)
    {
        if (index >= 0 && index < items.size())
        {
            Weapon* weapon = dynamic_cast<Weapon*>(items[index]);
            if (weapon && character->CanEquip(weapon->weapon_type))
            {
                activeItems.push_back(weapon);    
                items.erase(items.begin() + index); 
                std::cout << character->name << " equipped: " << weapon->name << std::endl;
            }
            else
            {
                std::cout << character->name << " cannot equip " << items[index]->name << std::endl;
            }
        }
        else
        {
            std::cout << "Invalid index." << std::endl;
        }
    }
   
    void UnequipItem(int index)
    {
        if (index >= 0 && index < activeItems.size())
        {
            items.push_back(activeItems[index]);
            std::cout << "Unequipped item: " << activeItems[index]->name << std::endl;
            activeItems.erase(activeItems.begin() + index);
        }
        else
        {
            std::cout << "Invalid index." << std::endl;
        }
    }
   
    int GetTotalDamage() const
    {
        int totalDamage = baseDamage;
        for (const ItemC* item : activeItems)
        {
            const Weapon* weapon = dynamic_cast<const Weapon*>(item);
            if (weapon)
            {
                totalDamage += weapon->damage;  
            }
        }
        return totalDamage;
    }
 
    void DisplayInventory() const
    {
        std::cout << "Inventory contents:" << std::endl;
        for (int i = 0; i < items.size(); ++i)
        {
            std::cout << i << ": " << items[i]->name << " - " << items[i]->description << std::endl;
        }
    }

    void DisplayEquippedItems() const
    {
        std::cout << "Equipped items:" << std::endl;
        for (int i = 0; i < activeItems.size(); ++i)
        {
            std::cout << i << ": " << activeItems[i]->name << " - " << activeItems[i]->description << std::endl;
        }
    }
  
    ~Inventory()
    {
        for (ItemC* item : items)
        {
            delete item;
        }
        for (ItemC* item : activeItems)
        {
            delete item;
        }
    }
};

