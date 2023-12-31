//
// Created by louis on 03/10/2023.
//

#ifndef DOOM_INIT_ARMOR_H
#define DOOM_INIT_ARMOR_H

#include "../includes/structs.h"

Armor *init_armor(char *name, int defense, int rarity);
void setArmorName(Armor *armor, char *name);
Armor *randomArmor();
void display_armor_stats(Armor *armor);

#endif //DOOM_INIT_ARMOR_H
