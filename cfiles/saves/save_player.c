//
// Created by louis on 22/10/2023.
//

#include <stdio.h>
#include "../../headers/saves/save_player.h"
#include "../../sqlite3/sqlite3.h"
#include "../../headers/includes/structs.h"

void save_player(Player *player, sqlite3** conn) {

    sqlite3_stmt *res;
    int req = 0;
    const char *tail;

    char query[300];
    sprintf(query, "insert into Player(name, lifepoints, shield, mana, attacks_left, gold, turn, current_weapon_id, current_armor_id, current_level_id, current_zone_id) values (%s, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d);",
                    player->name,
                    player->lifepoints,
                    player->shield,
                    player->mana,
                    player->attacks_left,
                    player->gold,
                    player->turn,
                    player->current_weapon->id,
                    player->current_armor->id,
                    player->current_level->id,
                    player->current_zone->id);
            printf("query : %s", query);

    req = sqlite3_prepare_v2(*conn, query, -1, &res, &tail);
    if (req != SQLITE_OK) {
        fprintf(stderr, "Failed to execute SQL query to insert player data: %s\n", sqlite3_errmsg(*conn));
        sqlite3_close(*conn);
        return;
    }

    req = sqlite3_step(res); // Exécuter la requête préparée
    if (req != SQLITE_DONE) {
        fprintf(stderr, "Failed to execute SQL query: %s\n", sqlite3_errmsg(*conn));
        sqlite3_finalize(res); // Finaliser la requête
        sqlite3_close(*conn);
        return;
    }

    sqlite3_finalize(res); // Finaliser la requête



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
   current_weapon_id INTEGER,
   current_armor_id INTEGER,
   current_level_id INTEGER,
   current_zone_id INTEGER,
   FOREIGN KEY (current_weapon_id) REFERENCES Weapon(id),
   FOREIGN KEY (current_armor_id) REFERENCES Armor(id),
   FOREIGN KEY (current_level_id) REFERENCES Level(id),
   FOREIGN KEY (current_zone_id) REFERENCES Zone(id)
);
 */