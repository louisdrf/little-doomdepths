//
// Created by louis on 27/09/2023.
//

#ifndef DOOM_INVENTORY_H
#define DOOM_INVENTORY_H

#include "../includes/structs.h"

void add_item(Player *player, Weapon *weapon, Armor *armor);
int get_first_weapon_free_space(Player *player);
int get_first_armor_free_space(Player *player);
void display_inventory_content(Player *player);

#endif //DOOM_INVENTORY_H
