#include "Item.h"

ItemC::ItemC(std::string name, std::string description, int rarity, int price)
    : name(name), description(description), rarity(rarity), price(price) {}
Health_PotkaC::Health_PotkaC(std::string name, std::string description, int rarity, int price, int health)
    : ItemC(name, description, rarity, price), health(health) {}
Luckest_PotkaC::Luckest_PotkaC(std::string name, std::string description, int rarity, int price, int die_bonus)
    : ItemC(name, description, rarity, price), die_bonus(die_bonus) {}
Armor::Armor(const std::string& name, const std::string& description, int rarity, int price, int armor, int die_bonus_armor)
    : Equipted_Items(name, description, rarity, price), armor(armor), die_bonus_armor(die_bonus_armor) {}

