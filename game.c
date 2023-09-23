//
// Created by louis on 22/09/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "game.h"
#include "structs.h"
#include "defines.h"
#include "player.h"
#include "init_monster.h"
#define DEBUG false


Game *init_game() {

    srand(time(NULL));

Game *game;

    game = malloc(sizeof(Game));
    if(game == NULL) {
        printf("Allocating memory for game failed.\n");
        exit(1);
    }

    Monster *first_monster = NULL;

    game->nbMonsters = rand() % NBMONSTERS_MAX + NBMONSTERS_MIN;
    for(int i = 0; i < game->nbMonsters + 1; i++) {
        first_monster = create_monster(first_monster, i);
    }


#if DEBUG
        printf("\n\nGame initialized.\n");
#endif

    return game;
}


void free_game(Game *game) {
    free(game);

#if DEBUG
    if(game == NULL) printf("\nGame correctly free.\n");
#endif
}


