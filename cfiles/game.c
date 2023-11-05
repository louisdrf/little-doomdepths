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
#include "../headers/includes/colors.h"
#include "../headers/player/player.h"
#include "../headers/loop.h"
#include "../headers/saves/load-save/load_game.h"
#include "../headers/saves/load-save/load_player.h"

#define DEBUG false

Game *init_game(int save_id) {

    srand(time(NULL));

    Game *game;
    game = malloc(sizeof(Game));

    if(game == NULL) {
        printf("Allocating memory for game failed.\n");
        exit(1);
    }
    game->id = save_id;
    game->display_zones_index = 0;

        // INIT THE GAME ZONES

       init_zones(game);

       /////////////////


#if DEBUG
    if(game->zoneList[0] == NULL) printf("Error while creating zone in game.");
#endif

#if DEBUG
        printf("\n\nGame initialized.\n");
#endif

    return game;
}


void launch_new_game(int save_id) {
    Game        *game;
    Player      *player;

    printf(GREEN"\nLancement d'une nouvelle partie...\n"RESET);
    game = init_game(save_id);                                          // init la partie et les niveaux
    player = init_player(game);

    launch_loop(game, player);
    free_player(player);
    free_game(game);
}

void load_saved_game(int save_id) {

    Game        *game;
    Player      *player;

    printf(GREEN"\nChargement de la partie...\n\n"RESET);
    game = load_game(save_id);                                 // charger la partie et les niveaux
    player = load_player(game);

    if(game != NULL && player != NULL) {
        launch_loop(game, player);
    }
    free_player(player);
    free_game(game);
}


void free_game(Game *game) {
    if(game != NULL) {
        free_zones(game);
        free(game->player_name);
        free(game);
    }

#if DEBUG
    if(game == NULL) printf("\nGame correctly free.\n");
#endif
}





