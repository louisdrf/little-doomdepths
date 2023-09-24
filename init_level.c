//
// Created by louis on 24/09/2023.
//

#include <stdlib.h>
#include <stdio.h>
#include "init_level.h"
#include "init_monster.h"
#include "structs.h"
#include "defines.h"

#define DEBUG true

/**
 * create a level with its own monsters list
 * @param id
 * @return
 */
Level *init_level(int id) {

    // create a level
    Level *level = malloc(sizeof(Game));
    if(level == NULL) {
        printf("Allocating memory for level failed.\n");
        exit(1);
    }

    level->id = id;

    // init the linked list of monsters for the level
    Monster *first_monster = NULL;
    level->nbMonsters = rand() % NBMONSTERS_MAX + NBMONSTERS_MIN; // nombre de monstres pour le niveau

    for(int j = 0; j < level->nbMonsters + 1; j++) {
        first_monster = create_monster(first_monster, j);
    }

    level->monsters = first_monster; // ajoute la tete de liste de monstres au niveau

#if DEBUG
printf("Level %d correctly initialized.\n", level->id);
#endif

    return level;
}