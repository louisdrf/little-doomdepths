//
// Created by louis on 30/09/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include "../../headers/inventory/potion.h"
#include "../../headers/includes/structs.h"
#include "../../headers/includes/colors.h"

#define DEBUG true

void getPotion(Player *player) {

    srand(time(NULL));

    unsigned short choice;

    unsigned short potionType = rand() % 2 + 1;

    choice = display_potion_choice(potionType);

    switch(choice) {
        case 1:     // utiliser la potion
            use_potion(player, potionType);
            break;

        case 2:     // stocker la potion en inventaire
            give_player_potion(player, potionType);
            printf("\nPotion ajoutee a l'inventaire. (+30)\n");
            break;

        default:
            break;
    }
}

/**
 * chose to keep it in inventory or using it immediatly
 * @param potionType
 * @return
 */
int display_potion_choice(unsigned short potionType) {

    unsigned short playerEntry;

    switch(potionType) {

        case 1:  // potion de mana
            printf("\n\n");
            printf(BLUE" mmm\n");
            printf(BLUE" |-|\n");
            printf(BLUE"(   )\n");
            printf(BLUE"|   |\n");
            printf(BLUE"|   |\n");
            printf(BLUE"|___|\n");
            printf(RESET"\n\n");
            break;

        case 2: // potion de vie
            printf("\n\n");
            printf(RED" mmm\n");
            printf(RED" |-|\n");
            printf(RED"(   )\n");
            printf(RED"|   |\n");
            printf(RED"|   |\n");
            printf(RED"|___|\n");
            printf(RESET"\n\n");
        break;
    }

    printf("Utiliser (1)       Garder dans l'inventaire (2)\n\n-->  ");
    playerEntry = getch();
    playerEntry -= 48;
    while(playerEntry != 1 && playerEntry != 2) {
        playerEntry = getch();
        playerEntry -= 48;
    }

    return playerEntry;
}

void use_potion(Player *player, unsigned short potionType) {

    switch(potionType)      // potion de mana
    {
        case 1: // potion de mana
        if((player->mana + 30) >= player->mana_max) player->mana = 100;
        else player->mana += 30;
            printf("\nVous recuperez 30 points de mana.\n");
            break;

        case 2: // potion de vie
            if((player->lifepoints + 30) >= player->lifepoints_max) player->lifepoints = 100;
            else player->lifepoints += 30;
            printf("\nVous recuperez 30 points de vie.\n");
            break;
    }
}

void give_player_potion(Player *player, unsigned short type) {

    char* sprite = " mmm\n"
                   " |-|\n"
                   "(   )\n"
                   "|   |\n"
                   "|   |\n"
                   "|___|";

    if (type == 1)      // potion de mana
    {
        Potion *manaPotion = createPotion("Potion de mana", sprite, 0, 30);
        if (manaPotion != NULL)
        {
            player->inventory->manaPotion = manaPotion;
        }
        else {
            #if DEBUG
            printf("Erreur lors de la création de la potion de mana.\n");
            #endif
        }
    }
    else                // potion de vie
        {
            Potion *healthPotion = createPotion("Potion de vie", sprite, 30, 0);
            if (healthPotion != NULL)
            {
                player->inventory->healthPotion = healthPotion;
            }
            else {
                #if DEBUG
                printf("Erreur lors de la création de la potion de vie.\n");
                #endif
            }

        }
}

Potion *createPotion(const char* name, const char* sprite, unsigned short healthValue, unsigned short manaValue) {

    Potion *potion = malloc( sizeof(Potion));

    if (potion != NULL) {
        potion->name = malloc(strlen(name) + 1);
        potion->sprite = malloc(strlen(sprite) + 1);

        if (potion->name != NULL && potion->sprite != NULL) {
            strcpy(potion->name, name);
            strcpy(potion->sprite, sprite);
            potion->healthValue = healthValue;
            potion->manaValue = manaValue;
        } else {
            printf("allocate memory for potion sprite or name failed.\n");
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
        printf("allocate memory for potion failed.\n");
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