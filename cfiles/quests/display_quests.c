//
// Created by louis on 04/11/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "../../headers/quests/display_quests.h"
#include "../../headers/includes/colors.h"

void display_quests_menu() {

    system("cls");
    int playerEntry;

    printf(GREEN"----- Quetes -----\n\n"RESET);
    printf("Quetes en cours  (1)\n");
    printf("Quetes terminees (2)\n");
    printf("-> ");

    playerEntry = getch() - 48;
    switch(playerEntry) {
        case 1:
            //display_quests();
            break;

        case 2:
            //display_done_quests();
            break;

        default:
            display_quests_menu();
    }
}