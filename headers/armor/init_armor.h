//
// Created by louis on 03/10/2023.
//

#ifndef DOOM_INIT_ARMOR_H
#define DOOM_INIT_ARMOR_H

#include "../includes/structs.h"

Armor *init_armor(char *name, int defense, int rarity);
void setArmorName(Armor *armor, char *name);
void free_armor(Armor *armor);
Armor *randomArmor();
void display_armor_stats(Armor *armor);

#endif //DOOM_INIT_ARMOR_H
