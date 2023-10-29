//
// Created by louis on 28/10/2023.
//

#include <stdlib.h>
#include <stdio.h>
#include "../../../headers/saves/load-save/load_levels.h"
#include "../../../sqlite3/sqlite3.h"
#include "../../../headers/db_connexion.h"

void load_levels(Zone *zone, int zone_id, int save_id) {

    sqlite3 *conn = connect_to_db();
    sqlite3_stmt *res; // Variable pour stocker le résultat de la requête
    const char *tail;
    char query[300];

    for(int i = 0; i < zone->height; i++) {
        for(int j = 0; j < zone->width; j++) {
            sprintf(query, "SELECT * FROM Level WHERE player_id=%d AND zone_id=%d AND height_index=%d AND width_index=%d", save_id, zone_id, i, j); // on recupere le niveau pour zone[i][j]

            int error = sqlite3_prepare_v2(conn, query, -1, &res, &tail);
            if (error != SQLITE_OK) {
                fprintf(stderr, "Failed to execute SQL query to select levels for zone %d: %s\n", zone_id, sqlite3_errmsg(conn));
                sqlite3_close(conn);
                return;
            }
        }
    }
    sqlite3_finalize(res); // Finaliser la requête


}