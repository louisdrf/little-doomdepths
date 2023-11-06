//
// Created by louis on 04/11/2023.
//

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "../../headers/player/display_player_equipment.h"
#include "../../headers/includes/colors.h"
#include "../../headers/inventory/inventory.h"

void display_player_equipment(Player *player) {

    int playerEntry;
    system("cls");

    if(player->current_weapon != NULL) {
        printf("---------------ARME--------------- \n| ");
        printf("%s | ", player->current_weapon->name); // nom de l'arme
        printf("att : ");                                                                                                           // affiche l'attaque min et max de l'attaque
        printf(RED"%d-%d "RESET, player->current_weapon->min_strength, player->current_weapon->max_strength);
        printf("|  ");
        printf("mana : ");
        printf(BLUE "%d \n"RESET, player->current_weapon->mana_cost);
        printf("----------------------------------\n");
    }
    else {
        printf("---------------ARME--------------- \n| ");
        printf(RED"aucune arme equipee\n"RESET);
        printf("----------------------------------\n");
    }

    if(player->current_armor != NULL) {
        printf("--------------ARMURE-------------- \n| ");
        printf("%s | ", player->current_armor->name); // nom de l'arme
        printf("def : ");                                                                                                           // affiche l'attaque min et max de l'attaque
        printf(BLUE"%d \n"RESET, player->current_armor->defense);
        printf("----------------------------------\n");
    }
    else {
        printf("--------------ARMURE-------------- \n| ");
        printf(RED"aucune armure equipee\n"RESET);
        printf("--------------------------------\n");
    }

    if(player->current_weapon != NULL) {
        printf("\nDesequipper l'arme   (1)");
        if(player->current_armor == NULL) {
            printf("\n");
        }
    }
    if(player->current_armor != NULL) {
        printf("\nDesequipper l'armure (2)\n");
    }
        printf(RED"Retour               (3)\n"RESET);
    printf("-> ");

    playerEntry = getch() - 48;
    switch(playerEntry) {
        case 1:
            add_item(player, player->current_weapon, NULL);
            player->current_weapon = NULL;
            player->min_strength = 10;
            player->max_strength = 16;
            if(player->attacks_by_turn != 2) player->attacks_by_turn = 2;
            break;

        case 2:
            add_item(player, NULL, player->current_armor);
            player->current_armor = NULL;
            player->defense = 5;
            break;

        case 3:
            return;

        default:
            display_player_equipment(player);
    }
}
