//
// Created by mokrane on 28/09/2023.
//

#ifndef DOOM_CREATE_WEAPON_H
#define DOOM_CREATE_WEAPON_H
#include "../includes/structs.h"

Weapon *init_weapon(char *name, int att_by_turn, int min_strength, int max_strength, int mana_cost, int rarity);
void free_weapon(Weapon *weapon);
void setWeaponName(Weapon *weapon, char *name);
void add_loot_item(Level *level, Weapon *weapon, Armor *armor);
int get_first_level_loot_weapon_free_space(Level *level);
int get_first_level_loot_armor_free_space(Level *level);
Weapon *randomWeapon();
void display_weapon_stats(Weapon *weapon);
void display_rarity(int rarity);
void equip_weapon(Player *player, Weapon *w);

#endif //DOOM_CREATE_WEAPON_H