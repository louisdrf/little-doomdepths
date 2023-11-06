//
// Created by louis on 05/11/2023.
//

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "../../headers/quests/check_quests.h"
#include "../../headers/includes/quests_defines.h"
#include "../../headers/includes/colors.h"


void check_quests(Player *player) {

    int pass;
    Quest *current = player->questList;

    while(current != NULL) {
        switch(current->id) {

            case KILL_10_MONSTERS:      // si le joueur a tué 10 monstres
                if(player->nbKill == 1) {
                    current->finished = true;
                    if(!current->displayedAlert) {
                        system("cls");
                        printf(GREEN"Vous avez termine une quete : %s ! Allez recuperer vos recompenses !\n\n"RESET, current->description);
                        printf("Entrez n'importe quelle touche pour continuer.\n-> ");
                        pass = getch();
                        current->displayedAlert = true;
                        player->nbQuestDone++;
                    }
                }
                break;

            case REACH_SECOND_LEVEL:        // si le joueur a atteint le second niveau
                if(player->current_level->id == 2) {
                    current->finished = true;
                    if(!current->displayedAlert) {
                        system("cls");
                        printf(GREEN"Vous avez termine la quete : %s ! Allez recuperer vos recompenses !\n\n"RESET, current->description);
                        printf("Entrez n'importe quelle touche pour continuer.\n-> ");
                        pass = getch();
                        current->displayedAlert = true;
                        player->nbQuestDone++;
                    }
                }
                break;

            case FINISH_TWO_QUESTS:
                if(player->nbQuestDone == 1) {
                    current->finished = true;
                    if(!current->displayedAlert) {
                        system("cls");
                        printf(GREEN"Vous avez termine la quete : %s ! Allez recuperer vos recompenses !\n\n"RESET, current->description);
                        printf("Entrez n'importe quelle touche pour continuer.\n-> ");
                        pass = getch();
                        current->displayedAlert = true;
                        player->nbQuestDone++;
                    }
                }
                break;

            default:
                break;
        }

        current = current->next;
    }
}
