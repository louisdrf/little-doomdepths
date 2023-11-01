//
// Created by louis on 28/10/2023.
//

#include <stdlib.h>
#include <stdio.h>
#include "../../../headers/saves/load-save/load_game.h"
#include "../../../headers/saves/load-save/load_zones.h"
#include "../../../sqlite3/sqlite3.h"
#include "../../../headers/db_connexion.h"


Game *load_game(int game_id) {

    sqlite3 *conn = connect_to_db();
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

    load_zones(game, &conn);

    printf("\nRecup all zones done\n");

    /////////////////


#if DEBUG
    if(game->zoneList[0] == NULL) printf("Error while loading zone in game.");
#endif

#if DEBUG
    printf("\n\nGame initialized.\n");
#endif

    return game;
}