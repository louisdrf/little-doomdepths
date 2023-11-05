//
// Created by louis on 05/11/2023.
//

#include <stdlib.h>
#include "../../headers/quests/check_quests.h"
#include "../../headers/includes/quests_defines.h"


void check_quests(Player *player) {

    Quest *current = player->questList;

    while(current != NULL) {
        switch(current->id) {

            case KILL_10_MONSTERS:      // si le joueur a tué 10 monstres
                if(player->nbKill == 10) {
                    current->finished = true;
                }
                break;

            case REACH_SECOND_LEVEL:        // si le joueur a atteint le second niveau
                if(player->current_level->id == 2) {
                    current->finished = true;
                }

            default:
                break;
        }

        current = current ->next;
    }
}
