//
// Created by mokrane on 28/09/2023.
//

#include "../../headers/weapon/init_weapon.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../../headers/includes/colors.h"
#include "../../headers/utils.h"
#include "../../headers/weapon/init_random_weapon_name.h"

#define DEBUG false

Weapon *init_weapon(char *name, int att_by_turn, int min_strength, int max_strength, int mana_cost, int rarity) {

    Weapon *weapon;
    weapon = malloc(sizeof(Weapon));

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



/*void add_loot_item(Level *level, Weapon *weapon, Armor *armor) {

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



int get_first_level_loot_weapon_free_space(Level *level) {

    int i = 0;
    while(level->loot_weapon[i] != NULL) {
        i++;
    }
    return i; // on retourne la case suivante
}


int get_first_level_loot_armor_free_space(Level *level) {

    int i = 0;
    while(level->loot_armor[i] != NULL) {
        i++;
    }

    return i;
}*/

Weapon *randomWeapon() {
    Weapon *weapon = malloc(sizeof(Weapon));

    if(weapon == NULL) {
#if DEBUG
        printf("Allocating memory for weapon failed.\n");
#endif
        exit(1);
    }

    int rarityRoll = rand() % 95;

    if (rarityRoll < 60) {
        weapon->rarity = COMMON;
    } else if (rarityRoll < 85) {
        weapon->rarity = RARE;
    } else if (rarityRoll < 95) {
        weapon->rarity = EPIC;
    } else {
        weapon->rarity = LEGENDARY;
    }

    weapon->id = rand();

    switch (weapon->rarity) {
        case COMMON:
            set_random_weapon_name(weapon);
            weapon->min_strength = random_int(8, 8);
            weapon->max_strength = random_int(14, 14);
            weapon->attacks_by_turn = 2;
            weapon->mana_cost = random_int(2, 4);
            break;

        case RARE:
            set_random_weapon_name(weapon);
            weapon->min_strength = random_int(10, 14);
            weapon->max_strength = random_int(14, 20);
            weapon->attacks_by_turn = 2;
            weapon->mana_cost = random_int(3, 5);
            break;

        case EPIC:
            set_random_weapon_name(weapon);
            weapon->min_strength = random_int(16, 16);
            weapon->max_strength = random_int(18, 25);
            weapon->attacks_by_turn = random_int(2, 3);
            weapon->mana_cost = random_int(4, 6);
            break;

        case LEGENDARY:
            set_random_weapon_name(weapon);
            weapon->min_strength = random_int(20, 22);
            weapon->max_strength = random_int(30, 34);
            weapon->attacks_by_turn = random_int(2, 3);
            weapon->mana_cost = random_int(4, 8);
            break;
    }

return weapon;
}


void display_weapon_stats(Weapon *weapon) {

    printf("Arme : ");
    printf(MAGENTA"%s "RESET, weapon->name);
    printf("| att : ");
    printf(RED"%d-%d "RESET, weapon->min_strength, weapon->max_strength);
    printf("| cout en mana : ");
    printf(BLUE"%d "RESET, weapon->mana_cost);
    printf("| nombre attaques /tour : ");
    printf(YELLOW"%d "RESET, weapon->attacks_by_turn);
    printf("| rarete : ");
    display_rarity(weapon->rarity);


}


void equip_weapon(Player *player, Weapon *w) {

    player->current_weapon = w;
    player->min_strength = w->min_strength;
    player->max_strength = w->max_strength;
    player->attacks_by_turn = w->attacks_by_turn;
}


void display_rarity(int rarity) {

    switch(rarity) {
        case COMMON:
            printf(GREEN"commune"RESET);
            break;

        case RARE:
            printf(BLUE"rare"RESET);
            break;

        case EPIC:
            printf(MAGENTA"epique"RESET);
            break;

        case LEGENDARY:
            printf(YELLOW"*legendaire*"RESET);
            break;
    }
}