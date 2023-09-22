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

#define DEBUG true


Game *init_game() {

Game *game;

    game = malloc(sizeof(Game));
    if(game == NULL) {
        printf("Allocating memory for game failed.\n");
        exit(1);
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


