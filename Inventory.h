#include <iostream>
#include <vector>
#include "Item.h"

class Inventory 
{
public:
    std::vector<ItemC*> items;      
    std::vector<ItemC*> activeItems; 
    int baseDamage = 10;             

    void AddItem(ItemC* item) 
    {
        items.push_back(item);
        std::cout << "Added item: " << item->name << std::endl;
    }

    void RemoveItem(int index) 
    {
        if (index >= 0 && index < items.size()) 
        {
            delete items[index];
            items.erase(items.begin() + index);
            std::cout << "Removed item at index " << index << std::endl;
        }
        else 
        {
            std::cout << "Invalid index." << std::endl;
        }
    }

    void DisplayInventory() const 
    {
        std::cout << "Inventory contents:" << std::endl;
        for (int i = 0; i < items.size(); ++i) 
        {
            std::cout << i << ": " << items[i]->name << " - " << items[i]->description << std::endl;
        }
    }

    void ActivateItem(int index) 
    {
        if (index >= 0 && index < items.size()) 
        {
            activeItems.push_back(items[index]);
            std::cout << "Activated item: " << items[index]->name << std::endl;
        }
        else 
        {
            std::cout << "Invalid index." << std::endl;
        }
    }

    void DeactivateItem(int index) 
    {
        if (index >= 0 && index < activeItems.size()) 
        {
            std::cout << "Deactivated item: " << activeItems[index]->name << std::endl;
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

    ~Inventory()
    {
        for (ItemC* item : items) 
        {
            delete item;
        }
    }
};
