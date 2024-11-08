#pragma once
#include <vector>
#include "Item.h"

class InventoryC
{
public:
    std::vector<ItemC *> items;

    void AddItem(ItemC *item);
    void DisplayInventory();
    ~InventoryC()
    {
        for (ItemC *item: items)
        {
            delete item;
        }
    }
};
