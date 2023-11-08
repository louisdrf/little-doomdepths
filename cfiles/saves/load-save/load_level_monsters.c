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

#define DEBUG false

void load_level_monsters(Level *level, int save_id, int height_index, int width_index, int zone_id, sqlite3 **conn) {

    sqlite3_stmt *res;
    const char *tail;
    char query[200];

    for(int i = 0; i < level->nbMonsters; i++) {
        sprintf(query, "SELECT * FROM Monster WHERE level_height_index=%d AND level_width_index=%d AND zone_id=%d AND player_id=%d ORDER BY monster_id;",
                height_index,
                width_index,
                zone_id,
                save_id);

        int error = sqlite3_prepare_v2(*conn, query, -1, &res, &tail);
        if (error != SQLITE_OK) {
            fprintf(stderr, "Failed to execute SQL query to select monsters for level[%d][%d]: %s\n",  height_index, width_index, sqlite3_errmsg(*conn));
            sqlite3_close(*conn);
            return;
        }
#if DEBUG
        printf("\nMONSTRES: %s", query);
#endif

        level->monsters = NULL;

        while(sqlite3_step(res) == SQLITE_ROW) {
            Monster *monster = malloc(sizeof(Monster));

            monster->monster_type = sqlite3_column_int(res, 1);
            monster->lifepoints = sqlite3_column_int(res, 2);
            monster->lifepoints_max = sqlite3_column_int(res, 3);
            monster->min_strength = sqlite3_column_int(res, 4);
            monster->max_strength = sqlite3_column_int(res, 5);
            monster->defense = sqlite3_column_int(res, 6);
            monster->attacks_by_turn = sqlite3_column_int(res, 7);
            monster->attacks_left = sqlite3_column_int(res, 8);
            monster->turn = sqlite3_column_int(res, 9);
            monster->isAlive = sqlite3_column_int(res, 10);
            monster->loot_gold = sqlite3_column_int(res, 11);
            monster->id = sqlite3_column_int(res, 14);

            char *sprite = return_monster_sprite(monster->monster_type);
            monster->draw = malloc(strlen(sprite) + 1);
            strcpy(monster->draw, sprite);
            monster->drawIndex = 0;

            monster->next = level->monsters;
            level->monsters = monster;
        }

        sqlite3_finalize(res);
    }

#if DEBUG
    printf("Monster level recup\n");
#endif


}