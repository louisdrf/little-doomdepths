//
// Created by louis on 22/09/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../headers/game.h"
#include "../headers/includes/structs.h"
#include "../headers/includes/defines.h"
#include "../headers/init/init_level.h"
#include "../headers/zones/init_zones.h"
#include "../headers/init/init_store.h"
#define DEBUG true

Game *init_game() {

    srand(time(NULL));
    Game *game;


    game = malloc(sizeof(Game));
    if(game == NULL) {
        printf("Allocating memory for game failed.\n");
        exit(1);
    }

    game->id = 0;
    game->display_zones_index = 0;

        // INIT THE GAME ZONES

       init_zones(game);

       /////////////////
       // init the linked list of store for the game
Store *item = NULL;
for(int j = 1; j < MAX_STORE_ITEMS+1; j++ ){
    item = create_store(item,j);
}
    game->store = item;
#if DEBUG
    if(game->zoneList[0] == NULL) printf("Error while creating zone in game.");
#endif

#if DEBUG
        printf("\n\nGame initialized.\n");
#endif
    return game;
}


int end_game(Game *game) {
    free_game(game);
    printf("\nFin de partie.\n");
    return 0;
}


void free_game(Game *game) {
    if(game != NULL) {
        free_zones(game);
        free(game->player_name);
        free(game->store);
        free(game);
    }

#if DEBUG
    if(game == NULL) printf("\nGame correctly free.\n");
#endif
}





