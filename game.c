//
// Created by louis on 22/09/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "game.h"
#include "structs.h"
#include "defines.h"
#include "init_level.h"

#define DEBUG false

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
        game->levelList[i] = init_level(i);; // ajoute le niveau à la partie
        if(game->levelList[i] == NULL) {
            printf("Adding level %d in game failed.\n", i);
            exit(1);
        }
        #if DEBUG
                printf("\n\nLevel %d correctly added to the game.\n", i);
        #endif
    }

    ////////////////////////////////////

#if DEBUG
        printf("\n\nGame initialized.\n");
#endif

    return game;
}


int end_game(Game *game) {
    free_game(game);
    printf("\nFin de partie.\n");
    exit(0);
}


void free_game(Game *game) {
    if(game != NULL) {
        free(game->levelList);
        free(game);
    }

#if DEBUG
    if(game == NULL) printf("\nGame correctly free.\n");
#endif
}





