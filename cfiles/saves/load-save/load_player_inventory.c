//
// Created by louis on 01/11/2023.
//

#include <stdio.h>
#include "../../../headers/saves/load-save/load_player_inventory.h"
#include "../../../headers/includes/structs.h"
#include "../../../headers/init/init_inventory.h"
#include "../../../headers/inventory/potion.h"


void load_player_inventory(Player *player, sqlite3 **conn) {

    sqlite3_stmt *res;
    const char *tail;
    char query[50];

    player->inventory = init_inventory();

    sprintf(query, "SELECT * FROM Inventory WHERE player_id=%d;", player->id);

    int error = sqlite3_prepare_v2(*conn, query, -1, &res, &tail);
    if (error != SQLITE_OK) {
        fprintf(stderr, "Failed to execute SQL query to select inventory: %s\n", sqlite3_errmsg(*conn));
        sqlite3_close(*conn);
        return;
    }

    if(sqlite3_step(res) == SQLITE_ROW) {

        if(sqlite3_column_int(res, 2)) {
            give_player_potion(player, 2);      // potion de vie
        }
        if(sqlite3_column_int(res, 3)) {
            give_player_potion(player, 1);      // potion de mana
        }
    }
    sqlite3_finalize(res);

    load_player_inventory_weapons(player, &conn);
    load_player_inventory_armors(player, &conn);
}


void load_player_inventory_weapons(Player *player, sqlite3 **conn) {

}

void load_player_inventory_armors(Player *player, sqlite3 **conn) {

}