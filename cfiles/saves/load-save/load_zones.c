//
// Created by louis on 28/10/2023.
//

#include <stdlib.h>
#include "../../../headers/saves/load-save/load_zones.h"
#include "../../../headers/includes/structs.h"
#include "../../../sqlite3/sqlite3.h"
#include "../../../headers/db_connexion.h"
#include "../../../headers/saves/load-save/load_levels.h"


void load_zones(Game *game) {

    sqlite3 *conn = connect_to_db();

    for(int i = 0; i < NBZONES; i++) {
        game->zoneList[i] = malloc(sizeof(Zone));
        load_levels(game, i);
    }
}