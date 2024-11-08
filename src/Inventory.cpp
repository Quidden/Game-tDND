#include "Inventory.h"
#include "Item.h"
#include "vector"

std::vector<ItemC *> items;

void AddItem(ItemC *item)
{
    items.push_back(item);
    std::cout << "Added item: " << item->name << std::endl;
}
void DisplayInventory()
{
    std::cout << "Inventory contents:" << std::endl;
    for (int i = 0; i < items.size(); ++i)
    {
        std::cout << i << ": " << items[i]->name << " - " << items[i]->description << std::endl;
    }
}

