//
// Created by louis on 24/09/2023.
//

#include <stdlib.h>
#include <stdio.h>
#include "../../headers/init/init_level.h"
#include "../../headers/init/init_monster.h"
#include "../../headers/inventory/potion.h"



#define DEBUG false

/**
 * create a level with its own monsters list
 * @param id
 * @return
 */
Level *init_level(int id) {

    // create a level
    Level *level = malloc(sizeof(Level));
    if(level == NULL) {
        printf("Allocating memory for level failed.\n");
        exit(1);
    }

    level->id = id;

    // init the linked list of monsters for the level
    Monster *first_monster = NULL;
    level->nbMonsters = rand() % NBMONSTERS_MAX + NBMONSTERS_MIN; // nombre de monstres pour le niveau

    for(int j = 1; j < level->nbMonsters + 1; j++) {
        first_monster = create_monster(first_monster, j);
        #if DEBUG
                printf("Monster %d in level %d correctly added.\n", j, level->id);
        #endif
    }

    level->monsters = first_monster; // ajoute la tete de liste de monstres au niveau

#if DEBUG
printf("Level %d correctly initialized.\n", level->id);
#endif

    return level;
}


void next_level(Game *game, Player *player) {

    int next_level;
    int i = 0;

    while(game->zoneList[i]->levelList[0][player->current_level->id] == NULL) {
        player->current_level->id++;
    }

    next_level = player->current_level->id;

    player->current_level = game->zoneList[player->current_zone->id]->levelList[0][next_level];
    printf("\nVous passez au niveau %d !\n", next_level);

    player->turn = true;
    player->attacks_left = player->attacks_by_turn;
    player->lifepoints = player->lifepoints_max;
}


