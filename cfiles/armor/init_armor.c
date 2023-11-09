//
// Created by louis on 03/10/2023.
//

#include "../../headers/armor/init_armor.h"


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "../../headers/includes/structs.h"
#include "../../headers/includes/colors.h"
#include "../../headers/weapon/init_weapon.h"
#include "../../headers/rand.h"
#include "../../headers/armor/init_random_armor_name.h"

#define DEBUG false

Armor *init_armor(char *name, int defense, int rarity) {

    Armor *armor;
    armor= malloc(sizeof(Armor));

    if(armor == NULL) {
#if DEBUG
        printf("Allocating memory for armor failed.\n");
#endif
        exit(1);
    }

    setArmorName(armor, name);

    armor->rarity = rarity;
    armor->defense = defense;

    if(armor == NULL) {
#if DEBUG
        printf("Error while creating armor.\n");
#endif
        exit(1);
    }

    return armor;
}


void setArmorName(Armor *armor, char *name) {
    armor->name=malloc(strlen(name) + 1);
    strcpy(armor->name, name);
}

void free_armor(Armor *armor) {

    printf("armor name : %s\n", armor->name);
    free(armor->name);
    free(armor);

}

Armor *randomArmor() {
    Armor *armor = malloc(sizeof(Armor));

    if (armor == NULL) {
#if DEBUG
        printf("Allocating memory for armor failed.\n");
#endif
        exit(1);
    }

    int rarityRoll = rand() % 95;

    if (rarityRoll < 60) {
        armor->rarity = COMMON;
    } else if (rarityRoll < 85) {
        armor->rarity = RARE;
    } else if (rarityRoll < 95) {
        armor->rarity = EPIC;
    } else {
        armor->rarity = LEGENDARY;
    }

    armor->id = rand();

    switch (armor->rarity) {
        case COMMON:
            armor->defense = random_int(3, 6);
            set_random_armor_name(armor);
            break;
        case RARE:
            armor->defense = random_int(6, 10);
            set_random_armor_name(armor);
            break;
        case EPIC:
            armor->defense = random_int(12, 15);
            set_random_armor_name(armor);
            break;
        case LEGENDARY:
            armor->defense = random_int(20, 30);
            set_random_armor_name(armor);
            break;
    }

    return armor;
}


void display_armor_stats(Armor *armor) {

    printf("Armure : ");
    printf(MAGENTA"%s "RESET, armor->name);
    printf("| defense : ");
    printf(BLUE"%d "RESET, armor->defense);
    printf("| rarete : ");
    display_rarity(armor->rarity);

}


