//
// Created by louis on 28/10/2023.
//

#include <stdlib.h>
#include <stdio.h>
#include "../../../headers/saves/load-save/load_game.h"
#include "../../../headers/includes/structs.h"
#include "../../../headers/saves/load-save/load_zones.h"


Game *load_game(int game_id) {

    Game *game;
    game = malloc(sizeof(Game));

    if(game == NULL)
    {
        printf("Allocating memory for game to load failed.\n");
        exit(1);
    }
    game->id = game_id;
    game->display_zones_index = 0;
    game->isRunning = true;

    // INIT THE GAME ZONES

    load_zones(game);

    /////////////////


#if DEBUG
    if(game->zoneList[0] == NULL) printf("Error while loading zone in game.");
#endif

#if DEBUG
    printf("\n\nGame initialized.\n");
#endif

    return game;
}