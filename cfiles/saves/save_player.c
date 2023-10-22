//
// Created by louis on 22/10/2023.
//

#include <stdio.h>
#include "save_player.h"
#include "../../sqlite3/sqlite3.h"
#include "../../headers/includes/structs.h"

void save_player(Player *player, sqlite3** conn) {

    sqlite3_stmt *res;
    int error = 0;
    const char *tail;

    char query[100];
    sprintf(query, "insert into Player(id, name, lifepoints, shield, mana, attacks_left, gold, turn, current_weapon_id, current_armor_id, current_level_id, current_zone_id, inventory_id, book_id)  values (%d, %s, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d);",
            player->id, player->name, player->lifepoints, player->shield, player->mana, player->attacks_left, player->gold, player->turn,
            player->current_weapon->id, player->current_armor->id, player->current_level->id, player->current_zone->id,
            player->inventory->id, player->book->id);

    error = sqlite3_prepare_v2(*conn, query, -1, &res, &tail);
    if (error != SQLITE_OK) {
        fprintf(stderr, "Failed to execute SQL query to insert player: %s\n", sqlite3_errmsg(*conn));
        sqlite3_close(*conn);
        return;
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
   current_weapon_id INTEGER,
   current_armor_id INTEGER,
   current_level_id INTEGER,
   current_zone_id INTEGER,
   inventory_id INTEGER,
   book_id INTEGER,
   FOREIGN KEY (current_weapon_id) REFERENCES Weapon(id),
   FOREIGN KEY (current_armor_id) REFERENCES Armor(id),
   FOREIGN KEY (current_level_id) REFERENCES Level(id),
   FOREIGN KEY (current_zone_id) REFERENCES Zone(id),
   FOREIGN KEY (inventory_id) REFERENCES Inventory(id),
   FOREIGN KEY (book_id) REFERENCES Book(id)
);
 */