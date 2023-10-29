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

    zone->levelList = malloc(sizeof(Level *) * zone->height);
    for (int i = 0; i < zone->height; i++) {                              // allouer le tableau de niveaux pour la zone
        zone->levelList[i] = malloc(sizeof(Level *) * zone->width);
    }

    for(int i = 0; i < zone->height; i++) {
        for(int j = 0; j < zone->width; j++) {
            sprintf(query, "SELECT * FROM Level WHERE player_id=%d AND zone_id=%d AND height_index=%d AND width_index=%d", save_id, zone_id, i, j); // on recupere le niveau pour la zone[i][j]

            int error = sqlite3_prepare_v2(conn, query, -1, &res, &tail);
            if (error != SQLITE_OK) {
                fprintf(stderr, "Failed to execute SQL query to select levels for zone %d: %s\n", zone_id, sqlite3_errmsg(conn));
                sqlite3_close(conn);
                return;
            }

            if(sqlite3_step(res) == SQLITE_ROW) {
                // Récupérer les données du niveau
                zone->levelList[i][j]->nbMonsters = sqlite3_column_int(res, 2);   // nombre de monstres dans le niveau
                zone->levelList[i][j]->finished = sqlite3_column_int(res, 3);     // niveau terminé ou non
                zone->levelList[i][j]->id = (i + j);
            }
            else {
                zone->levelList[i][j] = NULL;
            }
        }
    }
    sqlite3_finalize(res); // Finaliser la requête


}