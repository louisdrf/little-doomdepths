//
// Created by louis on 03/10/2023.
//

#include "../../headers/armor/init_armor.h"


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../../headers/includes/structs.h"

#define DEBUG true

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
    if(armor != NULL) {
        free(armor->name);
        free(armor);
    }

#if DEBUG
    if(armor == NULL)   printf("\n armor correctly free\n");
#endif

}


