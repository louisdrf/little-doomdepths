//
// Created by mokrane on 28/09/2023.
//

#ifndef DOOM_CREATE_WEAPON_H
#define DOOM_CREATE_WEAPON_H
#include "../includes/structs.h"

Weapon *init_weapon();
void init_weapon_draw(Weapon *weapon);
void free_weapon(Weapon *weapon);
void setWeaponName(Weapon *weapon, char *name);

#endif //DOOM_CREATE_WEAPON_H