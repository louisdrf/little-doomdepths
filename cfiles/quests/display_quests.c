//
// Created by louis on 04/11/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "../../headers/quests/display_quests.h"
#include "../../headers/includes/colors.h"
#include "../../headers/includes/structs.h"


void display_quests_menu(Player *player) {

    system("cls");
    int playerEntry;

    printf(GREEN"----- Quetes -----\n\n"RESET);
    printf(BLUE "Quetes en cours  (1)\n"RESET);
    printf(GREEN"Quetes terminees (2)\n\n\n"RESET);
    printf(     "Retour           (3)\n");
    printf("-> ");

    playerEntry = getch() - 48;
    switch(playerEntry) {
        case 1:
            display_quests(player);
            break;

        case 2:
            display_done_quests(player);
            break;

        case 3:
            return;

        default:
            display_quests_menu(player);
    }
}

void display_quests(Player *player) {

}

void display_done_quests(Player *player) {

}