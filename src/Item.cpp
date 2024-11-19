#include "Item.h"

ItemC::ItemC(std::string name, std::string description, int rarity, int price)
    : name(name), description(description), rarity(rarity), price(price) {}
Health_PotkaC::Health_PotkaC(std::string name, std::string description, int rarity, int price, int health)
    : ItemC(name, description, rarity, price), health(health) {}
Luckest_PotkaC::Luckest_PotkaC(std::string name, std::string description, int rarity, int price, int die_bonus)
    : ItemC(name, description, rarity, price), die_bonus(die_bonus) {}
Equipten_Items_Vector::Equipten_Items_Vector(std::string name, std::string description, int rarity, int price, int damage, int slot, Equipted_Item_Type weapon_type)
    :ItemC(name, description, rarity, price), damage(damage), slot(slot), weapon_type(weapon_type) {}
