//
// Created by louis on 22/10/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include "../../headers/saves/save_player.h"
#include "../../sqlite3/sqlite3.h"
#include "../../headers/includes/structs.h"

#define DEBUG true

void save_player(Player *player, sqlite3** conn) {

    sqlite3_stmt *res;
    int req = 0;
    const char *tail;

    if(conn != NULL) {
        char query[300];
        sprintf(query, "UPDATE Player SET name = '%s', lifepoints = %d, shield = %d, mana = %d, attacks_left = %d, gold = %d, turn = %d, current_level_id = %d, current_zone_id = %d WHERE id = %d;",
                player->name,
                player->lifepoints,
                player->shield,
                player->mana,
                player->attacks_left,
                player->gold,
                player->turn,
                player->current_level->id,
                player->current_zone->id,
                player->id);
        printf("query : %s", query);

        req = sqlite3_prepare_v2(*conn, query, -1, &res, &tail);
        if (req != SQLITE_OK) {
            fprintf(stderr, "Failed to execute SQL query to insert player data: %s\n", sqlite3_errmsg(*conn));
            sqlite3_close(*conn);
            return;
        }

        req = sqlite3_step(res); // Exécuter la requête préparée
        if (req != SQLITE_DONE) {
            printf( "Failed to execute SQL query: %s\n", sqlite3_errmsg(*conn));
            sqlite3_finalize(res);
            sqlite3_close(*conn);
            exit(1);
        }

        sqlite3_finalize(res);
        sqlite3_close(*conn);
    }

    else {
        printf("conn null");
        exit(1);
    }

}

/*
 * CREATE TABLE Player (
   id INTEGER PRIMARY KEY,
   name TEXT,
   lifepoints INTEGER,
   shield INTEGER,
   mana INTEGER,
   attacks_left INTEGER,
   gold INTEGER,
   turn BOOLEAN,
   current_level_id INTEGER,
   current_zone_id INTEGER,
   game_id INTEGER,
   FOREIGN KEY (game_id) REFERENCES Game(id)
);
 */