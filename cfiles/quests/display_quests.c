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
    printf(BLUE "Liste des quetes  (1)\n"RESET);
    printf(GREEN"Quetes terminees  (2)\n\n\n"RESET);
    printf(     "Retour            (3)\n");
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
    system("cls");
    int nbQuests = 0;

    Quest *current = player->questList;
    while(current != NULL) {

            printf("%s | terminee : ", current->description);
            if(current->finished == true) printf(GREEN"oui\n"RESET);
            else  printf(RED"non\n"RESET);

        nbQuests++;
        current = current->next;
    }

    if(nbQuests == 0) {
        printf("Aucune quete en cours.\n");
    }

    int pass = getch();
}

void display_done_quests(Player *player) {

    system("cls");
    int playerEntry;
    int nbQuests = 0;

    Quest *current = player->questList;

    while(current != NULL) {

        if(current->finished == true) {
            printf("%d : %s | Recompenses recuperees : ",current->id, current->description);
            if(!current->claimedReward) printf(RED"non\n"RESET);
            else printf(GREEN"oui\n"RESET);
            nbQuests++;
        }
        current = current->next;
    }

    if(nbQuests == 0) {
        printf(RED"Aucune quete terminee pour l'instant.\n"RESET);
    }
    else {
        printf(BLUE"\nRecuperer les recompenses (1)"RESET);
        printf(RED"        Retour (2)\n"RESET);
        printf("-> ");
        playerEntry = getch() - 48;
        switch(playerEntry) {

            case 1:
                printf("Numero de la quete : ");
                int quest_id = getch() - 48;
                display_quest_rewards(player, quest_id);
                break;

            default:
                display_done_quests(player);
        }
    }
}


void display_quest_rewards(Player* player, int quest_id) {

}