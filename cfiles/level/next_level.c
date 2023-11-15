//
// Created by louis on 15/11/2023.
//

#include "../../headers/level/next_level.h"


void next_level_updates(Player *player) {

    player->current_level->finished = true;
    player->nbLevelFinished++;
    player->attacks_left = player->attacks_by_turn;
    player->shield = 0;
}