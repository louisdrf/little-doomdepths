//
// Created by louis on 24/09/2023.
//

#include "monster.h"
#include "structs.h"

/**
 * find the targeted monster through the actual player level monsters list
 * @param player
 * @param id
 * @return
 */
Monster *getTargetMonster(Player *player, int id) {

    Monster *current = player->current_level->monsters;

    while(current->id != id) {
        current = current->next;
    }

    return current;
}