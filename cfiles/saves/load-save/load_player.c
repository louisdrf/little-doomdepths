//
// Created by louis on 29/10/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../headers/saves/load-save/load_player.h"
#include "../../../headers/includes/structs.h"
#include "../../../headers/db_connexion.h"


Player *load_player(Game *game) {

    sqlite3 *conn = connect_to_db();
    sqlite3_stmt *res;
    const char *tail;
    char query[50];

    Player *player = malloc(sizeof(Player));

    sprintf(query, "SELECT * FROM Player WHERE id=%d;", game->id);

    int error = sqlite3_prepare_v2(conn, query, -1, &res, &tail);
    if (error != SQLITE_OK) {
        fprintf(stderr, "Failed to execute SQL query to select player: %s\n", sqlite3_errmsg(conn));
        sqlite3_close(conn);
        return NULL;
    }

    if(sqlite3_step(res) == SQLITE_ROW) {

        // Récupérer les données du joueur
        player->name = malloc(strlen(sqlite3_column_text(res, 1)) + 1);
        strcpy(player->name, sqlite3_column_text(res, 1));
        player->id = game->id;
        player->lifepoints_max = 100;
        player->lifepoints = sqlite3_column_int(res, 2);
        player->shield = sqlite3_column_int(res, 3);
        player->mana_max = 100;
        player->mana = sqlite3_column_int(res, 4);
        player->attacks_left = sqlite3_column_int(res, 5);
        player->gold = sqlite3_column_int(res, 6);
        player->turn = sqlite3_column_int(res, 7);
        int current_zone_id = sqlite3_column_int(res, 8);
        player->current_zone = game->zoneList[current_zone_id];
        player->currentX = sqlite3_column_int(res, 11);
        player->currentY = sqlite3_column_int(res, 12);
        player->current_level = game->zoneList[current_zone_id]->levelList[player->currentX][player->currentY];
        player->isAlive = true;
        player->min_strength = 10;
        player->max_strength = 20;
        player->attacks_by_turn = 2;
        player->current_armor = NULL;
        player->current_weapon = NULL;
        init_player_draw(player);

        printf("Player\nlifepoints:%d\nshield:%d\nmana:%d\nattacks-left:%d\ngold:%d\ncurrent zone id:%d\ncurrent_level:%d\n",
               player->lifepoints,
               player->shield,
               player->mana,
               player->attacks_left,
               player->gold,
               current_zone_id,
               player->current_level->id);

    }

    //load_player_inventory();
    sqlite3_finalize(res);
    sqlite3_close(conn);

    return player;
}