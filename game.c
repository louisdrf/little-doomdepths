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
#include "init_level.h"

#define DEBUG true

Game *init_game() {

    srand(time(NULL));

Game *game;

    game = malloc(sizeof(Game));
    if(game == NULL) {
        printf("Allocating memory for game failed.\n");
        exit(1);
    }

// INIT THE GAME LEVELS

    for(int i = 0; i < NBLEVELS; i++)
    {
        Level *level = init_level(i);
        game->levelList[i] = level; // ajoute le niveau à la partie
    }

    ////////////////////////////////////

#if DEBUG
        printf("\n\nGame initialized.\n");
#endif

    return game;
}


void free_game(Game *game) {
    free(game->levelList);
    free(game);

#if DEBUG
    if(game == NULL) printf("\nGame correctly free.\n");
#endif
}





