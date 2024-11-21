#include "Inventory.h"
#include "Item.h"
#include "vector"

std::vector<ItemC *> items;

void InventoryC::AddItem(ItemC *item)
{
    this->items.push_back(item);
    std::cout << "Added item: " << item->name << std::endl;
}
void InventoryC::DisplayInventory()
{
    std::cout << "Inventory contents:" << std::endl;
    for (int i = 0; i < items.size(); ++i)
    {
        std::cout << i << ": " << items[i]->name << " - " << items[i]->description << std::endl;
    }
}


