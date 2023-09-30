//
// Created by louis on 30/09/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "../../headers/inventory/potion.h"
#include "../../headers/includes/structs.h"
#include "../../headers/includes/colors.h"

#define DEBUG true

void getPotion(Player *player) {

    int choice;

    choice = display_potion_choice();

    switch(choice) {
        case 1:
            printf("ajout dune potion de mana");
            give_player_potion(player, "mana");
            printf("\nVous recuperez une potion de mana. (+30)\n");
            break;

        case 2:
            printf("ajout dune potion de vie");
            give_player_potion(player, "health");
            printf("\nVous recuperez une potion de vie. (+30)\n");
            break;

        default:
            break;
    }
}


int display_potion_choice() {

    int playerEntry;

    printf("\n\n");
    printf(BLUE" mmm     "RESET RED" mmm\n");
    printf(BLUE" )-(     "RESET RED" )-(");
    printf("\n");
    printf(BLUE"(   )    "RESET RED"(   )\n");
    printf(BLUE"|   |    "RESET RED"|   |\n");
    printf(BLUE"|   |    "RESET RED"|   |\n");
    printf(BLUE"|___|    "RESET RED"|___|\n");
    printf(RESET"\n\n");
    printf("Potion de mana (1)        Potion de vie (2)\n\n-->  ");
    playerEntry = getch();
    playerEntry -= 48;                                  // décalage ASCII de la saisie pour obtenir la valeur numérique
    while(playerEntry != 1 && playerEntry != 2) {
        playerEntry = getch();
        playerEntry -= 48;
    }

    return playerEntry;
}


void give_player_potion(Player *player, char* type) {

    char* sprite = " mmm\n"
                   " )-(\n"
                   "(   )\n"
                   "|   |\n"
                   "|   |\n"
                   "|___|";

    if (strcmp(type, "mana") == 0)
    {
        Potion *manaPotion = createPotion("Potion de mana", sprite, 0, 30);
        if (manaPotion != NULL)
        {
            player->inventory->manaPotion = manaPotion;
        }
        else
        {
            Potion *healthPotion = createPotion("Potion de vie", sprite, 30, 0);
            if (healthPotion != NULL)
            {
                player->inventory->manaPotion = healthPotion;
            }

            #if DEBUG
                        printf("Erreur lors de la création de la potion de mana.\n");
            #endif
        }
    }
}

Potion *createPotion(const char* name, const char* sprite, int healthValue, int manaValue) {

    Potion *potion = malloc( sizeof(Potion));
    if(potion == NULL) {
        printf("allocate memory for potion failed\n");
    }

    if (potion != NULL) {
        potion->name = malloc(strlen(name) + 1);
        potion->sprite = malloc(strlen(sprite) + 1);

        if (potion->name != NULL && potion->sprite != NULL) {
            strcpy(potion->name, name);
            strcpy(potion->sprite, sprite);
            potion->healthValue = healthValue;
            potion->manaValue = manaValue;
        } else {
            printf("Allocation de mémoire pour le nom ou le sprite de la potion a échoué.\n");
            if (potion->name != NULL) {
                free(potion->name);
            }
            if (potion->sprite != NULL) {
                free(potion->sprite);
            }
            free(potion);
            potion = NULL;
        }
    } else {
        printf("Allocation de mémoire pour la potion a échoué.\n");
    }

    return potion;
}


void destroy_potion(Potion* potion) {
    if (potion != NULL) {
        free(potion->name);
        free(potion->sprite);
        free(potion);
    }
}