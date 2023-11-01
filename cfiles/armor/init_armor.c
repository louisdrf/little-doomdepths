//
// Created by louis on 03/10/2023.
//

#include "../../headers/armor/init_armor.h"


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "../../headers/includes/structs.h"

#define DEBUG true

static int armorIDCounter = 1; // Initialisation du compteur

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

    armor->id = armorIDCounter++; // Générez un ID aléatoire pour l'armure

    // Initialisez la défense en fonction de la rareté
    switch (armor->rarity) {
        case COMMON:
            armor->defense = rand() % 11; // Points de défense de 0 à 10 pour une armure commune
            armor->name = "Common Armor";
            break;
        case RARE:
            armor->defense = rand() % 11 + 20; // Points de défense de 11 à 20 pour une armure rare
            armor->name = "Rare Plate";
            break;
        case EPIC:
            armor->defense = rand() % 20 + 30; // Points de défense de 20 à 30 pour une armure épique
            armor->name = "Epic Shield";
            break;
        case LEGENDARY:
            armor->defense = rand() % 30 + 40; // Points de défense de 0 à 40 pour une armure légendaire
            armor->name = "Legendary Helmet";
            break;
    }

    return armor;
}


