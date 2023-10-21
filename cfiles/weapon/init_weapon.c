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
        free(weapon->name);
        free(weapon);
    }

#if DEBUG
    if(weapon == NULL)   printf("\n weapon correctly free\n");
#endif

}

void add_loot_item(Level *level, Weapon *weapon, Armor *armor) {

    int index = 0;
    int place_in_weaponloot = MAX_LEVEL_LOOT_ITEM - get_first_level_loot_weapon_free_space(level);       // nombre de case libres dans le tableau d'armes
    int place_in_armorloot = MAX_LEVEL_LOOT_ITEM - get_first_level_loot_armor_free_space(level);         // nombre de case libres dans le tableau d'armures
    int inventory_left_size = 0;                                        // taille totale de l'inventaire

    inventory_left_size = (place_in_weaponloot + place_in_armorloot);

    if(weapon != NULL) {
        index = get_first_level_loot_weapon_free_space(level);

        if(inventory_left_size > MAX_LEVEL_LOOT_ITEM)
        {
            level->loot_weapon[index] = weapon;          // on stocke l'arme dans la case libre si il y a de la place dans le level loot
        }
        else {
            printf("pas de place pour une arme de plus !\n");
        }
    }
    else if(armor != NULL)
    {
        index = get_first_level_loot_armor_free_space(level);
        if(inventory_left_size > MAX_LEVEL_LOOT_ITEM)
        {
            level->loot_armor[index] = armor;          // on stocke l'armure dans la case libre si il y a de la place dans le level loot
        }
        else {
            printf("pas de place pour une armure de plus !\n");
        }
    }

}


/**
 * get the index of the first free space in the weapon level loot to add the item
 * @param level
 * @return
 */
int get_first_level_loot_weapon_free_space(Level *level) {

    int i = 0;
    while(level->loot_weapon[i] != NULL) {
        i++;
    }
    return i; // on retourne la case suivante
}

/**
 * get the index of the first free space in the weapon level loot to add the item
 * @param level
 * @return
 */
int get_first_level_loot_armor_free_space(Level *level) {

    int i = 0;
    while(level->loot_armor[i] != NULL) {
        i++;
    }

    return i; // on retourne la case suivante
}