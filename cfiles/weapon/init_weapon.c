//
// Created by mokrane on 28/09/2023.
//

#include "../../headers/weapon/init_weapon.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../../headers/includes/structs.h"

#define DEBUG true

Weapon *init_weapon(char *name, int att_by_turn, int min_strength, int max_strength, int mana_cost, int rarity) {

    Weapon *weapon;
    weapon= malloc(sizeof(Weapon));

    if(weapon == NULL) {
    #if DEBUG
            printf("Allocating memory for weapon failed.\n");
    #endif
            exit(1);
    }

    setWeaponName(weapon, name);

    weapon->min_strength = min_strength;
    weapon->max_strength = max_strength;
    weapon->attacks_by_turn = att_by_turn;
    weapon->mana_cost = mana_cost;
    weapon->rarity= rarity;
    init_weapon_draw(weapon);

    if(weapon == NULL) {
#if DEBUG
        printf("Error while creating weapon.\n");
#endif
        exit(1);
    }

    return weapon;
}


void setWeaponName(Weapon *weapon, char *name) {
    weapon->name=malloc(strlen(name) + 1);
    strcpy(weapon->name, name);
}

void init_weapon_draw(Weapon *weapon) {
    char *draw="   o\n"
               "     X\n"
               "     X\n"
               "|===[O]===|\n"
               "    |||\n"
               "    |||\n"
               "    |||\n"
               "    |||\n"
               "    |||\n"
               "    |||\n"
               "    |||\n"
               "    |||\n"
               "    |||\n"
               "    |^|\n"
               "    \\ /\n"
               "     `";
    weapon->draw = malloc((strlen(draw)) + 1);
    strcpy(weapon->draw, draw);
    if(strlen(weapon->draw) == 0) {
        printf("Error while drawing the weapon.\n");
        exit(1);
    }
}

void free_weapon(Weapon *weapon) {
    if(weapon != NULL) {
        free(weapon->draw);
        free(weapon);
    }

#if DEBUG
    if(weapon == NULL)   printf("\n weapon correctly free\n");
#endif

}