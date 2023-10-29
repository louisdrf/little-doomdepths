//
// Created by louis on 29/10/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../headers/saves/load-save/load_level_monsters.h"
#include "../../../sqlite3/sqlite3.h"
#include "../../../headers/db_connexion.h"
#include "../../../headers/monsters/monster_sprite.h"

void load_level_monsters(Level *level, int save_id, int zone_id) {

    sqlite3 *conn = connect_to_db();
    sqlite3_stmt *res;
    const char *tail;
    char query[100];

    for(int i = 0; i < level->nbMonsters; i++) {
        sprintf(query, "SELECT * FROM Monster WHERE level_id=%d AND zone_id=%d AND player_id=%d;", level->in_zone_id, zone_id, save_id);

        int error = sqlite3_prepare_v2(conn, query, -1, &res, &tail);
        if (error != SQLITE_OK) {
            fprintf(stderr, "Failed to execute SQL query to select monsters for level %d: %s\n",  level->id, sqlite3_errmsg(conn));
            sqlite3_close(conn);
            return;
        }

        int index = 0;
        level->monsters = NULL; // Initialiser la liste chaînée à NULL

        while(sqlite3_step(res) == SQLITE_ROW) {
            Monster *monster = malloc(sizeof(Monster)); // Allouer de la mémoire pour le nouveau monstre

            monster->id = sqlite3_column_int(res, 0);
            monster->monster_type = sqlite3_column_int(res, 2);
            monster->lifepoints = sqlite3_column_int(res, 3);
            monster->lifepoints_max = sqlite3_column_int(res, 4);
            monster->min_strength = sqlite3_column_int(res, 5);
            monster->max_strength = sqlite3_column_int(res, 6);
            monster->defense = sqlite3_column_int(res, 7);
            monster->attacks_by_turn = sqlite3_column_int(res, 8);
            monster->attacks_left = sqlite3_column_int(res, 9);
            monster->turn = sqlite3_column_int(res, 10);
            monster->isAlive = sqlite3_column_int(res, 11);
            monster->loot_gold = sqlite3_column_int(res, 12);

            char *sprite = return_monster_sprite(monster->monster_type);
            monster->draw = malloc(strlen(sprite) + 1);
            strcpy(monster->draw, sprite);

            monster->next = level->monsters;
            level->monsters = monster;
        }

        sqlite3_finalize(res); // Finaliser la requête
    }

    printf("Monstres niveau %d recup\n", level->id);

}