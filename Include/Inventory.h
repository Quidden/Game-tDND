#include <vector>
#include "Item.h"

class InventoryC
{
public:
    std::vector<ItemC*> items;

    void AddItem(ItemC* item)
    {
        items.push_back(item);
        std::cout << "Added item: " << item->name << std::endl;
    }

    void SellItem(int index, int& player_gold)
    {
        if (index >= 0 && index < items.size())
        {
            player_gold += items[index]->price;
            std::cout << "Sold item: " << items[index]->name << " for " << items[index]->price << " gold." << std::endl;
            delete items[index];
            items.erase(items.begin() + index);
        }
        else
        {
            std::cout << "Invalid index." << std::endl;
        }
    }

    void DisplayInventory()
    {
        std::cout << "Inventory contents:" << std::endl;
        for (int i = 0; i < items.size(); ++i)
        {
            std::cout << i << ": " << items[i]->name << " - " << items[i]->description << std::endl;
        }
    }

    ~InventoryC()
    {
        for (ItemC* item : items)
        {
            delete item;
        }
    }
};

