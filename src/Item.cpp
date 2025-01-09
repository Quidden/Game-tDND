#include "Item.h"

ItemC::ItemC(std::string name, std::string description, int rarity, int price)
    : name(name), description(description), rarity(rarity), price(price) {}
Health_PotkaC::Health_PotkaC(std::string name, std::string description, int rarity, int price, int health)
    : ItemC(name, description, rarity, price), health(health) {}
Luckest_PotkaC::Luckest_PotkaC(std::string name, std::string description, int rarity, int price, int die_bonus)
    : ItemC(name, description, rarity, price), die_bonus(die_bonus) {}
Equipten_Weapon_Class::Equipten_Weapon_Class(const std::string& name, const std::string& description, int rarity, int price, int damage, Equipted_Item_Type weapon_type)
    : Equipted_Items_Base(name, description, rarity, price, weapon_type), damage(damage) {}
Armor::Armor(const std::string& name, const std::string& description, int rarity, int price, int armor, int die_bonus_armor, Equipted_Item_Type weapon_type)
    : Equipted_Items_Base(name, description, rarity, price, weapon_type), armor(armor), die_bonus_armor(die_bonus_armor) {}


