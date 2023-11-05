//
// Created by louis on 04/11/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "../../headers/quests/display_quests.h"
#include "../../headers/includes/colors.h"
#include "../../headers/includes/structs.h"
#include "../../headers/weapon/init_weapon.h"


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

    printf("\nRetour (pressez n'importe quelle touche)\n->");
    int pass = getch();
    display_quests_menu(player);
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
        printf("\nRetour (pressez n'importe quelle touche)\n->");
        int pause = getch();
        return;
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

            case 2:
                display_quests_menu(player);

            default:
                display_done_quests(player);
        }
    }
}


void display_quest_rewards(Player* player, int quest_id) {
    Quest *current = player->questList;
    bool questExists = false;

    while (current != NULL) {
        if (current->id == quest_id) {
            questExists = true;
            break;
        }
        current = current->next;
    }

    if (!questExists) {
        system("cls");
        printf(RED"Le numero saisi ne correspond a aucune quete.\n"RESET);
        printf("\nRetour (pressez n'importe quelle touche)\n->");
        int pause = getch();
        display_done_quests(player);
    }

    if (current->claimedReward) {
        system("cls");
        printf(RED"Les recompenses pour cette quete ont deja ete recuperees.\n"RESET);
        printf("\nRetour (pressez n'importe quelle touche)\n->");
        int pause = getch();
        display_done_quests(player);
    }
    else {
        get_quest_rewards(current);
    }
}


void get_quest_rewards(Quest *quest) {
    printf(GREEN"Recompenses de la quete\n\n"RESET);

    if(quest->weaponReward != NULL) {
        display_weapon_stats(quest->weaponReward);
        printf("\n");
    }
    if(quest->armorReward != NULL) {
        printf("armure\n");
    }
    if(quest->goldReward > 0) {
        printf(YELLOW"Or : %d\n"RESET, quest->goldReward);
    }

    int pass = getch();
}


