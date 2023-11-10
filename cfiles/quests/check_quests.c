//
// Created by louis on 05/11/2023.
//

#include <stdio.h>
#include <conio.h>
#include "../../headers/quests/check_quests.h"
#include "../../headers/includes/quests_defines.h"
#include "../../headers/includes/colors.h"
#include "../../headers/utils.h"


void check_quests(Player *player) {

    Quest *current = player->questList;

    while(current != NULL) {
        switch(current->id) {

            case KILL_10_MONSTERS:
                if(!current->finished) {
                    if (player->nbKill == 10) finish_quest(player, current);
                }
                break;

            case REACH_SECOND_LEVEL:
                if(!current->finished) {
                    if (player->current_level->id == 2) finish_quest(player, current);
                }
                break;

            case FINISH_TWO_QUESTS:
                if(!current->finished) {
                    if(player->nbQuestDone == 2) finish_quest(player, current);
                }
                break;

            case FINISH_5_LEVELS:
                if(!current->finished) {
                    if (player->nbLevelFinished == 5) finish_quest(player, current);
                }
                break;

            default:
                break;
        }

        current = current->next;
    }
}


void finish_quest(Player *player, Quest *q) {

    q->finished = true;
    if(!q->displayedAlert) {
        clear();
        printf(GREEN"Vous avez termine la quete : %s ! Allez recuperer vos recompenses !\n\n"RESET, q->description);
        printf("Entrez n'importe quelle touche pour continuer.\n-> ");
        int pass = getch();
        q->displayedAlert = true;
    }
    player->nbQuestDone++;
}
